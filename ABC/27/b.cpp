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
#define ub(x,y)     upper_bound(all(x),y)
#define lb(x,y)     lower_bound(all(x),y)
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
  int n;
  cin >> n;
  Vector a(n);
  int avr= 0;
  int sum = 0;
  rep(i,n){
    cin>>a[i];
    avr += a[i];
  }
  if(avr%n != 0)sum=-1;
  else{
    avr /= n;
    rep(i,n-1){
      int left = 0;
      int right = 0;
      repl(j,0,i)left+=a[j];
      repl(j,i+1,n-1)right+=a[j];
      if(left != avr*(i+1) || right != avr*(n-1-i)) sum++;
    }
  }
  cout << sum << endl;
}
