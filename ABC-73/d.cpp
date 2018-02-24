#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef pair<ll,P>  PP;
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
ll N,M,R;
DVector mp;
Vector r;

void dks(){
  priority_queue<PP, vector<PP>, greater<PP>> pq;
  P start = mkp(0,0);
  pq.push(mkp(mp[0][0],start));

  while(pq.size()){
    PP state = pq.top();pq.pop();
    if(state.fi > mp[state.se.fi][state.se.se])continue;
    mp[state.se.fi][state.se.se] = state.fi;
    rep(i,N){
      if(state.se.fi == i)continue;
      ll cost = mp[state.se.fi][state.se.se] + mp[state.se.se][i];
      pq.push(mkp(cost,mkp(state.se.fi,i)));
    }
  }
}

ll dfs(set<ll> st,ll current,ll cost){
  if(st.size() == R)return cost;
  ll mn = INF;
  each(itr,r){
    if(st.count(itr))continue;
    set<ll> ts = st;
    ts.insert(itr);
    minch(mn, dfs(ts, itr, cost + mp[current][itr]));
  }
  return mn;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> N >> M >> R;
  mp.resize(N, Vector(N,INF));
  r.resize(R);
  rep(i,R){
    ll t;
    cin >> t;
    r[i] = t-1;
  }
  rep(i,M){
    ll a,b,c;
    cin >> a >> b >> c;
    mp[a-1][b-1] = c;
    mp[b-1][a-1] = c;
  }

  ll mn = INF;
  rep(i,R){
  set<ll> ts;
  ts.insert(r[i]);
    minch(mn,dfs(ts, r[i], 0));
  }
  cout << mn << endl;
}
