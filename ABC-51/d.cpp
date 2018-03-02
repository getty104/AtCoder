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

int main(){
  cin.sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  DVector mp(n,Vector(n,INF));
  vector<P> edges;
  rep(i,n)mp[i][i] = 0;
  rep(i,m){
    ll a,b,c;
    cin >> a >> b >> c;
    mp[a-1][b-1] = c;
    mp[b-1][a-1] = c;
    edges.pb(mkp(a-1,b-1));
    edges.pb(mkp(b-1,a-1));
  }

  DVector tmp = mp;
  rep(k,n)rep(i,n)rep(j,n)minch(mp[i][j],mp[i][k]+mp[k][j]);
  vector<vector<bool>> jd(n,vector<bool>(n,false));
  rep(s,n)rep(t,n)each(edge,edges)if(mp[s][edge.fi]+tmp[edge.fi][edge.se]+mp[edge.se][t] == mp[s][t]){
    jd[edge.fi][edge.se] = true;
    jd[edge.se][edge.fi] = true;
  }
  ll sum = 0;
  each(edge,edges)if(!jd[edge.fi][edge.se])sum++;
  cout << sum/2 << endl;
}
