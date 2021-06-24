#include <bits/stdc++.h>

using namespace std;

int l, r, h;

int solve(int n,int arr[], int hr)
{
   // cout<<n<<" "<<hr<<endl;
    if(n == 0 && hr>=l && hr<=r)return 1;
    if(!n)return 0;

    if(hr >= l && hr <= r)
    return 1 + max(solve(n-1, arr, (hr + arr[n-1])%h),
               solve(n-1, arr, (hr + arr[n-1] - 1 + h)%h));

    return max(solve(n-1, arr, (hr + arr[n-1])%h),
               solve(n-1, arr, (hr + arr[n-1] - 1 + h)%h));
}

int main() {

   int n;
   cin>>n>>h>>l>>r;

   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   reverse(arr, arr+n);
   int ans = 0;
   cout<<solve(n, arr, 0);

}
