#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define rep(i,n) repl(i,0,n-1)
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

#define INF INT_MAX

int main(){
  cin.sync_with_stdio(false);
  priority_queue<int,vector<int>,greater<int> > qmin;
  priority_queue<int> qmax;

  int n;
  cin >> n;
  ll a[3*n];
  ll b[n+1];
  ll c[n+1];
  b[0] = 0;
  c[n] = 0;
  rep(i,3*n)cin>>a[i];
  rep(i,n){
    qmax.push(a[3*n-1-i]);
    qmin.push(a[i]);
    b[0] += a[i];
    c[n] += a[3*n-1-i];
  }
  ll tmp;
  repl(i,n,2*n-1){
    qmin.push(a[i]);
    tmp = qmin.top();
    qmin.pop();
    b[i-n+1] = b[i-n]+a[i]-tmp;
  }

  for(auto i=2*n-1;i>=n;i--){
    qmax.push(a[i]);
    tmp = qmax.top();
    qmax.pop();
    c[i-n] = c[i-n+1]+a[i]-tmp;
  }
  ll t= -1e14;
  rep(i,n+1){
    if(t<=b[i]-c[i])t=b[i]-c[i];
  }
  cout << t << endl;
}