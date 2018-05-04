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
#define INF         INT_MAX
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
ll n,a,b;
Vector v;

//// コンビネーション(using double)
double comb(int n,int r){
  if(n<r)return 0.0;
  if(n-r<r)r=n-r;
  double res=1;
  for(int i=0;i<r;i++){
    res*=n;
    n--;
    res/=i+1;
  }
  return res;
}

int main(){
  cin.sync_with_stdio(false);
  cout.precision(20);
  cin >> n >> a >> b;
  v.resize(n);
  rep(i,n)cin >> v[i];
  dsort(v);
  double sum = 0;
  rep(i,a)sum+=v[i];
  cout << fixed << sum/(double)a << endl;

  ll x = 0,y = 0;
  rep(i,n){
    if(v[i] == v[a-1]){
      x++;
      if(i<a)y++;
    }
  }

  ll cnt = 0;
  if(y == a)repl(i,a,b)cnt+= comb(x,i);
  else cnt += comb(x,y);
  cout << cnt << endl;
}
