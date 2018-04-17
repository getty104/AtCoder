#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef vector<DVec> TVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi                first
#define se                second
#define pb                push_back
#define INF               LLONG_MAX/3
#define MOD               1000000007
#define bcnt              __builtin_popcount
#define all(x)            (x).begin(),(x).end()
#define srt(x)            sort(all(x))
#define rvs(x)            reverse(all(x))
#define uni(x)            x.erase(unique(all(x)),x.end())
#define ub(x,y)           (upper_bound(all(x),y)-x.begin())
#define lb(x,y)           (lower_bound(all(x),y)-x.begin())
#define rep(i,n)          repl(i,0,n-1)
#define mkp(x,y)          make_pair(x,y)
#define mmax(x,y)         (x>y?x:y)
#define mmin(x,y)         (x<y?x:y)
#define maxch(x,y)        x=mmax(x,y)
#define minch(x,y)        x=mmin(x,y)
#define exist(x,y)        (find(all(x),y)!=x.end())
#define each(itr,v)       for(auto itr:v)
#define repl(i,a,b)       for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)     DVec(n1,Vec(n2,i))
#define tvec(n1,n2,n3,i)  TVec(n1,dvec(n2,n3,i))
#define MAX_D 40
#define MAX (ll)1e5+10

DVec pos =  dvec(MAX_D,MAX,0);

int main(){
  cin.sync_with_stdio(false);
  ll N,M,D;
  cin >> N >> M >> D;
  Vec A(M);
  repl(i,1,N)pos[0][i] = i;
  rep(i,M)cin >> A[i];
  rvs(A);
  rep(i,M)swap(pos[0][A[i]], pos[0][A[i]+1]);
  rep(i,MAX_D-1)repl(j,1,N)pos[i+1][j] = pos[i][pos[i][j]];
  Vec tmp;

  for(int i=0; (1<<i) <= D; i++){
    if((D>>i)&1)tmp.push_back(i);
  }

  repl(i,1,N){
    ll k = i;
    rep(j,tmp.size())k = pos[tmp[j]][k];
    cout << k << endl;
  }

  return 0;
}
