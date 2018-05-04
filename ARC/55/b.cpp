#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<double> Vec;
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

// dp[n][k] : 残りn枚からk枚食べることが出来る場合に，最大を食べることが出来る確率
DVec dp;
ll N,K;

double dfs(ll n, ll k){

  //　残りn枚で，k枚食べることができる
  if(dp[n][k]>=0)return dp[n][k];

  // 今までで一番大きいせんべいが現れる確率
  double max_senbei = 1.0/(N-(n-1));
  double taberu = 1.0/N + max_senbei * dfs(n-1,k-1) + (1-max_senbei) * dfs(n-1,k);
  double tabenai=dfs(n-1,k);
  dp[n][k] = mmax(taberu,tabenai);
  return dp[n][k];
}

int main(){
  cin.sync_with_stdio(false);
  cin >> N >> K;
  dp = dvec(N+1,N+1,-1);
  rep(i,N+1){
    dp[i][i]=1.0*i/N;
    dp[i][0]=0;
  }
  cout << setprecision(15) << dfs(N,K) << endl;
  return 0;
}
