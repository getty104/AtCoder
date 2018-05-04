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
vector<string> mp;
ll h,w;
struct State{
  ll x;
  ll y;
  ll cost;
};

ll rds(){
  queue<State> states;
  states.push(State{0,0,0});
  Vector dx = {1,0,-1,0};
  Vector dy = {0,-1,0,1};
  set<P> st;
  while(states.size()){
    State state = states.front();
    states.pop();
    if(st.count(mkp(state.x,state.y)))continue;
    st.insert(mkp(state.x,state.y));
    if(state.x == w-1 && state.y == h-1)return state.cost;
    rep(i,4){
      ll tx =  state.x + dx[i];
      ll ty =  state.y + dy[i];
      if(tx > -1 && tx < w && ty > -1 && ty < h && mp[ty][tx] == '.'){
        states.push(State{tx, ty, state.cost+1});
      }
    }
  }
  return -1;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> h >> w;
  mp.resize(h);
  rep(i,h)cin >> mp[i];
  ll result = rds();
  ll sum = 0;
  rep(i,h)rep(j,w)if(mp[i][j] == '.')sum++;
  if(result != -1)cout << sum - result -1 << endl;
  else cout << result << endl;
}
