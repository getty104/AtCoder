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

ll calc(ll x, ll num) {
  if (x + num - 1 <= 0)return (-x -x - num + 1) * num / 2;
  if (x >= 0)return (x + (x + num - 1)) * num / 2;
  ll right = x + num - 1;
  return -x * (-x + 1) / 2 + right * (right + 1) / 2;
}

int main(void){
  cin.sync_with_stdio(false);
  ll R, G, B;
  cin >> R >> G >> B;
  ll ans = INF;

  repl(i,-500,500)repl(j,i + R,500)repl(k,j + G,500)
    minch(ans,calc(i+100,R)+calc(j,G)+calc(k-100,B));

  cout << ans << endl;
  return 0;
}

