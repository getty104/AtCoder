#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

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

#define INF INT_MAX/3

int main(){
  cin.sync_with_stdio(false);
  int h,w,n,a;
  int i=0,j=0;
  cin >> h >> w;
  cin >> n;
  int m[h][w];
  rep(l,n){
    cin >> a;
    rep(k,a){
      m[i][j] = l+1;
      if((i % 2 == 0 && j == w-1) || (i % 2 == 1 && j == 0))i++;
      else if(i % 2 == 0)j++;
      else if(i % 2 == 1)j--;
    }
  }
  rep(i,h){
    rep(j,w){
      cout << m[i][j];
      if(j<w-1)cout << " ";
    }
    cout << endl;
  }
}