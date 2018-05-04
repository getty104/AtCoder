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

ll N,M,R;
Vector r;
DVector mp;
ll ct = INF;
void dfs(Vector a){
  if(a.size() == R){
    ll cost = 0;
    rep(i,R-1)cost += mp[a[i]][a[i+1]];
    minch(ct, cost);
  }else{
    each(itr,r){
      if(exist(a, itr))continue;
      Vector ta = a;
      ta.pb(itr);
      dfs(ta);
    }
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin >> N >> M >> R;
  r.resize(R);
  mp.resize(N, Vector(N,INF));
  rep(i,R){
    cin >> r[i];
    r[i]--;
  }
  rep(i,M){
    ll a, b, c;
    cin >> a >> b >> c;
    mp[a-1][b-1] = c;
    mp[b-1][a-1] = c;
  }
  rep(k,N)rep(i,N)rep(j,N)minch(mp[i][j], mp[i][k]+mp[k][j]);
  dfs(Vector());
  cout << ct << endl;
}
