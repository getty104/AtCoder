#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef pair<ll,P>  PP;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;
typedef priority_queue<PP, vector<PP>, greater<PP>> PPQueue;

#define fi          first
#define se          second
#define sfi         se.fi
#define sse         se.se
#define pb          push_back
#define INF         INT_MAX
#define MOD         1000000007
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define uni(x)      x.erase(unique(all(x)),x.end())
#define ub(x,y)     (upper_bound(all(x),y)-x.begin())
#define lb(x,y)     (lower_bound(all(x),y)-x.begin())
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
string s;

bool same_num(bool ta, char ts){
  return(ta == 0 && ts == 'o' || ta == 1 && ts == 'x');
}

bool judge(Vector &a,ll i){
  if(same_num(a[i],s[i]))return a[(n+i+1)%n] == a[(n+i-1)%n];
  else return a[(n+i+1)%n] != a[(n+i-1)%n];
}

Vector ans;
bool dfs(ll idx, Vector &a){
  if(idx == n-1){
    if(judge(a,n-1) && judge(a,0)){
      ans = a;
      return true;
    }else return false;
  }

  if(same_num(a[idx],s[idx])){
    a[idx+1] = a[idx-1];
    return dfs(idx+1,a);
  }else{
    a[idx+1] = (a[idx-1]+1) % 2;
    return dfs(idx+1,a);
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  cin >> s;
  Vector a(n,-1);
  bool jd = false;
  a[0] = 0;
  a[1] = 0;
  jd = jd || dfs(1,a);
  a[0] = 0;
  a[1] = 1;
  jd = jd || dfs(1,a);
  a[0] = 1;
  a[1] = 0;
  jd = jd || dfs(1,a);
  a[0] = 1;
  a[1] = 1;
  jd = jd || dfs(1,a);

  if(jd){
    rep(i,n)cout << (ans[i] == 0 ? 'S' : 'W');
    cout << endl;
  }else{
    cout << -1 << endl;
  }
}
