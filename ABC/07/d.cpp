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

Vec digit{0, 1, 2, 3, 5, 6, 7, 8};

ll calc(string N){
  DVec dp = dvec(N.size()+1,2,0);
  dp[0][1] = 1;
  rep(i, N.size())rep(j, 2){
    if(dp[i][j] == 0)continue;
    ll lim = j ? (N[i] - '0') : 9;
    each(d,digit){
      if(d > lim) break;
      dp[i+1][j && d == lim] += dp[i][j];
    }
  }

  return dp[N.size()][0] + dp[N.size()][1];
}

int main(){
  cin.sync_with_stdio(false);

  ll Al, Bl;
  cin >> Al >> Bl; Al--;
  string A = to_string(Al), B = to_string(Bl);
  ll ans = calc(B) - calc(A);
  ans = (Bl-Al) - ans;
  cout << ans << endl;

  return 0;
}

