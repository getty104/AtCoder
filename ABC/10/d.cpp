#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef vector<DVec> TVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi                first
#define se                second
#define pb                push_back
#define INF               LLONG_MAX
#define MOD               1000000007
#define bcnt              __builtin_popcount
#define all(x)            (x).begin(),(x).end()
#define srt(x)            sort(all(x))
#define rvs(x)            reverse(all(x))
#define uni(x)            x.erase(unique(all(x)),x.end())
#define ub(x,y)           (upper_bound(all(x),y)-x.begin())
#define lb(x,y)           (lower_bound(all(x),y)-x.begin())
#define rep(i,n)          repl(i,0,n-1)
#define mkp(x,y)          make_pair(x,y)
#define mmax(x,y)         (x>y?x:y)
#define mmin(x,y)         (x<y?x:y)
#define maxch(x,y)        x=mmax(x,y)
#define minch(x,y)        x=mmin(x,y)
#define exist(x,y)        (find(all(x),y)!=x.end())
#define each(itr,v)       for(auto itr:v)
#define repl(i,a,b)       for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)     DVec(n1,Vec(n2,i))
#define tvec(n1,n2,n3,i)  TVec(n1,dvec(n2,n3,i))

struct edge { ll to, cap, rev; };

vector<vector<edge>> g(1010);
vector<bool> used(1010,false);
ll n, G, e;

void add(ll from, ll to, ll cap) {
  g[from].pb(edge{ to, cap, (ll)g[to].size() });
  g[to].pb(edge{ from, 0, (ll)g[from].size() - 1 });
}

ll dfs(ll v, ll t, ll f) {
  if (v == t)return f;
  used[v] = true;
  rep(i,g[v].size()){
    edge &e = g[v][i];
    if (!used[e.to] && e.cap > 0) {
      ll d = dfs(e.to, t, mmin(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

ll max_flow(ll s, ll t) {
  ll flow = 0;
  while(true){
    rep(i,n+1)used[i]=false;
    ll f = dfs(s, t, INF);
    if (f == 0)return flow;
    flow += f;
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin >> n >> G >> e;
  rep(i,G){
    ll p;
    cin >> p;
    add(p, n, 1);
    add(n, p, 1);
  }
  rep(i,e){
    ll a, b;
    cin >> a >> b;
    add(a, b, 1);
    add(b, a, 1);
  }
  cout << max_flow(0, n) << endl;
  return 0;
}
