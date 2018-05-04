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
  ll x;
  ll y;
  ll ct;
  ll px;
  ll py;
};

int main(){
  cin.sync_with_stdio(false);
  ll r, c, sy, sx, gy, gx;
  cin >> r >> c;
  cin >> sy >> sx;
  sy--;
  sx--;
  cin >> gy >> gx;
  gy--;
  gx--;
  vector<string> mp(r);
  rep(i,r)cin >> mp[i];

  queue<State> states;
  set<P> st;
  states.push(State{sx,sy,0,-1,-1});
  ll ans = INF;
  Vector dy{0,1,0,-1};
  Vector dx{1,0,-1,0};
  while(states.size() > 0){
    State state = states.front();
    states.pop();
    P jd = mkp(state.x,state.y);
    if(st.count(jd))continue;
    st.insert(jd);

    if(state.y == gy && state.x == gx){
      ans = state.ct;
      break;
    }
    rep(i,4){
      ll ty = state.y + dy[i];
      ll tx = state.x + dx[i];
      if(ty >= 0 && ty < r && tx >= 0 && tx < c && mp[ty][tx] == '.' && (ty != state.py || tx != state.px))
        states.push(State{tx,ty,state.ct+1,state.x,state.y});
    }
  }
  cout << ans << endl;
}
