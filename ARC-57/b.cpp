#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef vector<DVec> TVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi                first
#define se                second
#define pb                push_back
#define INF               LLONG_MAX/3
#define MOD               1000000007
#define bcnt              __builtin_popcount
#define all(x)            (x).begin(),(x).end()
#define srt(x)            sort(all(x))
#define rvs(x)            reverse(all(x))
#define uni(x)            x.erase(unique(all(x)),x.end())
#define ub(x,y)           (upper_bound(all(x),y)-x.begin())
#define lb(x,y)           (lower_bound(all(x),y)-x.begin())
#define rep(i,n)          repl(i,0,n-1)
#define mkp(x,y)          make_pair(x,y)
#define mmax(x,y)         (x>y?x:y)
#define mmin(x,y)         (x<y?x:y)
#define maxch(x,y)        x=mmax(x,y)
#define minch(x,y)        x=mmin(x,y)
#define exist(x,y)        (find(all(x),y)!=x.end())
#define each(itr,v)       for(auto itr:v)
#define repl(i,a,b)       for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)     DVec(n1,Vec(n2,i))
#define tvec(n1,n2,n3,i)  TVec(n1,dvec(n2,n3,i))

int main(){
  cin.sync_with_stdio(false);
  ll n, lim;
  cin >> n >> lim;
  Vec a(n);
  rep(i,n)cin >> a[i];
  if (lim == accumulate(all(a),0)){
    cout << 1 << endl;
    return 0;
  }
  Vec imos(n + 1,0);
  rep (i,n)imos[i + 1] = imos[i] + a[i];
  DVec dp = dvec(n+1,n+1,0); //dp[i][j] := i日目終了時に、j回勝率が上がっている時の勝利回数の最小値
  repl(i,0,n)repl(j,0,n)dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i,n)rep(j,n){
    if (dp[i][j] == INF)continue;
    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    if (i){
      ll x = dp[i][j] * imos[i + 1] / imos[i] - dp[i][j] + 1;
      dp[i + 1][j + 1] = mmin(dp[i + 1][j + 1], dp[i][j] + x);
    }
    else{
      dp[i + 1][j + 1] = 1;
    }
  }

  for (ll i = n; 0 <= i; i--){
    if (dp[n][i] <= lim){
      cout << i << endl;
      break;
    }
  }
  return 0;
}
