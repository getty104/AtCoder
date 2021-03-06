#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;
typedef pair<ll,pair<ll,ll>> PP;
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
ll h,w;
DVector c(10,Vector(10));
Vector a;
void create_cost(){
  rep(k,10)rep(i,10)rep(j,10)if(c[i][j] > c[i][k]+c[k][j])c[i][j] = c[i][k]+c[k][j];
}


int main(){
  cin.sync_with_stdio(false);
  cin >> h >> w;
  rep(i,10)rep(j,10)cin >> c[i][j];
  rep(i,h)rep(j,w){
    ll ta;
    cin >> ta;
    if(ta>=0)a.pb(ta);
  }
  create_cost();
  ll ans = 0;
  each(itr,a)ans+=c[itr][1];
  cout << ans << endl;
}
