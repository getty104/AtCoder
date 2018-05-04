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

string s[100];
char ans[100][105];
bool ok[100][100];
int H,W;

bool all_black(int y,int x){
  bool f = true;
  repl(dy, -1,1)repl(dx,-1,1){
    ll ny = y + dy,nx = x + dx;
    if(ny < 0 || ny >= H || nx < 0 || nx >= W)continue;
    if(s[ny][nx] == '.'){
      f=false;
      break;
    }
  }
  return f;
}

signed main(){
  cin.sync_with_stdio(false);
  cin >> H >> W;
  rep(i,H)cin>>s[i];
  rep(y,H)rep(x,W)ans[y][x]='.';
  rep(y,H)rep(x,W){
    if(s[y][x]=='.')continue;
    if(all_black(y,x)){
      ans[y][x]='#';
      repl(dy,-1,1)repl(dx,-1,1){
        ll ny = y + dy, nx = x + dx;
        if(ny < 0 || ny >= H || nx < 0 || nx >= W)continue;
        ok[ny][nx]=true;
      }
    }
  }

  rep(y,H)rep(x,W){
    if(s[y][x]=='#' && !ok[y][x]){
      cout<<"impossible"<<endl;
      return 0;
    }
  }

  cout<<"possible"<<endl;
  rep(y,H){
    rep(x,W)cout<<ans[y][x];
    cout<<endl;
  }
}
