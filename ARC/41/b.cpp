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


ll N, M;
vector<string> S(500);
vector<string> ans(500);

int main() {
  cin.sync_with_stdio(false);
  cin >> N >> M;
  rep(i,N) cin >> S[i];
  ans[0] = "";
  rep(i,M) ans[0] += '0';
  repl(i,1,N-2) {
    ans[i] = "0";
    repl(j,1,M-2) {
      ll a, b, c, d;
      a = S[i-1][j] - '0';
      b = S[i+1][j] - '0';
      c = S[i][j-1] - '0';
      d = S[i][j+1] - '0';
      ll x = min({a, b, c, d});
      S[i-1][j] = a - x + '0';
      S[i+1][j] = b - x + '0';
      S[i][j-1] = c - x + '0';
      S[i][j+1] = d - x + '0';
      ans[i] += to_string(x);
    }
    ans[i] += "0";
  }
  rep(i,M) ans[N-1] += '0';
  rep(i,N) cout << ans[i] << endl;
  return 0;
}
