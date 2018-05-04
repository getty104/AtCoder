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
// エラトステネスの篩 [1,n]
bool is_prime[INF];
void sieve(ll n){
  for(ll i=0;i<=n;i++)is_prime[i]=true;
  is_prime[0]=is_prime[1]=false;

  for(ll i=2;i<=n;i++){
    if(is_prime[i]){
      for(ll j=2*i;j<=n;j+=i)is_prime[j]=false;
    }
  }
}
int main(){
  cin.sync_with_stdio(false);
  sieve(1000000);
  Vector prs(100000+1,0);
  repl(i,1,100000)if(i % 2 == 1 && is_prime[i] && is_prime[(i+1) / 2])prs[i]++;
  repl(i,2,100000)prs[i] += prs[i-1];
  ll q;
  cin >> q;
  Vector ans(q);
  rep(i,q){
    ll l,r;
    cin >> l >> r;
    cout << prs[r] - prs[l-1] << endl;
  }
}
