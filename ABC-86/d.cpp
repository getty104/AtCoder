#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;

#define fi          first
#define se          second
#define pb          push_back
#define INF         INT_MAX
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define dbg(x)      cout<<#x"="<<x<<endl
#define uni(x)      x.erase(unique(all(x)),x.end())
#define ub(x,y)     upper_bound(all(x),y)-x.begin()
#define lb(x,y)     lower_bound(all(x),y)-x.begin()
#define rep(i,n)    repl(i,0,n-1)
#define usort(x)    sort(all(x))
#define dsort(x)    sort(all(x),greater<ll>())
#define mkp(x,y)    make_pair(x,y)
#define mmax(x,y)   (x>y?x:y)
#define mmin(x,y)   (x<y?x:y)
#define maxch(x,y)  x=mmax(x,y)
#define minch(x,y)  x=mmin(x,y)
#define exist(x,y)  (find(all(x),y)!=x.end())
#define each(itr,v) for(auto itr:v)
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
DVector mp(2000,Vector(2000,0));

ll calc(ll x1, ll y1, ll x2, ll y2){
  if(x1 > x2 || y1 > y2)return 0;
  ll ret = mp[x2][y2];
  if(x1 > 0)ret -= mp[x1 - 1][y2];
  if(y1 > 0)ret -= mp[x2][y1 - 1];
  if(x1 > 0 && y1 > 0)ret += mp[x1 - 1][y1 - 1];
  return ret;
}

int main(){
  cin.sync_with_stdio(false);
  ll n,k;
  cin >> n >> k;
  rep(i,n){
    ll tx, ty;
    string c;
    cin >> tx >> ty >> c;
    if(c == "W")ty += k;
    ll x = tx % (2 * k);
    ll y = ty % (2 * k);
    mp[x][y]++;
  }

  rep(i, 2 * k)rep(j, 2 * k)if(j > 0)mp[i][j] += mp[i][j - 1];
  rep(i, 2 * k)rep(j, 2 * k)if(i > 0)mp[i][j] += mp[i - 1][j];

  ll ans = 0;
  repl(i,0,k)repl(j,0,k){
    ll tmp = calc(0, 0, i - 1, j - 1) + calc(i + k, 0, 2 * k - 1, j - 1) + calc(i, j, i + k - 1, j + k - 1) + calc(0, j + k, i - 1, 2 * k - 1) + calc(i + k, j + k, 2 * k - 1, 2 * k - 1);
    ans = mmax(ans, mmax(tmp, n - tmp));
  }
  cout << ans << endl;
}
