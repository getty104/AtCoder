#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
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
int n,k;

bool f(double x, int tn, double *p, double *w){
  double list[tn];
  rep(i,tn)list[i] = (p[i]-x)*w[i];
  sort(list,list+tn);
  reverse(list,list+tn);
  double sum = 0;
  rep(i,k)sum += list[i];
  return (sum >= 0);
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n >> k;
  double p[n];
  double w[n];
  rep(i,n)cin>>w[i]>>p[i];

  double lb=0,ub=100; // 例えば最小化なら、(lbの初期値+1)が解の最小値
for(int i=0;i<100;i++){ // 必ず十分な定数回で打ち切る（実数では誤差死を防げるし、計算量の見積もりが楽）
  double mid=(lb+ub)/2;
  if(f(mid,n,p,w))lb=mid;
  else ub=mid;
}
printf("%.9f\n",lb);
}