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
DVector dp(1001,Vector(1001,INF));
Vector a(100),b(100),c(100);
ll n,ma,mb;
bool jd = false;
void dfs(ll cnt,ll ta, ll tb, ll tc){
  if(cnt == n || dp[ta][tb] < tc)return;
  dp[ta][tb] = tc;
  if(ta > 0 && tb > 0 && ta * mb == tb * ma){
    jd = true;
    return;
  }
  dfs(cnt+1,ta,tb,tc);
  dfs(cnt+1,ta+a[cnt+1],tb+b[cnt+1],tc+c[cnt+1]);
}


int main(){
  cin.sync_with_stdio(false);
  cin >> n >> ma >> mb;
  rep(i,n)cin >> a[i] >> b[i] >> c[i];
  dfs(0,0,0,0);
  dfs(0,a[0],b[0],c[0]);
  ll mn = INF;
  repl(i,1,1000)if(ma*i <= 1000 & mb*i <= 1000)minch(mn,dp[ma*i][mb*i]);
  cout << (jd ? mn : -1) << endl;
}
