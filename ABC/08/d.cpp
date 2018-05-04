#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef vector<DVec> TVec;
typedef vector<TVec> FVec;
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
#define fvec(n1,n2,n3,n4,i)  FVec(n1,tvec(n2,n3,n4,i))

ll n;
Vec a,b;
FVec dp;
bool used[35][35][35][35];

ll dfs(ll x, ll xx, ll y, ll yy) {
  if (used[x][xx][y][yy])return dp[x][xx][y][yy];
  used[x][xx][y][yy] = true;
  ll ret = 0;
  rep(i,n) {
    if (!(a[x] < a[i] && a[i] < a[xx] && b[y] < b[i] && b[i] < b[yy]))continue;
    ll pos = 0;
    pos += dfs(x, i, y, i);
    pos += dfs(x, i, i, yy);
    pos += dfs(i, xx, y, i);
    pos += dfs(i, xx, i, yy);
    pos += a[xx] - a[x];
    pos += b[yy] - b[y];
    pos -= 3;
    ret = mmax(ret, pos);
  }
  return dp[x][xx][y][yy] = ret;
}

int main() {
  cin.sync_with_stdio(false);
  ll w, h;
  cin >> w >> h >> n;
  a.resize(n+2);
  b.resize(n+2);
  dp = fvec(n+2,n+2,n+2,n+2,0);
  repl(i,1,n)cin >> a[i] >> b[i];
  n += 2;
  a[n - 1] = w + 1;
  b[n - 1] = h + 1;
  a[0] = 0, b[0] = 0;
  cout << dfs(0, n - 1, 0, n - 1) << endl;
  return 0;
}
