
// Problem : C. Chocolate Bunny
// Contest : Codeforces - Codeforces Round #669 (Div. 2)
// URL : https://codeforces.com/contest/1407/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//ONBVD NN
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mod 1000000007
#define endl "\n"
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf LLONG_MAX
int gcd(int a, int b);
void print(int arr[], int n);
void printv(vector<int>arr);

int val[1005];

signed main()
{
    int n;cin>>n;

    stack<int>ans;

    for(int i=1;i<=n;i++)ans.push(i);

    while(ans.size() > 1)
        {
            int i = ans.top();ans.pop();
            int j = ans.top();ans.pop();
            cout<<'?'<<" "<<i<<" "<<j<<endl;
            int k;cin>>k;// = arr[i] % arr[j];
            cout<<'?'<<" "<<j<<" "<<i<<endl;
            int kk;cin>>kk;// = arr[j] % arr[i];
            if(k > kk){val[i] = k;ans.push(j);}
            else {val[j] = kk;ans.push(i);}
            //print(val, n+1);
        }

    int sum = (n*(n+1))/2;
    int ind;
    for(int i=1;i<=n;i++){
        if(val[i])sum-=val[i];
        else ind = i;
    }

    val[ind] = sum;

    cout<<"! ";
    print(val, n+1);

    int verdict;
    cin>>verdict;



}




int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void print(int arr[], int n)
{
    for(int i=1;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void printv(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}
