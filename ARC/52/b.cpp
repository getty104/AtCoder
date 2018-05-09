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
#define pi acos(-1.0)

int main(){
  cin.sync_with_stdio(false);
  ll N, Q;
  cin >> N >> Q;
  Vec X(N), R(N), H(N);
  vector<double> sum(101010);
  rep(i, N){
    cin >> X[i] >> R[i] >> H[i];
    double r1=R[i], r2=0;
    rep(h,H[i]){
      double h1 = H[i]-h;
      double h2 = h1-1;
      double r2 = (h2*r1)/h1;
      sum[X[i]+h+1] += (pi*(r1*r1+r1*r2+r2*r2))/3.0;
      r1=r2;
    }
  }
  repl(i,1,100002) sum[i] += sum[i-1];
  rep(i, Q) {
    ll A, B;
    cin >> A >> B;
    cout << setprecision(10) << sum[B]-sum[A] << endl;;
  }
  return 0;
}
