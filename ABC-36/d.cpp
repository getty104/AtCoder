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

vector< vector<int> > tree;
int n;
int mod = 1e9 + 7;
vector<int> memo;
int func(int ad, int color, int par) {

  ll tmp = 1;
  if(color == 0){
    rep(i,tree[ad].size()){
      if(par == tree[ad][i])continue;
      if(memo[tree[ad][i]] == -1) memo[tree[ad][i]] = func(tree[ad][i],0,ad);
      tmp *= memo[tree[ad][i]] + func(tree[ad][i],1,ad);
      tmp %= mod;
    }
  }else{
   rep(i,tree[ad].size()){
    if(par == tree[ad][i])continue;
      if(memo[tree[ad][i]] == -1) memo[tree[ad][i]] = func(tree[ad][i],0,ad);
    tmp *= memo[tree[ad][i]];
    tmp %= mod;
  }
}
return tmp;
}

int main() {
  cin.sync_with_stdio(false);
  cin >> n;
  vector< vector<int> > ttree(n);
  vector<int> mmemo(n,-1);
  int t1, t2;
  rep(i,n-1){
    cin >> t1 >> t2;
    ttree[t1-1].pb(t2-1);
    ttree[t2-1].pb(t1-1);
  }
  tree = ttree;
  memo = mmemo;
  int ans = 0;
  ans += func(0,0,-1);
  ans += func(0,1,-1);
  cout << ans << endl;
}
