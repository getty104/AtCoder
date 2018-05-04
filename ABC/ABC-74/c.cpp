#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<double> Vector;
typedef vector<vector<ll>> DVector;

#define fi          first
#define se          second
#define pb          push_back
#define INF         INT_MAX/3
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define dbg(x)      cout<<#x"="<<x<<endl
#define ub(x,y)     upper_bound(all(x),y)
#define lb(x,y)     lower_bound(all(x),y)
#define uni(x)      x.erase(unique(all(x)),x.end())
#define rep(i,n)    repl(i,0,n-1)
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define mmax(x,y)   (x>y?x:y)
#define mmin(x,y)   (x<y?x:y)
#define maxch(x,y)  x=mmax(x,y)
#define minch(x,y)  x=mmin(x,y)
#define exist(x,y)  (find(all(x),y)!=x.end())
#define each(itr,v) for(auto itr:v)
#define usort(x)    sort(all(x))
#define dsort(x)    sort(all(x),greater<int>())
#define mkp(x,y)    make_pair(x,y)

double per(int water, int suger){
  return double(suger*100)/double(water+suger);
}

int main(){
  cin.sync_with_stdio(false);
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  int mw=-INF,ms=0;
  rep(i,30)rep(j,30)rep(k,3000){
    if(i == 0 && j == 0 )break;
    int water = (a * i + b * j) * 100;
    int suger = c*k + mmax(0, mmin((((water/100)*e-c*k)/d)*d,((f-water-c*k)/d)*d));
    if(water+suger > f || suger > (water/100)*e)continue;
    if(per(mw,ms)<per(water,suger)){
      mw = water;
      ms = suger;
    }
  }
  if( mw==-INF )mw =100*a;
  cout << mw+ms << " " << ms << endl;
}
