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
#define MOD         1000000007
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

string s;
ll judge2(){
  rep(i,s.size()-1)if(s[i] == s[i + 1])return i + 1;
  return -1;
}

ll judge3(){
  rep(i,s.size()-2)if(s[i] == s[i + 2])return i + 1;
  return -1;
}


int main(){
  cin.sync_with_stdio(false);
  cin >> s;
  ll j2 = judge2(), j3 = judge3();
  if (j2 >= 0){
    cout << j2 << " " << j2 + 1 << endl;
    return 0;
  }

  if (j3 >= 0) {
    cout << j3 << " " << j3 + 2 << endl;
    return 0;
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}
