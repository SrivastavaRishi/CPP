#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define p 1000000007
int visit[1000008];
int ans[1000008];
int num;
vector<pair<int, int>>pp;

void print(int n)
{
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

void dfs(int v, vector<int>adj[])
{
    stack<int>st;
    st.push(v);
    num++;
    ans[v] = num;
    while(st.size()){
        int f = st.top();
        st.pop();
        visit[f] = 1;
        for(auto x:adj[f]){
            if(!visit[x]){
                st.push(x);
                ans[x] = ans[f];
            }
        }
    }
}



void bfs(int v, vector<int>adj[])
{
    queue<int>q;
    q.push(v);
    visit[v] = 1;
    ans[v] = 0;
    while(q.size()){
        int ff = q.front();
        q.pop();
        for(int x: adj[ff]){
            if(!visit[x]){
                visit[x] = 1;
                ans[x] = ans[ff] + 1;
                q.push(x);
            }
        }
    }
}


bool check()
{
    for(auto it = pp.begin(); it!=pp.end(); it++){
        int a = it->first;
        int b = it->second;
        if(ans[a] == ans[b])return false;
    }
    return true;
}


signed main()
{
    int t;cin>>t;
    while(t--){
        num = 0;
        pp.clear();
        int n,e;
        cin>>n>>e;
        vector<int>adj[n+1];

        for(int i=0;i<e;i++){
            int a,b;
            string eq;
            cin>>a>>eq>>b;
            //cout<<"the equation is "<<eq<<endl;
            if(eq == "!=")pp.pb({a, b});
            else{
            adj[a].pb(b);
            adj[b].pb(a);}
        }

        for(int i=1;i<=n;i++){
            visit[i] = 0;
            ans[i] = 0;
        }

        for(int i=1;i<=n;i++){
            if(visit[i])continue;
            dfs(i, adj);
        }
        //print(n);
       // for(auto it = pp.begin(); it!=pp.end(); it++)
           // cout<<it->first<<" "<<it->second<<endl;

        if(check())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }
}
