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

vector<vector<P>> edge(100000 + 1);
vector<vector<P>> redge(100000 + 1);
Vector dist(100000 + 1);
Vector rdist(100000 + 1);

void dijkstra(void) {
  priority_queue<P, vector<P>, greater<P>> pq;
  dist[1] = 0;
  pq.push({ 0,1 });
  while (pq.size()) {
    ll from = pq.top().second;
    pq.pop();
    rep(i, edge[from].size()){
      ll to = edge[from][i].first;
      if(dist[to] > dist[from] + edge[from][i].second){
        dist[to] = dist[from] + edge[from][i].second;
        pq.push({ dist[from] + edge[from][i].second,to });
      }
    }
  }
}

void rdijkstra(void) {
  priority_queue<P, vector<P>, greater<P>> pq;
  rdist[1] = 0;
  pq.push({ 0,1 });
  while (pq.size()) {
    ll from = pq.top().second;
    pq.pop();
    rep(i, redge[from].size()) {
      ll to = redge[from][i].first;
      if(rdist[to] > rdist[from] + redge[from][i].second){
        rdist[to] = rdist[from] + redge[from][i].second;
        pq.push({ rdist[from] + redge[from][i].second,to });
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  ll N, M, T;
  cin >> N >> M >> T;
  Vector A(N + 1);
  repl(i, 1, N) cin >> A[i];
  rep(i,M){
    ll a, b, c;
    cin >> a >> b >> c;
    edge[a].pb({ b,c });
    redge[b].pb({ a,c });
  }

  repl(i, 1, N)dist[i] = rdist[i] = INF;
  dijkstra();
  rdijkstra();

  ll value = 0;
  repl(i, 1, N)if(T >= dist[i] + rdist[i])maxch(value, (T - dist[i] - rdist[i])*A[i]);
  cout << value << endl;
}
