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
int main(){
  cin.sync_with_stdio(false);
  ll x1,y1,r,x2,x3,y2,y3;
  cin >> x1 >> y1 >> r;
  cin >> x2 >> y2 >> x3 >> y3;
  ll ans = 0;
  vector<P> c{{x2,y2},{x2,y3},{x3,y2},{x3,y3}};
  bool jd = true;
  rep(i,4){
    double len = sqrt((x1-c[i].fi)*(x1-c[i].fi) + (y1-c[i].se)*(y1-c[i].se));
    if(len > r)jd=false;
  }
  if(x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3)ans = 1;
  else if(jd)ans = 2;
  switch(ans){
    case 0:
    cout << "YES" << endl;
    cout << "YES" << endl;
    break;
    case 1:
    cout << "NO" << endl;
    cout << "YES" << endl;
    break;
    case 2:
    cout << "YES" << endl;
    cout << "NO" << endl;
    break;
  }
  return 0;
}
