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
#define each(itr,v)    for(auto& itr:v)
#define repl(i,a,b)    for(int i=(int)(a);i<=(int)(b);i++)
#define dvec(n1,n2,i)  DVec(n1,Vec(n2,i))

const ll MOD = (ll)10e9 + 7;
vector<int> none;
int a[25], pos[25];
ll dp[1 << 25];

void f(int s, int t) {
  int y = t / 5, x = t % 5;
  if(s & (1 << t))return;
  if(y > 0 && y < 4 && ((s >> (t - 5)) ^ (s >> (t + 5))) & 1)return;
  if(x > 0 && x < 4 && ((s >> (t - 1)) ^ (s >> (t + 1))) & 1)return;
  (dp[s | (1 << t)] += dp[s]) %= MOD;
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(false);
  fill(pos,pos+25,-1);

  for(int i = 0; i < 25; i++) {
    cin >> a[i];
    a[i]--;
    if(a[i] < 0)none.pb(i);
    else pos[a[i]] = i;
  }

  dp[0] = 1;
  for(int i = 0; i < 1 << 25; i++){
    if(!dp[i])continue;
    int bit = bcnt(i);
    if(pos[bit] >= 0)f(i, pos[bit]);
    else for(auto& j : none)f(i, j);
  }
  cout << dp[(1 << 25) - 1] << endl;

  return 0;
}
