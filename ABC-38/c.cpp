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
ull c(int n,int r,int dup){
    int i,j,nn;
    ull* a=(ull*)calloc(n,sizeof(ull));
    ull retv;
    nn=(dup)?(n+r-1): n;
    if(nn-r<r) r=nn-r;
    if(r==0) return 1; if(r==1) return nn;
    for(i=1;i<r;i++) a[i]=i+2;
    for(i=3;i<=nn-r+1;i++){
        a[0]=i;
        for(j=1;j<r;j++) a[j]+=a[j-1];
    }
    retv = a[r-1];
    free(a);
    return retv;
}

int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  int a[n];
  ull ans=0;
  rep(i,n)cin>>a[i];
  int count = 1;
  repl(i,1,n-1){
    if(a[i]>a[i-1])count++;
    else{
      ans += c(count,2,1);
      count = 1;
    }
  }
  ans += c(count,2,1);
  cout<<ans<<endl;

}