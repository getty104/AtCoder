#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> Vector;
typedef vector<vector<ll>> DVector;

#define fi          first
#define se          second
#define pb          push_back
#define INF         INT_MAX/3
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define dbg(x)      cout<<#x"="<<x<<endl
#define ub(x,y)     upper_bound(all(x),y)
#define lb(x,y)     lower_bound(all(x),y)
#define uni(x)      x.erase(unique(all(x)),x.end())
#define rep(i,n)    repl(i,0,n-1)
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define mmax(x,y)   (x>y?x:y)
#define mmin(x,y)   (x<y?x:y)
#define maxch(x,y)  x=mmax(x,y)
#define minch(x,y)  x=mmin(x,y)
#define exist(x,y)  (find(all(x),y)!=x.end())
#define each(itr,v) for(auto itr:v)
#define usort(x)    sort(all(x))
#define dsort(x)    sort(all(x),greater<int>())
#define mkp(x,y)    make_pair(x,y)
DVector tree;
int goal;
bool dfs(int parent,int current,int count) {
  if(count==3)return false;
  else if(current == goal)return true;
  else {
    bool flag = false;
    each(itr,tree[current]) {
      if(parent == itr)continue;
      if(dfs(current,itr,count+1))flag = true;
    }
    return flag;
  }
}
int main(){
  cin.sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  tree.resize(n);
  goal = n-1;
  int a,b;
  rep(i,m) {
    cin >> a >> b;
    tree[a-1].pb(b-1);
  }
  bool flag = false;
  int parent = -1;
  bool ans = dfs(parent,0,0);
  cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
