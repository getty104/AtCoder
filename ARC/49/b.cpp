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

ll n;
Vec x, y, c;

bool ok(double mid) {
  rep(i, n) {
    rep(j, i) {
      double dx = x[i] - x[j], dy = y[i] - y[j];
      double i_dist = mid / (double)c[i], j_dist = mid / (double)c[j];
      if (abs(dx) > i_dist + j_dist) return false;
      if (abs(dy) > i_dist + j_dist) return false;
    }
  }
  return true;
}

int main() {

  cin.sync_with_stdio(false);
  cin >> n;
  x.resize(n);
  y.resize(n);
  c.resize(n);
  rep(i, n) cin >> x[i] >> y[i] >> c[i];

  double lb = 0, ub = INF;
  while(ub-lb > 1e-5){
    double mid = (ub + lb) / 2;
    if (ok(mid)) ub = mid;
    else lb = mid;
  }

  cout << setprecision(10) << ub << endl;

  return 0;
}
