#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 1000005
int inv[N],n;
inline int add(int x,int y){return ((long long)x+y)%mod;};
inline int mul(int x,int y){return (long long)x*y%mod;}
inline int quickpow(int x,int y){
    long long ans = 1;
    while(y){
        if(y&1) ans = ans*x%mod;
        x = (long long)x*x%mod;
        y/=2;
    }
    return (int)ans;
}  
int main(){
    cin>>n;
    // 线性求逆元
    inv[1] = 1;
    for(int i=2;i<=n;i++) inv[i] = mul(mod-mod/i,inv[mod%i]);
    // 小费马定理
    for(int i=1;i<=n;i++) inv[i] = quickpow(i,mod-2);
    return 0;
}