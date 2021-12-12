#include <bits/stdc++.h>

using namespace std;

ifstream fin("distraction.inp");
ofstream fout("distraction.out");

vector<bool> taken; // table taken?

vector<pair<int, int>> v;

vector<int> pos; // guest position aka guest table number
vector<int> distraction;

int t, m, n;

int main() {
  fin >> t >> m >> n; // t: time, m: table, n: guest
  for (int i = 0; i < n; i++) {
    int a, b;
    fin >> a >> b;
    v.push_back({a, b});
  }

  taken.resize(2 * m);
  pos.resize(n);

  // simulate table taken
  for (int i = 0; i < m; i++) { // i: predicate/candidate
    // simulate time
    int distract = 0;
    for (int j = 1; j <= t; j++) { // j: time
      // garbage collector (table taken => empty)
      for (int k = 0; k < n; k++) {
        if (v[k].second == j) {
          taken[pos[k]] = false;
        }
      }
      // GET IN THE TABLE (table empty => taken)
      for (int k = 0; k < n; k++) {
        if (v[k].first == j) {
          for (int l = 0; l < 2 * m; l++) {
            if (l == i || taken[l])
              continue;
            pos[k] = l;
            taken[l] = true;
            break;
          }
        }
      }
      if (taken[m + i])
        distract++;
    }
    distraction.push_back(distract);
  }
  pair<int, int> ans = {distraction[0], 1};
  for (int i = 0; i < m; i++) {
    if (distraction[i] < ans.first)
      ans = {distraction[i], i + 1};
  }
  fout << ans.first << " " << ans.second;
}