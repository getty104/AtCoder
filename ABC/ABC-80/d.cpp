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

int main(){
  cin.sync_with_stdio(false);
  ll N,C;
  ll size = 100000;
  Vector s(size),t(size),c(size);
  Vector sm(2*size+2,0),tt(2*size+2,0);
  cin >> N >> C;
  rep(i,N)cin >> s[i] >> t[i] >> c[i];
  repl(i,1,C){
    rep(j,2*size+2)tt[j] = 0;
    rep(j,N)if(c[j] == i)tt[s[j]*2 - 1]++,tt[t[j]*2]--;
    repl(j,1,2*size+1)tt[j]+=tt[j-1];
    rep(j,2*size+2)if(tt[j] > 0)sm[j]++;
  }
  ll mx = 0;
  rep(i,2*size+2)maxch(mx,sm[i]);
  cout << mx << endl;
}
