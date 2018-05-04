#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> Array;
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
#define lb(x,y) lower_bound(all(x),y)
#define ub(x,y) upper_bound(all(x),y)
#define INF INT_MAX/3

int main(){
  cin.sync_with_stdio(false);
  int n,m;
  int x,y;
  cin >> n >> m;
  cin >> x >> y;
  Array a(n);
  Array b(m);
  rep(i,n)cin >> a[i];
  rep(i,m)cin >> b[i];
  ssort(a);
  ssort(b);
  int time=0;
  int current = 0;
  int count = 0;
  bool end = false;
  while(true){
    if(current == 0){
      auto itr = lb(a,time);
      if(itr == a.end())end=true;
      else {
        time = *itr+x;
        current = 1;
      }
    }else{
      auto itr = lb(b,time);
      if(itr == b.end())end=true;
      else {
        time = *itr+y;
        current = 0;
        count++;
      }
    }
    if(end)break;
  }
  cout << count << endl;
}
