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

int main(){
  cin.sync_with_stdio(false);
  int n,l,r;
  int c = 1000000;
  Vector a(c+1,0);
  cin >> n;
  rep(i,n){
    cin >> l >> r;
    a[l-1] ++;
    a[r]--;
  }
  repl(i,1,c)a[i] += a[i-1];
  int sum = 0;
  rep(i,c)sum+=a[i];
  cout << sum << endl;
}
