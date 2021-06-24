#include<bits/stdc++.h>
using namespace std;
int mat[22][22];
int n;
pair<int,int>src,dest;
int visit[22][22];
//3 blank cell
//0 blank wall

void bfs()
{
    queue<pair<int, int> > q;
    pair<int, int > temp;
    q.push(src);
    visit[src.first][src.second] = 1;
    int t,b,l,rt,i,j;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        i = temp.first;
        j = temp.second;
        if(i+1< n && visit[i+1][j]==0 && mat[i+1][j]!=0)
            {visit[i+1][j] = 1;q.push({i+1,j});}
        if(i-1>=0 && visit[i-1][j]==0 && mat[i-1][j]!=0)
            {visit[i-1][j] = 1;q.push({i-1,j});}
        if(j+1<n && visit[i][j+1]==0 && mat[i][j+1]!=0)
            {visit[i][j+1] = 1;q.push({i,j+1});}
        if(j-1>=0 && visit[i][j-1]==0 && mat[i][j-1]!=0)
            {visit[i][j-1] = 1;q.push({i,j-1});}
    }
}

void print()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<visit[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int t;cin>>t;
    while(t--){
        cin>>n;
        memset(visit, 0, sizeof(visit));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    cin>>mat[i][j];
                    if(mat[i][j] == 1)src = {i,j};
                    else if(mat[i][j] == 2)dest = {i,j};
            }
        }
        bfs();
        //cout<<"**********"<<endl;
        //print();
        if(visit[dest.first][dest.second] == 1)cout<<1<<endl;
        else cout<<0<<endl;
    }
}
