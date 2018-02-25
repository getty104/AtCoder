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
ll n;
DVector tree;
Vector snuke,fennec;

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  tree.resize(n);
  snuke.resize(n);
  fennec.resize(n);
  rep(i,n-1){
    ll a,b;
    cin >> a >> b;
    tree[a-1].pb(b-1);
    tree[b-1].pb(a-1);
  }
  queue<P> q1;
  q1.push(mkp(0,0));
  set<ll> st1;
  while(q1.size()){
    P state = q1.front();
    q1.pop();
    if(st1.count(state.fi))continue;
    st1.insert(state.fi);
    fennec[state.fi] = state.se;
    each(itr,tree[state.fi]){
      q1.push(mkp(itr,state.se+1));
    }
  }
  queue<P> q2;
  q2.push(mkp(n-1,0));
  set<ll> st2;
  while(q2.size()){
    P state = q2.front();
    q2.pop();
    if(st2.count(state.fi))continue;
    st2.insert(state.fi);
    snuke[state.fi] = state.se;
    each(itr,tree[state.fi]){
      q2.push(mkp(itr,state.se+1));
    }
  }
  ll cnt1 = 0,cnt2 = 0;
  rep(i,n)fennec[i] <= snuke[i] ? cnt1++ : cnt2++;
  cout << (cnt1 > cnt2 ? "Fennec" : "Snuke") << endl;
}
