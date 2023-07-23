#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
 
const ll mod  = 998244353;
const ld eps  = 1e-9 ;
const ll maxn = 105;
const ll inf  = 5e18 ;
const ll minf = -inf ;
 
#define mp make_pair
#define pb push_back
#define endl "\n"
 
ll fac[maxn],invfact[maxn];

ll binPow(ll a,ll b)
{
    if (b == 0)return 1;
    if (b == 1)return a;
    ll ret = binPow(a,b/2);
    if (b%2 == 0)return (ret * ret)%mod;
    return ((ret * ret)%mod * a)%mod;
}

ll inv(ll a)
{
    return (binPow(a,mod - 2)%mod + mod)%mod;
}

  
void comp()
{
    fac[0] = 1, invfact[0] = 1; 
    
    for (ll i = 1; i < maxn; i++){ 
        fac[i] = (fac[i - 1] * i) % mod;
        invfact[i] = inv(fac[i]);
    } 
}



ll NCRR(ll a,ll b)
{
    if (b < 0 or a < 0)return 0;
    return (((fac[a] * inv(fac[b]))%mod * inv(fac[a - b]))%mod + mod)%mod;
}
 