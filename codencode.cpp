#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define m 1000000007
signed main()
{
    //int t;cin>>t;while(t--){
    int n;cin>>n;
    int num = n;
    int ans = n;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            ans/=i;
            ans*=(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1){
        ans /= n;
        ans *= (n-1);
    }



    if(num % 2 == 0){
        num/=2;
        ans = ans%m;
        num = num%m;
        num = ((num%m) * (ans%m))%m;
    }

    else{
        ans /= 2;
        ans = ans%m;
        num = num %m;
        num = ((num%m) * (ans%m))%m;
    }

    cout<<num;

    }

