#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef vector<DVec> TVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi                first
#define se                second
#define pb                push_back
#define INF               LLONG_MAX/3
#define MOD               (ll)1000000007
#define bcnt              __builtin_popcount
#define all(x)            (x).begin(),(x).end()
#define srt(x)            sort(all(x))
#define rvs(x)            reverse(all(x))
#define uni(x)            x.erase(unique(all(x)),x.end())
#define ub(x,y)           (upper_bound(all(x),y)-x.begin())
#define lb(x,y)           (lower_bound(all(x),y)-x.begin())
#define rep(i,n)          repl(i,0,n-1)
#define mkp(x,y)          make_pair(x,y)
#define mmax(x,y)         (x>y?x:y)
#define mmin(x,y)         (x<y?x:y)
#define maxch(x,y)        x=mmax(x,y)
#define minch(x,y)        x=mmin(x,y)
#define exist(x,y)        (find(all(x),y)!=x.end())
#define each(itr,v)       for(auto itr:v)
#define repl(i,a,b)       for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)     DVec(n1,Vec(n2,i))
#define tvec(n1,n2,n3,i)  TVec(n1,dvec(n2,n3,i))

ll r,c,x,y,d,l;

ll pow(ll a, ll b){
  return b ? pow(a * a % MOD, b/2) * (b % 2 ? a : 1) % MOD : 1;
}

ll C(ll a, ll b){
  ll ans=1;
  repl(i,1,b)ans = ans * (a-i+1) % MOD * pow(i,MOD-2) % MOD;
  return ans;
}

ll f(ll a, ll b){
  if(a<=0||b<=0||a*b<d+l)return 0;
  return C(a*b,d+l)*C(d+l,d)%MOD;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> r >> c >> x >> y >> d >> l;
  ll one=(f(x,y)-(f(x-1,y)*2+f(x,y-1)*2)+(f(x-2,y)+f(x,y-2)+f(x-1,y-1)*4)-(f(x-2,y-1)*2+f(x-1,y-2)*2)+f(x-2,y-2))%MOD;
  if(one<0)one += MOD;
  ll ans=0;
  repl(i,x,r)repl(j,y,c)ans = (ans + one) % MOD;
  cout << ans << endl;
  return 0;
}
