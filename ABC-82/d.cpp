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

string s;
ll x,y;
Vector a,b;
vector< vector<bool> > dp1(2, vector<bool>(20011,false));
vector< vector<bool> > dp2(2, vector<bool>(20011,false));

int main(){
  cin >> s>> x >> y;
  s += "T";
  ll crt = 0,sum = 0;
  each(itr,s){
    if(itr == 'T'){
      if(crt == 0)a.pb(sum);
      else b.pb(sum);
      sum = 0;
      crt = 1 - crt;
    }else{
      sum++;
    }
  }

  crt = 0;
  ll nxt = 1;
  dp1[crt][10000] = true;
  rep(i,a.size()){
    dp1[nxt] = vector<bool>(20011,false);
    rep(j,20001){
      if(!dp1[crt][j])continue;
      if(i == 0){
        if(j+a[i] <= 20000)dp1[nxt][j+a[i]] = true;
      }else{
        if(j+a[i] <= 20000)dp1[nxt][j+a[i]] = true;
        if(j-a[i] >= 0)dp1[nxt][j-a[i]] = true;
      }
    }
    swap(crt,nxt);
  }

  if(!dp1[crt][x+10000]){
    cout << "No" << endl;
    return 0;
  }

  crt = 0;
  nxt = 1;
  dp2[crt][10000] = true;
  rep(i,b.size()){
    dp2[nxt] = vector<bool>(20011,false);
    rep(j,20001){
      if(!dp2[crt][j])continue;
      if(j+b[i] <= 20000)dp2[nxt][j+b[i]] = true;
      if(j-b[i] >= 0)dp2[nxt][j-b[i]] = true;
    }
    swap(crt,nxt);
  }

  if(!dp2[crt][y+10000]){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}
