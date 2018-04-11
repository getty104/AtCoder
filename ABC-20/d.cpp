#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi             first
#define se             second
#define pb             push_back
#define INF            LLONG_MAX/3
#define MOD            1000000007
#define bcnt           __builtin_popcount
#define all(x)         (x).begin(),(x).end()
#define uni(x)         x.erase(unique(all(x)),x.end())
#define ub(x,y)        (upper_bound(all(x),y)-x.begin())
#define lb(x,y)        (lower_bound(all(x),y)-x.begin())
#define ssort(x)       sort(all(x))
#define rep(i,n)       repl(i,0,n-1)
#define mkp(x,y)       make_pair(x,y)
#define mmax(x,y)      (x>y?x:y)
#define mmin(x,y)      (x<y?x:y)
#define maxch(x,y)     x=mmax(x,y)
#define minch(x,y)     x=mmin(x,y)
#define exist(x,y)     (find(all(x),y)!=x.end())
#define each(itr,v)    for(auto itr:v)
#define repl(i,a,b)    for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)  DVec(n1,Vec(n2,i))


int main(){
  cin.sync_with_stdio(false);
  Vec G;
  ll n,k;
  cin >> n >> k;
  for(ll i=1; i*i <= k; i++){
    if(k % i == 0){
      G.pb(i);
      if(i*i != k)G.pb(k/i);
    }
  }

  ll ans = 0;
  rep(i,G.size()){
    ll s = k/G[i];
    ll N = n/G[i];
    Vec P;
    ll sum = 0;

    for(ll j=2; j*j <= s; j++){
      if(s%j == 0)P.pb(j);
      while(s%j == 0)s /= j;
    }

    if(s > 1)P.pb(s);
    ll M = P.size();
    for(ll j=0; j< 1<<M; j++){
      bool sign= bcnt(j) % 2;
      ll t=1;
      rep(l,M)if(j>>l&1)t *= P[l];
      ll u = N/t;
      ll v = u*(u+1) / 2 % MOD * t % MOD;
      sum = (sum + (sign ? -v : v) + MOD) % MOD;
    }
    ans = (ans + sum * k % MOD) % MOD;
  }
  cout << ans << endl;
}
