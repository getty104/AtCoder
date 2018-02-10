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
  ll n,m;
  cin >> n >> m;
  DVector mp(n+1,Vector(n+1,INF));
  rep(i,m){
    ll u,v,l;
    cin >> u >> v >> l;
    mp[u][v] = l;
    mp[v][u] = l;
  }
  repl(k,2,n)repl(i,2,n)repl(j,2,n)mp[i][j] = mmin(mp[i][j],mp[i][k]+mp[k][j]);
  ll ans = INF;
  repl(i,2,n)repl(j,2,n){
    if(i==j)continue;
    ans = mmin(ans,mp[1][i]+mp[i][j]+mp[j][1]);
  }
  if(ans == INF)cout << -1 << endl;
  else cout << ans << endl;
}
