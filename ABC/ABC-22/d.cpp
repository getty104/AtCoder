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

int main() {
  cin.sync_with_stdio(false);
  ll N;
  cin >> N;

  vector<double> Ax(N), Ay(N), Bx(N), By(N);
  rep(i,N)cin >> Ax[i] >> Ay[i];
  rep(i,N)cin >> Bx[i] >> By[i];

  double Ax_mean = accumulate(all(Ax), 0.0) / N;
  double Ay_mean = accumulate(all(Ay), 0.0) / N;
  double Bx_mean = accumulate(all(Bx), 0.0) / N;
  double By_mean = accumulate(all(By), 0.0) / N;

  double A_max = 0, B_max = 0;
  rep(i,N){
      A_max = max(A_max, sqrt(pow(Ax[i] - Ax_mean, 2) + pow(Ay[i] - Ay_mean, 2)));
      B_max = max(B_max, sqrt(pow(Bx[i] - Bx_mean, 2) + pow(By[i] - By_mean, 2)));
  }
  cout << setprecision(8) << B_max / A_max << endl;
}
