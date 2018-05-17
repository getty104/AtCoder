#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
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
#define MOD               1000000007
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

ll N, M, K, H, W, L, R;

ll power(ll x,  ll n) {
  ll tmp = 1;
  if (n > 0) {
    tmp = power(x, n / 2);
    if (n % 2 == 0) tmp = (tmp*tmp) % MOD;
    else tmp = (((tmp*tmp) % MOD)*x) % MOD;
  }
  return tmp;
}

int main() {
  cin.sync_with_stdio(false);
  cin >> N;
  Vec v(N), num(N+1,0);
  ll max_n = 0;
  set<ll> s;
  rep(i,N){
    cin >> v[i];
    maxch(max_n, v[i]);
    s.insert(v[i]);
    num[v[i]]++;
  }
  if (v[0]){
    cout << 0 << endl;
    return 0;
  }
  if (s.size() != max_n + 1) {
    cout << 0 << endl;
    return 0;
  }
  if (num[0] > 1) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  repl(i,1,max_n){
    ll box = power(2, num[i - 1]);
    box--;
    ans *= power(box, num[i]);
    ans %= MOD;
    box = num[i]*(num[i] - 1) / 2;
    box %= (MOD - 1);
    ans *= power(2, box);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
