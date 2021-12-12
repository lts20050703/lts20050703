#include <bits/stdc++.h>

using namespace std;

ifstream fin("majornum.inp");
ofstream fout("majornum.out");

vector<int> a; // what number it is, how many times it appear

int n, m, r, l;

int input() {
  int i;
  fin >> i;
  return i;
}

int main() {
  fin >> n >> m;
  for (int i = 0; i < n; i++) {
    a.push_back(input());
  }
  for (int i = 0; i < m; i++) {
    fin >> l >> r;
    vector<int> num, rep;
    for (int j = l - 1; j < r; j++) {
      bool found = false;
      for (int k = 0; k < num.size(); k++) {
        if (a[j] == num[k]) {
          rep[k]++;
          found = true;
          break;
        }
      }
      if (!found) {
        num.push_back(a[j]);
        rep.push_back(1);
      }
    }
    sort(rep.begin(), rep.end());
    if (rep[rep.size() - 1] > rep[rep.size() - 2])
      fout << "1\n";
    else
      fout << "0\n";
  }
}