#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;

#define fi          first
#define se          second
#define pb          push_back
#define INF         INT_MAX
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define dbg(x)      cout<<#x"="<<x<<endl
#define uni(x)      x.erase(unique(all(x)),x.end())
#define ub(x,y)     upper_bound(all(x),y)-x.begin()
#define lb(x,y)     lower_bound(all(x),y)-x.begin()
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
ll n;
ll N = 3;
DVector b(N-1,Vector(N,0));
DVector c(N,Vector(N-1,0));

ll score(DVector mp){
  ll sum1 = 0;
  rep(i,N)rep(j,N){
    if(i < N -1){
      if(mp[i][j] == mp[i+1][j])sum1 += b[i][j];
    }
    if(j < N-1){
      if(mp[i][j] == mp[i][j+1])sum1 += c[i][j];
    }
  }
  return sum1;
}

ll dfs(ll ct, DVector mp){
  if(ct == 9)return score(mp);
  else if(ct % 2 == 0){
    ll mx = -1;
    rep(i,N)rep(j,N){
      if(mp[i][j] != -1)continue;
      mp[i][j] = 1;
      ll r = dfs(ct+1,mp);
      maxch(mx,r);
      mp[i][j] = -1;
    }
    return mx;
  }else{
    ll mn = INF;
    rep(i,N)rep(j,N){
      if(mp[i][j] != -1)continue;
      mp[i][j] = 2;
      ll r = dfs(ct+1,mp);
      minch(mn,r);
      mp[i][j] = -1;
    }
    return mn;
  }
}

int main(){
  cin.sync_with_stdio(false);
  DVector mp(N,Vector(N,-1));
  ll sum = 0;
  rep(i,2)cin >> b[i][0] >> b[i][1] >> b[i][2];
  rep(i,3)cin >> c[i][0] >> c[i][1];
  rep(i,N-1)rep(j,N)sum+=b[i][j];
  rep(i,N)rep(j,N-1)sum+=c[i][j];
  ll r = dfs(0,mp);
  cout << r << endl;
  cout << sum - r << endl;
}
