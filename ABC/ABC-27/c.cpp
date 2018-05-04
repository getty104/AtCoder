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
ll n;
ll depth = 0;
bool dfs(ll num, ll count){
  if(num > n) return false;
  else if(depth % 2 == 0){
    if(count % 2 == 0)return !dfs(num*2,count+1);
    else if(count % 2 == 1)return !dfs(num*2+1,count+1);
  }
  else if(depth % 2 == 1){
    if(count % 2 == 0)return !dfs(num*2+1,count+1);
    else if(count % 2 == 1)return !dfs(num*2,count+1);
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  for(ll m = n;m > 0;m /=2)depth++ ;
  cout << (dfs(1,0) ? "Aoki" : "Takahashi") << endl;
}
