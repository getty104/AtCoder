#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi             first
#define se             second
#define pb             push_back
#define INF            LLONG_MAX/3
#define MOD            1000000007
#define bcnt           __builtin_popcount
#define all(x)         (x).begin(),(x).end()
#define uni(x)         x.erase(unique(all(x)),x.end())
#define ub(x,y)        (upper_bound(all(x),y)-x.begin())
#define lb(x,y)        (lower_bound(all(x),y)-x.begin())
#define ssort(x)       sort(all(x))
#define rep(i,n)       repl(i,0,n-1)
#define mkp(x,y)       make_pair(x,y)
#define mmax(x,y)      (x>y?x:y)
#define mmin(x,y)      (x<y?x:y)
#define maxch(x,y)     x=mmax(x,y)
#define minch(x,y)     x=mmin(x,y)
#define exist(x,y)     (find(all(x),y)!=x.end())
#define each(itr,v)    for(auto itr:v)
#define repl(i,a,b)    for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)  DVec(n1,Vec(n2,i))

int main(){
  cin.sync_with_stdio(false);
  ll N;
  cin >> N;
  ll mx = -INF;
  ll mxd = 0;
  repl(i,2,N){
    cout << "? " << 1 << " " << i << endl;
    ll tmx;
    cin >> tmx;
    if(mx < tmx){
      mx = tmx;
      mxd = i;
    }
  }

  ll mx2 = -INF;
  repl(i,1,N){
    if(i == mxd)continue;
    cout << "? " << mxd << " " << i << endl;
    ll tmx;
    cin >> tmx;
      maxch(mx2,tmx);
  }
  cout << "! " << mx2 << endl;
  return 0;
}
