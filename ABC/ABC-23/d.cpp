#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi             first
#define se             second
#define pb             push_back
#define INF            LLONG_MAX/3
#define MOD            1000000007
#define bcnt           __builtin_popcount
#define all(x)         (x).begin(),(x).end()
#define uni(x)         x.erase(unique(all(x)),x.end())
#define ub(x,y)        (upper_bound(all(x),y)-x.begin())
#define lb(x,y)        (lower_bound(all(x),y)-x.begin())
#define ssort(x)       sort(all(x))
#define rep(i,n)       repl(i,0,n-1)
#define mkp(x,y)       make_pair(x,y)
#define mmax(x,y)      (x>y?x:y)
#define mmin(x,y)      (x<y?x:y)
#define maxch(x,y)     x=mmax(x,y)
#define minch(x,y)     x=mmin(x,y)
#define exist(x,y)     (find(all(x),y)!=x.end())
#define each(itr,v)    for(auto itr:v)
#define repl(i,a,b)    for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)  DVec(n1,Vec(n2,i))

int main(){
  cin.sync_with_stdio(false);
  ll N;
  cin >> N;
  Vec H(N),S(N),time(N);
  rep(i,N)cin >> H[i] >> S[i];
  ll left = -1, right = 10000000000000000;
  while(right - left > 1){
    ll mid = (left + right) / 2;
    bool ok = true;
    rep(i,N){
      if(mid - H[i] < 0){
        ok = false;
        break;
      }
      time[i] = (mid - H[i]) / S[i];
    }
    ssort(time);
    rep(i,N)if(i > time[i])ok = false;
    if(ok)right = mid;
    else left = mid;
  }
  cout << right << endl;
  return 0;
}
