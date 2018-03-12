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

ll n,m;
ll MA=1005*300;
Vec v(300), w(300);
ll mv,mw;
DVec dp(3,Vec(1000001));

ll zen(ll p,ll o){
  if(p == n)return 0;
  ll v1 = 0, v2 = 0;
  if(o + w[p] <= m)v1 = zen(p + 1, o + w[p]) + v[p];
  v2 = zen(p + 1, o);
  return mmax(v1, v2);
}

ll dp1(){
  rep(i,n)rep(j,MA){
    if(j + w[i] <= m)maxch(dp[1&(i+1)][j+w[i]],dp[1&i][j]+v[i]);
    maxch(dp[1&(i+1)][j], dp[1&i][j]);
  }

  ll ans = 0;
  rep(i,MA){
    maxch(ans,dp[0][i]);
    maxch(ans,dp[1][i]);
  }
  return ans;
}

ll dp2(){
  rep(i,2)rep(j,MA)dp[i][j]=INF;
  dp[0][0]=0;
  rep(i,n)rep(j,MA)if(dp[1&i][j] < INF){
    minch(dp[1&(i+1)][j+v[i]],dp[1&i][j]+w[i]);
    minch(dp[1&(i+1)][j],dp[1&i][j]);
  }
  ll ans=0;

  rep(i,2)rep(j,MA)if(dp[i][j] <= m)maxch(ans,j);
  return ans;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n >> m;
  rep(i,n){
    cin >> v[i] >> w[i];
    maxch(mv,v[i]);
    maxch(mw,w[i]);
  }

  if(n <= 30){
    ll c = 0, ret = 0;
    rep(i,n)c += w[i],ret += v[i];
    if(c <= m)cout << ret << endl;
    else cout << zen(0,0) << endl;
  }
  else if(mw <= 1000){
    cout << dp1() << endl;
  }
  else {
    cout << dp2() << endl;
  }

  return 0;
}
