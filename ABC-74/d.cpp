#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
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
DVector mp;

bool djk(){
  priority_queue<PP> pq;
  P start = mkp(0,1);
  pq.push(mkp(mp[0][1],start));
  while(pq.size()){
    PP state = pq.top();
    pq.pop();
    if(state.fi > 0 && state.fi < mp[state.se.fi][state.se.se])return false;
    if(state.fi > 0 && state.fi == mp[state.se.fi][state.se.se])each(itr,mp[state.se.se]){
      ll cost = mp[state.se.fi][state.se.se]+mp[state.se.se][itr];
      pq.push(mkp(cost,mkp(state.se.fi,itr)));
    }
  }
  return true;
}

int main(){
  cin.sync_with_stdio(false);
  ll n;
  cin >> n;
  mp.resize(n, Vector(n));
  rep(i,n)rep(j,n){
    ll a;
    cin >> a;
    mp[i][j] = a;
    mp[j][i] = a;
  }
  cout << djk() << endl;
}
