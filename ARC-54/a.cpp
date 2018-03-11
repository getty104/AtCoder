#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi          first
#define se          second
#define pb          push_back
#define INF         LLONG_MAX/3
#define MOD         1000000007
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define uni(x)      x.erase(unique(all(x)),x.end())
#define ub(x,y)     (upper_bound(all(x),y)-x.begin())
#define lb(x,y)     (lower_bound(all(x),y)-x.begin())
#define rep(i,n)    repl(i,0,n-1)
#define mkp(x,y)    make_pair(x,y)
#define mmax(x,y)   (x>y?x:y)
#define mmin(x,y)   (x<y?x:y)
#define each(itr,v) for(auto itr:v)
#define dvec(a,n,i) a(n,Vector(n,i))
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define ssort(x)    sort(all(x))
#define maxch(x,y)  x=mmax(x,y)
#define minch(x,y)  x=mmin(x,y)
#define exist(x,y)  (find(all(x),y)!=x.end())

int main(){
  cin.sync_with_stdio(false);
  ll L,S,D;
  double X,Y;
  cin >> L >> X >> Y >> S >> D;
  double K = S < D ? (D-S) % L : (D+L-S) % L;
  double K1 = (D + L - S) % L, K2 = (S + L - D) % L;
  cout << fixed << setprecision(10);
  if(X < Y)cout << mmin(K1/(Y+X),K2/(Y-X)) << endl;
  else cout << K1/(Y+X) << endl;
}
