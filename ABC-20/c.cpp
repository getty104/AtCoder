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
typedef tuple<ll,int,int> p;
int h,w,startx,starty,goalx,goaly;
ll t;
vector<string> board(12);
int dy[]={1,0,0,-1};
int dx[]={0,1,-1,0};

bool judge(int mid){
  priority_queue<p,vector<p>,greater<p> > q;
  DVector d(10,Vector(10,1000000001));
  q.push(p(0,starty,startx));
  d[starty][startx] = 0;
  while(!q.empty()){
    ll cost;
    ll cx,cy;
    tie(cost,cy,cx)=q.top();
    q.pop();
    rep(i,4){
      ll nx = cx+dx[i],ny = cy+dy[i];
      if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      ll nc;
      if(board[ny][nx]=='#')nc = mid;
      else nc=1;
      if(d[ny][nx] > cost+nc){
        d[ny][nx]=cost+nc;
        q.push(p(cost+nc,ny,nx));
      }
    }
  }
  return d[goaly][goalx] <= t;
}

int main(int argc,char const* argv[]){
  cin >> h >> w >> t;
  rep(i,h){
    cin >> board[i];
    rep(j,w){
      if(board[i][j] == 'S'){
        startx = j;
        starty = i;
      }
      else if(board[i][j] == 'G'){
        goalx = j;
        goaly = i;
      }
    }
  }
  ll left = 1,right = t;
  while(right - left > 1){
    ll middle = (left + right)/2;
    if(judge(middle))left=middle;
    else right=middle;
  }
  cout << left << endl;
}
