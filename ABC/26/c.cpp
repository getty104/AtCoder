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
#define ub(x,y)     upper_bound(all(x),y)-x.begin()
#define lb(x,y)     lower_bound(all(x),y)-x.begin()
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
DVector b;

int sum(int current){
  int ans = 0;
  if(b[current].size() == 0) return 1;
  else if(b[current].size() == 1) return 2*sum(b[current][0])+1;

  int mx=-1,mn=INF;
  each(itr,b[current]){
    int tmp = sum(itr);
    minch(mn, tmp);
    maxch(mx, tmp);
  }
  return mx+mn+1;
}

int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  b.resize(n);
  int t;
  repl(i,1,n-1){
    cin >> t;
    b[t-1].pb(i);
  }
  cout << sum(0) << endl;
}
