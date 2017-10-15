#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<int> Array;
typedef vector<vector<ll>> DArray;

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
#define ssort(x) sort(all(x))
#define mkpair(x,y) make_pair(x,y)
#define INF INT_MAX/3
Array a;
int n;

int culc_t(int t,int o) {
  int l = mmin(t,o);
  int r = mmax(t,o);
  int sum=0;
  int c = 1;
  repl(i,l,r){
    if(c % 2 == 1)sum += a[i];
    c++;
  }
  return sum;
}
int culc_o(int t,int o) {
  int l = mmin(t,o);
  int r = mmax(t,o);
  int sum=0;
  int c = 1;
  repl(i,l,r){
    if(c % 2 == 0)sum += a[i];
    c++;
  }
  return sum;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  a.resize(n); rep(i,n)cin >> a[i];
  int maxn,index;
  int ans = -INF;
  rep(i,n) {
    maxn = -INF;
    rep(j,n){
      if(i == j)continue;
      int tmp = culc_o(i,j);
      if(tmp > maxn){
        maxn = tmp;
        index = j;
      }
    }
      int tmp2 = culc_t(i,index);
      if(tmp2 > ans)ans = tmp2;
  }
    cout << ans << endl;
}
