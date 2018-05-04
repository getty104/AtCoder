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

int n,m;
vector<int> x, y;
ll memo[(1<<16) - 1];

ll solve(int s) {
  if(memo[s]) return memo[s];

  vector<bool> remain(n,false);
  rep(i,m) {
    if((s & 1 << (x[i] - 1)) && (s & 1 << (y[i] -1))) {
      remain[x[i] -1] = true;
    }
  }

  ll res = 0;
  rep(i,n) {
    if(!(s & (1 << i)) || remain[i]) continue;
    res += solve(s & ~(1 << i));
  }
  return memo[s] = res;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n >> m;
  x.resize(m);
  y.resize(m);
  rep(i,m) {
    cin >> x[i] >> y[i];
  }

  memo[0] = 1;
  cout << solve((1 << n) - 1) << endl;
}
