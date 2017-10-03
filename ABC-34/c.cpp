#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount
#define INF INT_MAX/3
ll mod = pow(10,9)+7;

ll power(ll x, ll n){
  ll tmp = 1;

  if ( n > 0 ){
    tmp = power(x, n/2)%mod;
    if ( n%2 == 0 ) tmp = (tmp*tmp)%mod;
    else tmp = (((tmp*tmp)%mod)*x)%mod;
  }
  return tmp;
}

int main(){
  cin.sync_with_stdio(false);
  ll w,h;
  ll W=1, H=1,WH=1;
  cin >> w >> h;

  repl(i,1,w){
    W*=i;
    W %=mod;
  }

  repl(i,1,h){
    H*=i;
    H %= mod;
  }

  repl(i,1,h+w-1){
    WH*=i;
    WH %= mod;
  }

  cout << WH*power(W*H%mod,mod-2)%mod << endl;
}