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
#define INF INT_MAX/3
double short_arrow(double minute) {
  return 360.0 *(minute/60.0);
}

double long_arrow(double hour, int minute) {
  return 360 * (hour/12.0) + (360.0/12.0) * (minute/60.0);
}
int main(){
  cin.sync_with_stdio(false);
  double hour,minute;
  cin >> hour >> minute;
  if(hour >= 12)hour -= 12;
  double ans = abs(short_arrow(minute)-long_arrow(hour,minute));
  if(ans >180)ans = 360 - ans;
  cout << ans << endl;
}
