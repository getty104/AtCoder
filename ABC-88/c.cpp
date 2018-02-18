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

int main(){
  cin.sync_with_stdio(false);
  DVector c(3,Vector(3));
  rep(i,3)rep(j,3)cin >> c[i][j];
  bool jd = false;
  rep(a1,101)rep(a2,101)rep(a3,101){
    Vector a{a1,a2,a3};
    Vector b{c[0][0]-a1,c[0][1] - a1, c[0][2] - a1};
    jd = true;
    rep(i,3)rep(j,3)if(c[i][j] != a[i] + b[j])jd = false;
    if(jd){
      cout << "Yes" << endl;
      return 0;
    }
  }
      cout << "No" << endl;
}
