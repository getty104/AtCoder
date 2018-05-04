#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef vector<DVec> TVec;
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
int main() {
  cin.sync_with_stdio(false);
  ll W;
  ll N,K;
  cin >> W >> N >> K;
  Vec A(N+1), B(N+1);
  repl(i,1,N)cin >> A[i] >> B[i];

  TVec dp(N+1, dvec(W+1, K+1, 0));
  repl(i,1,N)repl(j,1,W)repl(k,1,K){
    dp[i][j][k] = dp[i - 1][j][k];
    if(j >= A[i])dp[i][j][k] = mmax(dp[i - 1][j][k], dp[i - 1][j - A[i]][k - 1]+B[i]);
  }

  ll ans = 0;
  rep(j,W+1)rep(k,K+1)maxch(ans, dp[N][j][k]);
  cout << ans << endl;
  return 0;
}
