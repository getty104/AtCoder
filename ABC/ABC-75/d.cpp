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
struct State{
  ll left;
  ll right;
  ll down;
  ll up;
};

int main(){
  cin.sync_with_stdio(false);
  ll n,k;
  ll x,y;
  vector<P> mx;
  vector<P> my;
  cin >> n >> k;
  rep(i,n){
    cin >> x >> y;
    mx.pb(mkp(x,y));
    my.pb(mkp(y,x));
  }
  usort(mx);
  usort(my);
  queue<State> states;
  State mn = State{0,n-1,0,n-1};
  ll mnnum = (mx[mn.right].fi - mx[mn.left].fi) * (my[mn.up].fi - my[mn.down].fi);
  states.push(mn);
  while(states.size()){
    State state = states.front();
    states.pop();
    rep(i,4){
      State ts;
      switch(i){
        case 0:
        ts = State{state.left+1,state.right,state.down,state.up};
        break;
        case 1:
        ts = State{state.left,state.right-1,state.down,state.up};
        break;
        case 2:
        ts = State{state.left,state.right,state.down+1,state.up};
        break;
        case 3:
        ts = State{state.left,state.right,state.down,state.up-1};
        break;
      }
      if(ts.left < ts.right && ts.down < ts.up){
        ll sum = mmin(ts.right - ts.left + 1, ts.up - ts.down + 1);
        ll s = (mx[ts.right].fi - mx[ts.left].fi) * (my[ts.up].fi - my[ts.down].fi);
        if(sum > k){
          if(mnnum > s){
            mn = ts;
            mnnum = s;
          }
          states.push(ts);
        }
      }
    }
  }
  cout << (mx[mn.right].fi - mx[mn.left].fi) * (my[mn.up].fi - my[mn.down].fi) << endl;
}
