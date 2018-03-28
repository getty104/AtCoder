#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = (ll)1e9 + 7;
vector<int> none;
int a[25], pos[25];
ll dp[1 << 25];

void f(int s, int t) {
  int y = t / 5, x = t % 5;
  if (s & (1 << t)) return;
  if (y > 0 && y < 4 && ((s >> (t - 5)) ^ (s >> (t + 5))) & 1) return;
  if (x > 0 && x < 4 && ((s >> (t - 1)) ^ (s >> (t + 1))) & 1) return;
  (dp[s | (1 << t)] += dp[s]) %= mod;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  fill(pos, pos + 25, -1);
  for (int i = 0; i < 25; i++) {
    cin >> a[i];
    a[i]--;
    if (a[i] < 0) none.push_back(i);
    else pos[a[i]] = i;
  }

  dp[0] = 1;
  for (int i = 0; i < 1 << 25; i++) {
    if (!dp[i]) continue;
    int bit = __builtin_popcount(i);
    if (pos[bit] >= 0) {
      f(i, pos[bit]);
    } else {
      for (auto& j : none) {
        f(i, j);
      }
    }
  }
  cout << dp[(1 << 25) - 1] << endl;

  return 0;
}
