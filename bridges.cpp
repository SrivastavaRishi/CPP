#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>v[100008];
int visit[100008], in[100008], low[100008], parent[100008];
int timer;
vector<pair<int, int> > ans;
bool hasb = false;
void dfs(int s, int par)
{
    visit[s] = 1;
    in[s] = low[s] = timer;
    timer++;
    for(int child: v[s]){
        if(child == par)continue;
        if(visit[child]){
            //child h ye
            // back edge
            low[s] = min(low[s], in[child]);
            if(in[s] > in[child]){
                ans.pb({s, child});
            }
        }
        else {
                //forward edge
                dfs(child, s);
                if(low[child] > in[s]){
                    //cout<<s<<"-"<<child<<" is a bridge"<<endl;
                    hasb = true;return;

                }
                ans.pb({s, child});
                low[s] = min(low[s], low[child]);

        }

    }
}

/*void dfs(int s)
{
    stack<int>st;
    st.push(s);
    while(st.size()){
        int f = st.top();
        visit[f] = 1;
        in[s] = low[s] = timer;
        timer++;
        st.pop();
        for(int child: v[f]){
            if(parent[child] == f)continue;
            if(visit[child]){
                //back edge ie either a grandparent or other
                low[s] = min(low[s], in[child]);
            }
            else{
                st.push(child);
                parent[child] = f;

            }
        }
    }
}

*/

int main()
{
    int n,e;cin>>n>>e;
    int root;
    while(e--){
        int a, b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        root = a;
    }
    //parent[1] = -1;
    dfs(1,-1);
    if(hasb)cout<<0<<endl;
    else{
    for(auto x: ans)
        cout<<x.first<<" "<<x.second<<endl;}
        return 0;
}
