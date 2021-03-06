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
#define ub(x,y)        (upper_bound(x.begin(),x.end(),y)-x.begin())
#define lb(x,y)        (lower_bound(x.begin(),x.end(),y)-x.begin())
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

int main() {
  cin.sync_with_stdio(false);
  ll N; cin >> N;
  Vec a1,a2;
  rep(i,N){
    ll ta;
    cin >> ta;
    a1.pb(ta);
    a2.pb(-ta);
  }

  ssort(a1);
  ssort(a2);
  double A = a1[N-1];
  ll b1 = a1[lb(a1, A/2)];
  ll b2 = a2[lb(a2, -A/2)];
  if(N == 2)cout << (ll)A << " " << a1[0] << endl;
  else if(abs(b1*2-A) < abs(-b2*2 - A) || abs((A-b1)*2 - A) < abs((A+b2)*2 - A))cout << (ll)A << " " << b1 << endl;
  else cout << (ll)A << " " << -b2 << endl;
  return 0;
}

