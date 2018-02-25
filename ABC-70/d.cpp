#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef pair<ll,P>  PP;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;
typedef priority_queue<PP, vector<PP>, greater<PP>> PPQueue;

#define fi          first
#define se          second
#define sfi         se.fi
#define sse         se.se
#define pb          push_back
#define INF         INT_MAX
#define MOD         1000000007
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define uni(x)      x.erase(unique(all(x)),x.end())
#define ub(x,y)     (upper_bound(all(x),y)-x.begin())
#define lb(x,y)     (lower_bound(all(x),y)-x.begin())
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
ll n,q,k;
DVector tree;
map<P,ll> costs;
Vector ans;

void dfs(ll root, ll parent, ll edge, ll cost){
  costs[mkp(root,edge)] = cost;
  costs[mkp(edge,root)] = cost;
  each(itr,tree[edge]){
    if(itr == parent)continue;
    dfs(root, edge, itr, cost+costs[mkp(edge,itr)]);
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  tree.resize(n);
  rep(i,n-1){
    ll a,b,c;
    cin >> a >> b >> c;
    tree[a-1].pb(b-1);
    tree[b-1].pb(a-1);
    costs[mkp(a-1,b-1)] = c;
    costs[mkp(b-1,a-1)] = c;
  }

  cin >> q >> k;
  k--;
  dfs(k,-1,k,0);
  rep(i,q){
    ll x,y;
    cin >> x >> y;
    ans.pb(costs[mkp(x-1,k)]+costs[mkp(k,y-1)]);
  }
  rep(i,q)cout << ans[i] << endl;
}
