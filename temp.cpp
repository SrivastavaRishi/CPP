#include<bits/stdc++.h>
using namespace std;
#define p pair<int, int>
#define pb push_back
#define int long long

int arr[400008];
int pre[400008];
int sum[400008];
int n,k;

void printf(int arr[])
{
    for(int i=0;i<2*n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

signed main()
{
    cin>>n>>k;
    cin>>arr[0];
    pre[0] = arr[0];
    sum[0] = (arr[0]*(arr[0]+1))/2;

    for(int i=1;i<2*n;i++){
        if(i<n)cin>>arr[i];
        else arr[i] = arr[i-n];
        pre[i] = pre[i-1] + arr[i];
        sum[i] = sum[i-1] + (arr[i]*(arr[i]+1))/2;
    }

    printf(pre);
    printf(sum);

    int ans = 0;

    for(int i=0;i<2*n;i++){
        int t = 0;
        for(int j=i;j>=0;j--){
            t += arr[j];
            if(t == k)
        }
    }

}
