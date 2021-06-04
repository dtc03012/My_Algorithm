/**
 *    author:  tourist
 *    created: 24.01.2021 19:05:39       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, r, g, b;
    cin >> n >> m >> r >> g >> b;
    char cr = 'R';
    char cg = 'G';
    char cb = 'B';
    if (r > g) swap(r, g), swap(cr, cg);
    if (r > b) swap(r, b), swap(cr, cb);
    if (g > b) swap(g, b), swap(cg, cb);
    // r <= g <= b
    vector<string> s(n, string(m, cb));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == 0 && g > 0) {
          s[i][j] = cg;
          g -= 1;
        }
        if ((i + j) % 2 == 1 && r > 0) {
          s[i][j] = cr;
          r -= 1;
        }
      }
    }
    assert(r == 0 && g == 0);
    for (int i = 0; i < n; i++) {
      cout << s[i] << '\n';
    }
  }
  return 0;
}