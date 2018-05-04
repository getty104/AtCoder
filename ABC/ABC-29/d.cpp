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

string N;
vector<DVec> memo(12,dvec(2,12,-1));

// flag : 未満フラグ
ll rec(ll now = 0, bool flag = false, ll cnt = 0){
  if(now == N.size())return cnt;
  if(memo[now][flag][cnt] != -1) return memo[now][flag][cnt];

  ll x = N[now] - '0';
  ll r = (flag ? 9 : x);

  ll res = memo[now][flag][cnt];
  res = 0;

  rep(i,r+1){  // now桁目(0-indexed)をiにする
    if(!flag and i==r)res += rec(now+1,false,cnt+(i==1));
    else res += rec(now+1,true,cnt+(i==1));
  }
  memo[now][flag][cnt] = res;
  return res;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> N;
  cout << rec() << endl;
}
