#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> Vector;
typedef vector<vector<ll>> DVector;

#define fi          first
#define se          second
#define pb          push_back
#define INF         INT_MAX/3
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define dbg(x)      cout<<#x"="<<x<<endl
#define ub(x,y)     upper_bound(all(x),y)-x.begin()
#define lb(x,y)     lower_bound(all(x),y)-x.begin()
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

int main(){
  cin.sync_with_stdio(false);
  ll n,d,k;
  cin >> n >> d >> k;
  Vector l(d),r(d),s(k),t(k);
  vector<bool> re(k,false);
  rep(i,d){
    int l1,r1;
    cin >> l1 >> r1;
    l[i] = l1 - 1;
    r[i] = r1 - 1;
  }

  rep(i,k){
    int l1,r1;
    cin >> l1 >> r1;
    s[i] = l1 - 1;
    t[i] = r1 - 1;
    if(l1 > r1)re[i]=true;
  }
  Vector ans(k,-1);
  rep(i,d)rep(j,k){
    if(s[j] >= l[i] && s[j] <= r[i]){
      if(re[j])s[j] = l[i];
      else       s[j] = r[i];
      if(ans[j] == -1)if( (re[j] && s[j] <= t[j]) || (!re[j] && s[j] >= t[j]) ) ans[j] = i+1;
    }
  }
  rep(i,k)cout << ans[i] << endl;
}
