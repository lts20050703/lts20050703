#include <bits/stdc++.h>

using namespace std;

ifstream fin("seladd.inp");
ofstream fout("seladd.out");

long long n, q, k, l, r, x, b, ans, a[100001], t[6];

int main() {
  fin >> n >> q >> k;
  for (long long ll = 0; ll < n; ll += 1) {
    fin >> x;
    a[ll] = x;
    ans += x;
  }
  for (long long ll = 0; ll < k; ll += 1) {
    fin >> x;
    t[ll] = x;
  }
  for (long long l1 = 0; l1 < q; l1 += 1) {
    fin >> l >> r >> x;
    for (long long l2 = l - 1; l2 < r; l2 += 1) {
      b = false;
      for (long long l3 = 0; l3 < k; l3 += 1)
        if (a[l2] == t[l3])
          b = true;
      if (!b) {
        a[l2] += x;
        ans += x;
      }
    }
    fout << ans << "\n";
  }
}
