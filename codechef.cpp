#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 2008
int visit[N];
vector<int>v[N];
vector<int>conn(N);
vector<int>parent(N);
map<int, int>m;
int kk;
void dfs(int node)
{
    kk++;
    int com = 0;
    stack<int>st;
    st.push(node);
    while(st.size()){
        int ff = st.top();
        st.pop();
        if(visit[ff]){continue;}
        visit[ff] = 1;
        com++;
        conn[ff] = kk;
        parent[ff] = node;
        for(int child: v[ff]){
            if(!visit[child])st.push(child);
        }
    }
    m[com]++;
    parent[node] = -com;
}

int main()
{
    int n,e;
    cin>>n>>e;

    int a,b;
    while(e--)
    {
        cin>>a>>b;
        if(a == b)continue;
        v[a].pb(b);
        v[b].pb(a);
    }

    for(int i=1;i<=n;i++){
        if(visit[i])continue;
        dfs(i);
    }
    /*
    for(auto it = m.begin(); it!=m.end();it++)
        cout<<it->first<<" "<<it->second<<endl;

    for(int i =1;i<=n;i++)cout<<conn[i]<<" ";cout<<endl;
    for(int i =1;i<=n;i++)cout<<parent[i]<<" ";cout<<endl;*/

    int dis;cin>>dis;

    while(dis--){
        cin>>a>>b;
        if(conn[a] != conn[b])continue;
        if(parent[a] < 0)m[-parent[a]]--;
        else{
            m[-parent[parent[a]]]--;
        }
     }

     bool flag = true;

     for(auto it = m.rbegin(); it!=m.rend();it++){
        if(it->second > 0){cout<<it->first<<endl;flag = false;break;}
     }

     if(flag)cout<<0<<endl;

}
