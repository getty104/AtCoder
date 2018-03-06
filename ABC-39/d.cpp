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

Vector dy{0, 0, 1, -1, 1, 1, -1, -1,0};
Vector dx{1, -1, 0, 0, 1, -1, -1, 1,0};

ll h,w;
vector<string> s(300), ans(300);
bool next_white(ll i,ll j) {
  bool ret = false;
  rep(k,9){
    ll x = i + dx[k];
    ll y = j + dy[k];
    if((0 <= x && x < h && 0 <= y && y < w) && s[x][y] == '.' )ret = true;
  }
  return ret;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> h >> w;

  rep(i,h)cin >> s[i];

  rep(i,h)rep(j,w){
    if(s[i][j] == '.'){
      ans[i][j] = '.';
    }else if(next_white(i,j)){
      bool f = true;
      rep(k,8){
        ll x = i + dx[k];
        ll y = j + dy[k];
        if((0 <= x && x < h && 0 <= y && y < w) && s[x][y] == '#' && !next_white(x,y)){
          f = false;
          break;
        }
      }
      if(f){
        cout << "impossible" << endl;
        return 0;
      }
      ans[i][j] = '.';
    }else ans[i][j] = '#';
  }
  cout << "possible" << endl;

  rep(i,h){
    rep(j,w)cout << ans[i][j];
    cout << endl;
  }
  return 0;
}
