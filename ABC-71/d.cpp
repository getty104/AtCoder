#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef pair<ll,P>  PP;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;
typedef priority_queue<PP, vector<PP>, greater<PP>> PPQueue;

#define fi          first
#define se          second
#define sfi         se.fi
#define sse         se.se
#define pb          push_back
#define INF         INT_MAX
#define MOD         1000000007
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define uni(x)      x.erase(unique(all(x)),x.end())
#define ub(x,y)     (upper_bound(all(x),y)-x.begin())
#define lb(x,y)     (lower_bound(all(x),y)-x.begin())
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

ll n;
string s1,s2;
ll ans = 0;
int main() {
  cin.sync_with_stdio(false);

  cin >> n;
  cin >> s1 >> s2;
  ans = 1;
  ll mode = -1;
  rep(i,n){
    switch(mode){
      case -1 :
      if (s1[i] == s2[i]) {
        mode = 0;
        ans = 3;
      }
      else {
        mode = 1;
        ans = 6;
      }
      break;
      case 0 :
      if (s1[i] == s2[i]) {
        mode = 0;
        ans *= 2;
      }
      else {
        mode = 1;
        ans *= 2;
      }
      break;
      case 1 :
      mode = 2;
      break;
      case 2 :
      if (s1[i] == s2[i]) {
        mode = 0;
        ans *= 1;
      }
      else {
        mode = 1;
        ans *= 3;
      }
      break;
    }
    ans %= MOD;
  }
  cout << ans << endl;
}
