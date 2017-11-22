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

DVector b(2,Vector(3)),c(3,Vector(2));
judge(Dvector m, int turn){
  bool flag = true;
  Vector ans;
  rep(i,3)rep(j,3){
    if(m[i][j] == -1){
      if(turn == 1)m[i][j] = 1;
      else m[i][j]=0;
      ans.pb(judge(m,(turm+1)%2));
      m[i][j] = -1;
      flag = false;
    }
  }
  if(flag){
    rep(i,2)rep(j,3){
      if(m[i][j] == m[i+1][j])
        else
      }
  }
}


int main(){
  cin.sync_with_stdio(false);
  DVector m(3,Vector(3,-1));
  rep(i,2)rep(j,3)cin >> b[i][j];
  rep(i,3)rep(j,2)cin >> c[i][j];
}
