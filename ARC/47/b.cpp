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

ll X[101010],Y[101010];
ll XX[101010],YY[101010];

int main(){
  cin.sync_with_stdio(false);
  ll N; cin>>N;
  ll maX = -INF, miX = INF;
  ll maY = -INF, miY = INF;
  rep(i,N){
    cin>>X[i]>>Y[i];
    XX[i]=X[i]+Y[i];
    YY[i]=X[i]-Y[i];
    maxch(maX,XX[i]);
    minch(miX,XX[i]);
    maxch(maY,YY[i]);
    minch(miY,YY[i]);
  }
  ll D = mmax(maX-miX,maY-miY);
  Vec Px,Py;
  Px.pb(maX-D/2);
  Px.pb(D/2+miX);
  Py.pb(maY-D/2);
  Py.pb(D/2+miY);
  ll a,b;
  rep(i,2)rep(j,2){
    ll a = (Px[i]+Py[j])/2, b = (Px[i]-Py[j])/2;
    bool flag = 1;
    ll x = abs(a-X[0]) + abs(b-Y[0]);
    rep(k,N-1){
      if(abs(a-X[k+1])+abs(b-Y[k+1])!=x){
        flag=0;
        break;
      }
    }
    if(flag){
      cout << a << " " << b << endl;
      return 0;
    }
  }
  return 0;
}
