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

int main(){
  cin.sync_with_stdio(false);
  ll n,k;
  cin >> n >> k;
  Vector x(n),y(n);
  Vector xary,yary;

  rep(i,n){
      cin >> x[i] >> y[i];
      xary.pb(x[i]);
      yary.pb(y[i]);
  }
  usort(xary);
  usort(yary);

  ll ans = (xary[n-1] - xary[0]) * (yary[n-1] - yary[0]);
  rep(xi,n)repl(xj,xi+1,n-1)rep(yi,n)repl(yj,yi+1,n-1){
    ll num = 0;
    ll lx = xary[xi],rx = xary[xj];
    ll by = yary[yi],uy = yary[yj];

    rep(i,n)if(lx <= x[i] && x[i] <= rx && by <= y[i] && y[i] <= uy)num++;
    if(num >= k)ans = mmin(ans, (rx - lx) * (uy - by));
  }

  cout << ans << endl;
}
