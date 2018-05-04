#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vec;
typedef vector<Vec> DVec;
typedef priority_queue<P, vector<P>, greater<P>> PQ;

#define fi             first
#define se             second
#define pb             push_back
#define INF            UINT_MAX
#define MOD            1000000007
#define bcnt           __builtin_popcount
#define all(x)         (x).begin(),(x).end()
#define uni(x)         x.erase(unique(all(x)),x.end())
#define ub(x,y)        (upper_bound(all(x),y)-x.begin())
#define lb(x,y)        (lower_bound(all(x),y)-x.begin())
#define ssort(x)       sort(all(x))
#define rep(i,n)       repl(i,0,n-1)
#define mkp(x,y)       make_pair(x,y)
#define mmax(x,y)      (x>y?x:y)
#define mmin(x,y)      (x<y?x:y)
#define maxch(x,y)     x=mmax(x,y)
#define minch(x,y)     x=mmin(x,y)
#define exist(x,y)     (find(all(x),y)!=x.end())
#define each(itr,v)    for(auto itr:v)
#define repl(i,a,b)    for(ll i=(ll)(a);i<=(ll)(b);i++)
#define dvec(n1,n2,i)  DVec(n1,Vec(n2,i))

ll K, M;
Vec A(110);
Vec C(110);
DVec B;

DVec matPro(DVec& m1, DVec& m2){
  DVec m = dvec(K,K,0);
  rep(i,K)rep(j,K)rep(k,K)m[i][j] ^= m1[i][k] & m2[k][j];
  return m;
}


void makeB(){
  B = dvec(K,K,0);
  rep(i,K) B[0][i] = C[i];
  repl(i,1,K-1) B[i][i-1] = INF;
}


DVec matProMP(){
  DVec ret;
  M -= K;
  do {
    if(M%2) ret = (!ret.size() ? B : matPro(B, ret));
    B = matPro(B, B);
  } while(M/=2);
  return ret;
}


ll solve(){
  if(M <= K) return A[M-1];
  ll ans = 0;
  DVec BM = matProMP();
  rep(i,K)ans ^= BM[0][i] & A[K-i-1];
  return ans;
}


int main(){
  cin.sync_with_stdio(false);
  cin >> K >> M;
  rep(i,K) cin >> A[i];
  rep(i,K) cin >> C[i];

  makeB();

  cout << solve() << endl;

  return 0;
}
