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
#define INF         1LL << 50
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


int main(){
  cin.sync_with_stdio(false);
  ll n,m;
  cin >> n >> m;
  ll nmx = 1000;
  ll mmx = 2000;
  Vector a(mmx), b(mmx), c(mmx),dist(nmx,INF);
  rep(i,m){
    cin >> a[i] >> b[i] >> c[i];
    c[i] = -c[i];
  }
  dist[0] = 0;
  rep(loop,n-1)rep(i,m){
    if(dist[a[i] - 1] == INF)continue;
    if(dist[b[i] - 1] > dist[a[i] - 1] + c[i])dist[b[i] - 1] = dist[a[i] - 1] + c[i];
  }
  ll ans = dist[n - 1];
  vector<bool> negative(nmx,false);
  rep(loop,n)rep(i,m){
    if(dist[a[i] - 1] == INF)continue;
    if(dist[b[i] - 1] > dist[a[i] - 1] + c[i]){
      dist[b[i] - 1] = dist[a[i] - 1] + c[i];
      negative[b[i] - 1] = true;
    }
    if(negative[a[i] - 1] == true)negative[b[i] - 1] = true;
  }

  if(negative[n - 1]) cout << "inf" << endl;
  else                cout << -ans << endl;
}
