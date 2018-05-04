#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;

#define fi          first
#define se          second
#define pb          push_back
#define INF         INT_MAX
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define dbg(x)      cout<<#x"="<<x<<endl
#define uni(x)      x.erase(unique(all(x)),x.end())
#define ub(x,y)     upper_bound(all(x),y)-x.begin()
#define lb(x,y)     lower_bound(all(x),y)-x.begin()
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

int main(){
  cin.sync_with_stdio(false);
  ll N,R,C,K;
  cin >> R >> C >> K;
  cin >> N;
  Vector row(R,0),col(C,0);
  Vector r(N),c(N);
  rep(i, N){
    cin >> r[i] >> c[i];
    r[i]--;
    c[i]--;
    row[r[i]]++;
    col[c[i]]++;
  }
  Vector sumr(N+1,0),sumc(N+1,0);
  each(itr,row)sumr[itr]++;
  each(itr,col)sumc[itr]++;
  ll ans = 0;
  rep(i,K+1)ans += sumr[i] * sumc[K-i];
  rep(i,N){
    if(row[r[i]] + col[c[i]] == K)ans--;
    else if(row[r[i]] + col[c[i]] == K + 1)ans++;
  }
  cout << ans << endl;
}
