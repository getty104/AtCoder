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
DVector mp(41,Vector(41,INF));
ll a,b;

int main(){
  cin.sync_with_stdio(false);
  cin >> a >> b;
  rep(i,41)mp[i][i] = 0;
  repl(j,1,40){
    repl(i,1,40){
      if(j-i >= 0){
        mp[j][j-i] = i;
        mp[j-i][j] = i;
      }
      if(j+i <= 40){
        mp[j][j+i] = i;
        mp[j+i][j] = i;
      }
    }
  }
  repl(j,1,40){
    repl(i,1,8){
      if(j-5*i >= 0){
        mp[j][j-5*i] = i;
        mp[j-5*i][j] = i;
      }
      if(j+5*i <= 40){
        mp[j][j+5*i] = i;
        mp[j+5*i][j] = i;
      }
    }
  }
  repl(j,1,40){
    repl(i,1,4){
      if(j-10*i >= 0){
        mp[j][j-10*i] = i;
        mp[j-10*i][j] = i;
      }
      if(j+10*i <= 40){
        mp[j][j+10*i] = i;
        mp[j+10*i][j] = i;
      }
    }
  }
  rep(k,41)rep(i,41)rep(j,41)minch(mp[i][j],mp[i][k]+mp[k][j]);
  cout << mp[a][b] << endl;
}
