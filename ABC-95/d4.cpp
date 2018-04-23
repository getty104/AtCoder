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


int main(){
  cin.sync_with_stdio(false);
  ll n,m,w,h,r,l;
  ll mv=0,c,suma=0,sumb=0;
  cin >> n >> c;
  Vec v(n+2,0),x(n+2,0),rv(n+2,0),lv(n+2,0),frv(n+2,0),dnum(n+2,0);
  x[n+1]=c;
  repl(i,1,n) cin >> x[i] >> v[i];
  repl(i,1,n){
    suma+=v[i];
    sumb+=v[n+1-i];
    rv[i]=suma-x[i];
    if(rv[i]>frv[i-1]){
      frv[i]=rv[i];
      dnum[i]=i;
    }
    else{
      frv[i]=frv[i-1];
      dnum[i]=dnum[i-1];
    }
    lv[i]=max(lv[i-1],sumb-c+x[n+1-i]);
  }
  rep(i,n+1)mv=mmax(mv,lv[i]+frv[n-i]-mmin(c-x[n+1-i],x[dnum[n-i]]));
  cout << mv << endl;

  return 0;
}
