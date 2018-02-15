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
  ll r, c, k ,ans=0;
  DVector a(500,Vector(500,0));
  vector<string> s(500);
  cin >> r >> c >> k;
  rep(i,r)cin >> s[i];
  rep(i,r)rep(j,c){
    if (s[i][j] == 'x')a[i][j]++;
    if (j + 1 < c)a[i][j + 1] += a[i][j];
  }
  for (ll x = k - 1; x < r - k + 1; x++) {
    for (ll y = k - 1; y < c - k + 1; y++) {
      ll num=0;
      for (ll z = -k + 1; z <= k - 1; z++) {
        if (y - (k - 1 - abs(z)) == 0)num += a[x + z][y + k - 1 - abs(z)];
        else num += a[x + z][y + k - 1 - abs(z)] - a[x + z][y - k + abs(z)];
      }
      if (num == 0)ans++;
    }
  }
  cout << ans << endl;
}
