//ONBVD NN
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define MOD 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl;
int gcd(int a, int b);
void print(int arr[], int n);
void printv(vector<int>arr);

const int N = 200005;
int h[N], arr[N];
unordered_map<int, vector<int> >mp;

struct type{
    vector<int>ht;
    int ans;
    bool flag = true;
};

type tree[4 * N];
int res = 0;
bool flag;

void buildtree(int ind, int st, int en)
{
    //cout<<ind<<" "<<st<<" "<<en<<endl;
    if(st == en){
        tree[ind].ans = arr[st];
        tree[ind].ht.push_back(st);
        return;
        //tree[ind].flag = true;
    }
    int mid = (st + en)/2;
    buildtree(ind*2, st, mid);
    buildtree(ind*2 + 1, mid+1, en);

    //main part
    //cout<<"yea"<<endl;

    if(tree[ind*2].flag == false || tree[ind*2+1].flag == false)
    {
        tree[ind].flag = false;
        return ;
    }

    if(h[tree[ind*2].ht[0]] < h[tree[ind*2 + 1].ht[0]]){
        tree[ind].flag = false;
        return ;
    }

    if(h[tree[ind*2].ht[0]] == h[tree[ind*2 + 1].ht[0]]){
        tree[ind].ht = tree[ind*2 + 1].ht;
        tree[ind].ans = tree[ind*2 + 1].ans;
        return ;
    }


    int aa = tree[ind*2].ht.size();
    int bb = tree[ind*2 + 1].ht.size();

    //cout<<"YES"<<endl;

    if(h[tree[ind*2 + 1].ht[0]] < h[tree[ind*2].ht[aa-1]])
    {
        //cout<<"main "<<ind<<" "<<st<<" "<<en<<endl;
        tree[ind].ht = tree[ind*2].ht;
        tree[ind].ht.insert(tree[ind].ht.end(),tree[ind*2+1].ht.begin(),tree[ind*2+1].ht.end());
        tree[ind].ans = tree[ind*2].ans + tree[ind*2 + 1].ans;
        //cout<<tree[ind].ans<<endl;
        return ;
    }

    //cout<<"fg"<<endl;


    vector<int>a = tree[ind*2].ht;
    vector<int>b = tree[ind*2 + 1].ht;
    int tem = tree[ind*2].ans;

    //printv(a);printv(b);
    auto it = a.crbegin();

    while(h[*it] <= h[b[0]]){
        //cout<<*it<<" ";
        tem -= arr[*it];
        it++;
        a.pop_back();
    }

    a.insert(a.end(), b.begin(), b.end());
    tree[ind].ht = a;
    tree[ind].ans = tem + tree[ind*2 + 1].ans;
    return;

}

int query(int si , int ss , int se , int qs , int qe)
{
    //vector<int>v;
	if(ss > qe || se < qs) return 0;
	if(ss >= qs && se <= qe) return si;//return tree[si];
	int mid = (ss + se) / 2;
	return (query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe));
}

signed main()
{

    int n;cin>>n;
    int q;cin>>q;
    for(int i=1;i<=n;i++){cin>>h[i];mp[h[i]].pb(i);}
    for(int i=1;i<=n;i++)cin>>arr[i];
    //deb(n);
    buildtree(1, 1, n);
    //deb(n);
    for(int i=1;i<4*n;i++)
    {
    if(tree[i].ht.size()){
        cout<<i<<" ";
        printv(tree[i].ht);
        cout<<tree[i].ans<<endl;}
    }

    while(q--)
    {
        int t, a, b;
        cin>>t>>a>>b;
        if(t == 1)arr[a] = b;
        else
        {
            flag = false;
            if(h[b] >= h[a]){cout<<-1<<endl;continue;}
            auto it = upper_bound(mp[h[a]].begin(), mp[h[a]].end(), a);
            if(it != mp[h[a]].end()){it++;
            if(*it <= b){cout<<-1<<endl;continue;}}
            cout<<query(1, 1, n, a, b)<<endl;
        }
        res = 0;
        cout<<0<<endl;
        //cout<<query(1, 1, n, a, b)<<endl;
    }

}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void print(int arr[], int n)
{
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void printv(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}
