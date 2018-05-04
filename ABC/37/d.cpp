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
DVector dp;
DVector mp;
ll h,w;
ll count = 0;
ll dfs(ll y,ll x){
  if(dp[y][x] == -1){
    ll sum = 1;
    Vector dy{0,-1,0,1};
    Vector dx{1,0,-1,0};
    rep(i,4){
      ll ty = y + dy[i];
      ll tx = x + dx[i];
      if(ty >= 0 && ty < h && tx >= 0 && tx < w && mp[ty][tx] > mp[y][x])sum = (sum+dfs(ty,tx)%MOD)%MOD;
    }
    dp[y][x] = sum;
  }
  return dp[y][x];
}

int main(){
  cin.sync_with_stdio(false);
  cin >> h >> w;
  dp.resize(h,Vector(w,-1));
  mp.resize(h,Vector(w,-1));
  rep(i,h)rep(j,w)cin >> mp[i][j];
  ll sum = 0;
  rep(i,h)rep(j,w)sum = (sum+dfs(i,j))%MOD;
  cout << sum << endl;
}
