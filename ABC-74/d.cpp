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
  ll n;
  cin >> n;
  DVector d(n,Vector(n));
  rep(i,n)rep(j,n)cin >> d[i][j];
  DVector t = d;
  ll flag = true;
  rep(i,n)rep(j,n)rep(k,n)flag = flag && (t[i][j] <= t[i][k] + t[k][j]);
  ll ans = 0;
  if(flag){
    rep(k,n)rep(i,n)rep(j,n)if((d[i][j] > 0 && d[i][k] > 0 && d[k][j] > 0 ) && d[i][j] == d[i][k] + d[k][j])d[i][j] = 0;
    rep(i,n)repl(j,i+1,n-1)ans+=d[i][j];
  }else{
    ans = -1;
  }
  cout << ans << endl;
}
