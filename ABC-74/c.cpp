#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define rep(i,n) repl(i,0,n-1)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

double per(int water, int suger){
return double(suger*100)/double(water+suger);
}

int main(){
  cin.sync_with_stdio(false);
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  int p = double(e*100)/double(e+100);
  int w = mmin(a,b)*100;
  int s = mmin(c,d);
  int aw = w;
  while(per(aw,s) > p){
    aw += w;
  }
  if(aw+s > f)cout << w << " " << 0 << endl;
  else cout << aw+s << " " << s << endl;
}
