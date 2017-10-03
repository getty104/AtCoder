#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
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


//// BinaryIndexedTree （区間の和を高速に行う）
// 1D (0-indexed)
#define MAX_N 123456
struct BIT{
  ll bit[MAX_N];
  // 初期化
  void init(){
    memset(bit,0,sizeof(bit));
  }

  int query(int i) {
    if(!(i + 1)) return 0;
    return mmax(bit[i], query((i + 1) - ((i + 1) & -(i + 1)) - 1));
  }

  void update(int i, int n) {
    if(i > MAX_N) return;
    bit[i] = mmax(bit[i], n);
    update((i + 1) + ((i + 1) & -(i + 1)) - 1, n);
  }
};


#define SIZE 100000
int main(){
  cin.sync_with_stdio(false);

  BIT bit;
  bit.init();
  int N;
  cin >> N;
  P hw[SIZE];
  rep(i,N) cin >> hw[i].fi >> hw[i].se;
  sort(hw,hw+N);
  vector<P> q;
  rep(i,N){
    q.pb(P(hw[i].se,bit.query(hw[i].se-1)+1));
    if(i+1 == N || hw[i].fi != hw[i+1].fi){
      rep(j,q.size())bit.update(q[j].fi,q[j].se);
      q.clear();
    }
  }
  cout << bit.query(SIZE+1)<<endl;
}