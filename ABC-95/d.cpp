#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi             first
#define se             second
#define pb             push_back
#define INF            LLONG_MAX/3
#define MOD            1000000007
#define bcnt           __builtin_popcount
#define all(x)         (x).begin(),(x).end()
#define uni(x)         x.erase(unique(all(x)),x.end())
#define ub(x,y)        (upper_bound(all(x),y)-x.begin())
#define lb(x,y)        (lower_bound(all(x),y)-x.begin())
#define ssort(x)       sort(all(x))
#define rep(i,n)       repl(i,0,n-1)
#define mkp(x,y)       make_pair(x,y)
#define mmax(x,y)      (x>y?x:y)
#define mmin(x,y)      (x<y?x:y)
#define maxch(x,y)     x=mmax(x,y)
#define minch(x,y)     x=mmin(x,y)
#define exist(x,y)     (find(all(x),y)!=x.end())
#define each(itr,v)    for(auto itr:v)
#define repl(i,a,b)    for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)  DVec(n1,Vec(n2,i))

int main(){
  cin.sync_with_stdio(false);
  ll n,c;
  cin >> n >> c;
  vector<P> xv(n+1);
  xv[0] = mkp(0,0);
  repl(i,1,n)cin >> xv[i].fi >> xv[i].se;
  ll sum = 0;
  ll cnt = 0;
  vector<bool> ct(n+1,false);
  ct[0]=true;
  while(true){
    bool check = true;
    ll mx = 0;
    ll idx = cnt;
    repl(i,1,n){
      ll s1 = ct[i] ? -1 : xv[i].se -  min(abs(xv[cnt].fi-xv[i].fi),c-abs(xv[i].fi-xv[cnt].fi));
      ll s2 = ct[n-i] ? -1 : xv[n-i].se -  min(abs(xv[cnt].fi-xv[n-i].fi),c-abs(xv[n-i].fi-xv[cnt].fi));
      if(s1 >= 0 || s2 >= 0){
        check = false;
        if(s1 >= s2){
          mx = s1;
          idx = i;
        }else{
          mx = s2;
          idx = n-i;
        }
        break;
      }
    }
    if(check)break;
    sum += mx;
    cnt = idx;
    ct[cnt] = true;
  }
  cout << sum << endl;
  return 0;
}
