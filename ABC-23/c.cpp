#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<int> Vector;
typedef vector<vector<int>> DVector;

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
  ll rr,cc,k,n;
  cin >> rr >> cc >> k;
  cin >> n;
  ll r[rr], c[cc];
  rep(i,rr)r[i]=0;
  rep(i,cc)c[i]=0;
  ll rc[rr][cc];
  rep(i,rr)rep(j,cc)rc[i][j]=0;
  ll tr,tc;
  rep(i,n) {
    cin >> tr;
    cin >> tc;
    r[tr-1]++;
    c[tc-1]++;
    rc[tr-1][tc-1] = 1;
  }


  ll count = 0;
  rep(i,rr)rep(j,cc)if(r[i]+c[j]-rc[i][j] == k)count++;
  cout << count << endl;
}
