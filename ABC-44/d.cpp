#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef pair<ll,P>  PP;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;
typedef priority_queue<PP, vector<PP>, greater<PP>> PPQueue;

#define fi          first
#define se          second
#define sfi         se.fi
#define sse         se.se
#define pb          push_back
#define INF         1000000000000
#define MOD         1000000007
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define uni(x)      x.erase(unique(all(x)),x.end())
#define ub(x,y)     (upper_bound(all(x),y)-x.begin())
#define lb(x,y)     (lower_bound(all(x),y)-x.begin())
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

ll f(ll b, ll n){
  if(n < b)return n;
  else return f(b,n/b) + (n % b);
}

int main(){
  cin.sync_with_stdio(false);
  ll n,s;
  cin >> n >> s;
  ll ab = INF;
  if(s < n){
    repl(b,2,sqrt(n))if(s == f(b,n))minch(ab,b);
    for(ll p = sqrt(n); p >= 1; p--){
      if((n - s) >= p || (n - s) % p == 0){
        ll b = (n - s)/p + 1;
        if(s == f(b,n))minch(ab,b);
      }
    }
  }else if(s == n){
    ab = n + 1;
  }
  cout << (ab == INF ? -1 : ab) << endl;
}
