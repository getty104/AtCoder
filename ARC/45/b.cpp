#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
    ll N, M;
    cin >> N >> M;
    ll po[N + 1] = {};
    pair<ll, ll> yo[M];
    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        yo[i] = pair<ll, ll>(--a, --b);
        po[a]++;
        po[b + 1]--;
    }
    for(ll i = 0; i < N; i++) po[i + 1] += po[i];
    set<ll> s;
    for(ll i = 0; i < N; i++) if(po[i] == 1) s.insert(i);
    vector<ll> ans;
    for(ll i = 0; i < M; i++){
        auto ite = s.lower_bound(yo[i].first);
        if(ite != s.end() && *ite <= yo[i].second) continue;
        ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for(ll u : ans) cout << u << endl;
    return 0;
}
