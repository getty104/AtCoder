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
  int n,q;
  cin >> n >> q ;
  vector<int> tmp(n,0);
  int l,r;
  rep(i,q) {
    cin >> l >> r;
    tmp[l-1] += 1;
    tmp[r] -= 1;
  }

  vector<int> chip(n,0);
  chip[0] = tmp[0];
  repl(i,1,n-1)chip[i] = chip[i-1] + tmp[i];
  rep(i,n)cout << chip[i]%2;
  cout << endl;
}
