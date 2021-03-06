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

int main() {
  cin.sync_with_stdio(false);
  ll N,C;
  cin >> N >> C;
  vector<P> xv(N);
  rep(i,N) cin>> xv[i].fi >> xv[i].se;
  ll cur = 0;
  ll bit = 0;
  ll sum1 = 0;
  cur = 0;
  rep(i,N){
    if(!(bit >> i & 1))continue;
    ll s = xv[i].se -  mmin(abs(xv[i].fi-cur), C - abs(xv[i].fi-cur));
    if(s>=0){
      cur = xv[i].fi;
      sum1 += s;
    }
  }

  ll sum2 = 0
  cur = 0;
  rep(i,N){
    if(!(bit >> i & 1))continue;
    ll s = xv[N-1-i].se - mmin(abs(xv[N-1-i].fi-cur), C - abs(xv[N-1-i].fi-cur));
    if(s>=0){
      cur = xv[N-1-i].fi;
      sum2 += s;
    }
  }
  cout << mmax(sum1,sum2) << endl;
  return 0;
}
