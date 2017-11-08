#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> Vector;
typedef vector<vector<ll>> DVector;

#define fi          first
#define se          second
#define pb          push_back
#define INF         INT_MAX/3
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define dbg(x)      cout<<#x"="<<x<<endl
#define ub(x,y)     upper_bound(all(x),y)-x.begin()
#define lb(x,y)     lower_bound(all(x),y)-x.begin()
#define uni(x)      x.erase(unique(all(x)),x.end())
#define rep(i,n)    repl(i,0,n-1)
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define mmax(x,y)   (x>y?x:y)
#define mmin(x,y)   (x<y?x:y)
#define maxch(x,y)  x=mmax(x,y)
#define minch(x,y)  x=mmin(x,y)
#define exist(x,y)  (find(all(x),y)!=x.end())
#define each(itr,v) for(auto itr:v)
#define usort(x)    sort(all(x))
#define dsort(x)    sort(all(x),greater<int>())
#define mkp(x,y)    make_pair(x,y)
int n;
Vector a,b,c;
int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  rep(i,n)cin>>c[i];
  usort(a);
  usort(b);
  usort(c);
  ll ans = 0;
  Vector dp(n);
  for(int i=n-1;i>=0;i--){
    auto itc = ub(c, b[i]);
    if(itc >= n)dp[i]=0;
    else if(i == n-1)dp[i] = n-itc;
    else dp[i] = (n-itc)+dp[i+1];
  }

  each(ita, a) {
    auto itb = ub(b,ita);
    if(itb >= n)break;
    ans += dp[itb];
  }

  cout << ans << endl;
}
