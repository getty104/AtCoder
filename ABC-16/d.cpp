#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
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

ll ax,ay,bx,by;

bool f(ll x1,ll y1,ll x2,ll y2){
  ll s1 = (ay - by)*(x1 - ax) - (y1 - ay)*(ax - bx);
  ll s2 = (ay - by)*(x2 - ax) - (y2 - ay)*(ax - bx);
  ll s3 = (y1 - y2)*(ax - x1) - (ay - y1)*(x1 - x2);
  ll s4 = (y1 - y2)*(bx - x1) - (by - y1)*(x1 - x2);
  return s1*s2 <= 0 && s3*s4 <= 0;
}
int main(){
  cin.sync_with_stdio(false);
  cin >> ax >> ay >> bx >> by;
  ll n;
  cin >> n;
  Vec x(110), y(110);
  rep(i,n)cin >> x[i] >> y[i];
  ll ans=0;
  rep(i,n)if(f(x[i], y[i], x[(i + 1)%n],y[(i + 1)%n]))ans++;
  ans = ans/2 + 1;
  cout << ans << endl;
  return 0;
}
