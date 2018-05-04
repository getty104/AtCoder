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
int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> p(n);
  int m = 0;
  int sum = 0;
  rep(i,n){
    cin >> s[i] >> p[i];
    if(p[m] < p[i])m=i;
    sum += p[i];
  }
  if(p[m] >= sum/2 +1)cout << s[m] << endl;
  else cout << "atcoder" << endl;
}
