#include <bits/stdc++.h>

using namespace std;

ifstream fin("nobridge.inp");
ofstream fout("nobridge.out");

vector<int> vi;

int n, m, u, v, ans;

int main() {
  fin >> n >> m;
  vi.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    fin >> u >> v;
    vi[u]++;
    vi[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (vi[i] < 2)
      ans++;
    if (vi[i] < 1)
      ans++;
  }
  if (ans % 2 == 1)
    ans++;
  fout << ans / 2;
}