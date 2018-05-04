#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef vector<DVec> TVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi                first
#define se                second
#define pb                push_back
#define INF               LLONG_MAX/3
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
#define MAX_V 100100
#define MAX_LOG_V 20

DVec G(MAX_V);
DVec par = DVec(MAX_LOG_V,Vec(MAX_V));
Vec depth(MAX_V);

void dfs(ll v,ll p,ll d){
  par[0][v] = p;
  depth[v] = d;
  rep(i,G[v].size())if(G[v][i] != p) dfs(G[v][i],v,d+1);
}

void init(){
  dfs(0,-1,0);
  repl(i,1,MAX_LOG_V-1)rep(j,MAX_V)par[i][j] = par[i-1][par[i-1][j]];
}

ll lca(ll u,ll v){
  ll dv = depth[v];
  ll du = depth[u];
  if(depth[v] < depth[u])swap(u,v);
  for(ll i = MAX_LOG_V-1; i>=0; i--)if(((depth[v] - depth[u]) >> i) & 1)v = par[i][v];
  if(u == v) return dv+du-2*depth[v];
  for(ll i = MAX_LOG_V-1; i>=0; i--){
    if(par[i][v] != par[i][u]){
      v = par[i][v];
      u = par[i][u];
    }
  }
  return dv+du-2*depth[par[0][v]];
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  ll n;
  cin >> n;

  rep(i,n-1){
    ll x,y;
    cin >> x >> y;
    x--; y--;
    G[x].pb(y);
    G[y].pb(x);
  }
  init();

  ll q;
  cin >> q;
  Vec ans;
  rep(i,q){
    ll a,b;
    cin >> a >> b;
    a--;b--;
    ans.pb(lca(a,b)+1);
  }
  rep(i,ans.size())cout << ans[i] << endl;
  return 0;
}
