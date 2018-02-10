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
ll n, m;
ll a,b;
DVector mp;
Vector costs;
struct State{
  ll ct;
  ll pt;
  ll prt;
};

void create(){
  queue<State> states;
  states.push(State{0,a,-1});
  while(states.size() > 0){
    State state = states.front();
    states.pop();
    if(costs[state.pt] != -1)continue;
    costs[state.pt] = state.ct;
    each(itr, mp[state.pt]){
      if(itr == state.prt)continue;
      states.push(State{state.ct+1,itr,state.pt});
    }
  }
}

Vector memo;
ll dfs(int current){

}

int main(){
  cin.sync_with_stdio(false);
  ll m;
  cin >> n;
  cin >> a >> b;
  a--;
  b--;
  cin >> m;
  mp.resize(n);
  costs.resize(n,-1);
  memo.resize(n,-1);
  rep(i,m){
    int x,y;
    cin >> x >> y;
    mp[x-1].pb(y-1);
    mp[y-1].pb(x-1);
  }
  create();
}
