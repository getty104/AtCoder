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

int main(void){
  cin.sync_with_stdio(false);
  ll H, W, N;
  cin >> H >> W >> N;
  Vector a(N), b(N);
  rep(i,N) cin >> a[i] >> b[i];
  Vector ans(10);
  map<P,ll> ma;
  rep(i,N){
    ll x;
    ll y;
    rep(k,9) {
      x = a[i] + k % 3 - 1;
      y = b[i] + k / 3 - 1;
      if(x < 2 || x > H - 1 || y < 2 || y > W - 1)continue;
      else ma[mkp(x,y)]++;
    }

  }
  ans[0] = (H-2) * (W-2);
  rep(i,N){
    ll x;
    ll y;
    rep(k,9){
      x = a[i] + k % 3 - 1;
      y = b[i] + k / 3 - 1;
      if(x < 2 || x > H - 1 || y < 2 || y > W - 1)continue;
      else if(ma[mkp(x,y)] != 0)ans[ma[mkp(x, y)]]++;
    }
  }
  rep(i,9)ans[0] -= ans[i+1]/(i+1);
  rep(i,10) cout << ans[i]/(mmax(1,i)) << endl;
}
