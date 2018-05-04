#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define rep(i,n) repl(i,0,n-1)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3
vector< vector<int> > g;
vector<bool> re;
vector<int> low;
int ans = 0;
int p = 0;
int func(int current, int parent){
  int pw = ++p;
  if(re[current])return low[current];
  low[current] = pw;
  re[current] = true;
  each(tmp,g[current]) {
    if(tmp == parent)continue;
   minch(low[current],func(tmp, current));
  }
  if(pw == low[current])ans++;
  return low[current];
}
int main(){
  cin.sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  g.resize(n);
  re.resize(n);
  low.resize(n);
  rep(i,n){
    low[i] = i;
    re[i] = false;
  }
  int a,b;
  rep(i,m){
    cin >> a >> b;
    g[a-1].pb(b-1);
    g[b-1].pb(a-1);
  }
  func(0,-1);
  cout << ans-1 << endl;
}
