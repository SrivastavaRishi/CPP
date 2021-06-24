#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<pair<int, int > >v[100];
#define inf 1e9

int main()
{
    int n, e;
    cin>>n>>e;
    while(e--){
        int a,b,w;
        cin>>a>>b>>w;
        v[a].pb({b,w});
        v[b].pb({a,w});
    }

    priority_queue<int, vector<pair<int, int> >, greater<pair<int, int> > >pq;

    vector<int> dist(n+1, inf);
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty())
    {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();

        for(pair<int, int>edge : v[curr])
        {
            if(curr_d + edge.second < dist[edge.first])
            {
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }

    }

    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";


}
