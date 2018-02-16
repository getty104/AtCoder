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

struct edge{
  ll f,t,c;
};

ll n,m;
ll cnt = 101010;
vector<edge> es;
vector< vector<P> > g(cnt);
vector<bool> used(cnt);
Vector d(cnt);

int main(){
  cin >> n >> m;
  rep(i,m){
    ll a,b,c;
    cin>> a >> b >> c;
    a--;
    b--;
    g[a].pb(P(b,c));
    used[b] = true;
    es.pb(edge{a,b,c});
  }
  priority_queue<P, vector<P>, greater<P> > que;
  rep(i,n){
    d[i] = INF;
    if(used[i])continue;
    que.push(P(0,i));
  }
  while(que.size() > 0){
    ll v = que.top().se;
    ll nd = que.top().fi;
    que.pop();
    if(d[v] != INF)continue;
    d[v] = nd;
    each(e,g[v])que.push(P(nd+e.se, e.fi));
  }
  bool ok = true;
  rep(i,m){
    ll v = es[i].f, u = es[i].t, nc = es[i].c;
    if(d[v] + nc != d[u])ok = false;
  }
  if(ok)cout <<(ok ? "Yes" : "No") << endl;
}
