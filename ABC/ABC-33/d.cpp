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

double eps=1e-10;

int main(){
  cin.sync_with_stdio(false);
  ll N; cin >> N;
  Vector x(N),y(N);
  rep(i,N)cin >> x[i] >> y[i];

  ll acute_angle = 0;
  ll right = 0;
  rep(i,N){
    vector<double> angles;
    rep(j,N)if(j != i){
        double angle = atan2(y[j] - y[i], x[j]- x[i]);
        angles.pb(angle);
    }
    usort(angles);
    rep(j,N-1)angles.pb(angles[j]+2*M_PI);

    ll k = 0;
    rep(j,N-1){
        while(angles[k+1] - angles[j] < M_PI / 2 - eps)k++;
        acute_angle += k - j;
        if(angles[k+1] - angles[j] < M_PI / 2 + eps)right++;
    }
}

ll all = N * (N - 1) * (N - 2) / 6;
ll obtuse = 3 * all - acute_angle - right;
ll acute = all - right - obtuse;
cout << acute << ' ' << right << ' ' << obtuse << endl;
}
