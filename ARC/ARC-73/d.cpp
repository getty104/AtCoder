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
ll N, W;
vector<P> mp;
set<P> st;
map<P,ll> memo;
ll dfs(ll n, ll weight){
  P idx = mkp(n,weight);
  if(st.count(idx))return memo[mkp(n,weight)];
  if(n == N)return 0;
  ll res = dfs(n+1,weight);
  if(weight - mp[n].fi >= 0)maxch(res,mp[n].se+dfs(n+1,weight-mp[n].fi));
  st.insert(idx);
  return memo[idx] = res;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> N >> W;
  rep(i,N){
    ll w,v;
    cin >> w >> v;
    mp.pb(mkp(w,v));
  }
  cout << dfs(0,W) << endl;
}
