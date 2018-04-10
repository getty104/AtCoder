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
#define MAX_P 1000000
//// 階乗(mod p)
ll fact[MAX_P];
void mod_fact(ll n,ll p){
  fact[0]=1;
  for(ll i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%p;
}

//// 冪乗(mod p)
//// xの逆元 mod_pow(x,p-2,p)
ll mod_pow(ll x,ll n,ll p){
  ll res=1;
  while(n>0){
    if(n&1)res=res*x%p;
    x=x*x%p;
    n>>=1;
  }
  return res;
}

//// コンビネーション(mod p)
ll mod_comb(ll n,ll k,ll p){
  if(n<0||k<0||n<k)return 0;
  return ((fact[n]*mod_pow(fact[k],p-2,p))%p)*mod_pow(fact[n-k],p-2,p)%p;
}

int main(){
  cin.sync_with_stdio(false);
  mod_fact(MAX_P,MOD);
  ll N,K;
  cin >> N >> K;
  cout << mod_comb(N-1+K,N-1,MOD) << endl;

  return 0;
}
