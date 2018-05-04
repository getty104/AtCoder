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
#define INF         INT_MAX
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
int n;
DVector f,p;

ll dfs(Vector a){
  ll ans;
  if(a.size() == 10){
    bool flag = false;
    rep(i,10)if(a[i] != 0)flag = true;
    if(!flag)ans = -INF;
    else{
      Vector c(n,0);
      ll sum = 0;
      rep(i,n)rep(j,10)if(a[j] && f[i][j])c[i]++;
      rep(i,n) sum += p[i][c[i]];
      ans = sum;
    }
  }else{
    Vector tmp1 = a;
    Vector tmp2 = a;
    tmp1.pb(1);
    tmp2.pb(0);
    ans = mmax(dfs(tmp1),dfs(tmp2));
  }
  return ans;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  f.resize(n,Vector(10));
  p.resize(n,Vector(11));
  rep(i,n)rep(j,10)cin >> f[i][j];
  rep(i,n)rep(j,11)cin >> p[i][j];
  Vector a;
  cout << dfs(a) << endl;
}
