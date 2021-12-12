#include <bits/stdc++.h>

using namespace std;

ifstream fin("PALINCON.INP");
ofstream fout("PALINCON.OUT");

vector<string> vs;
vector<bool> vb;
vector<int> ans;

bool b, failed;

int n, k;

bool palin(int length, string s1, string s2) {
  for (int i = 0; i < length; i++) {
    if (s1[i] != s2[length - i - 1])
      return false;
  }
  return true;
}

int main() {
  fin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    fin >> s;
    vs.push_back(s);
  }
  vb.resize(n);
  if (n % 2 == 0) {
    for (int i = 0; i < n; i++) {
      b = false;
      if (vb[i])
        continue;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        if (vb[j])
          continue;
        if (!palin(k, vs[i], vs[j]))
          continue;
        b = true;
        vb[i] = true;
        vb[j] = true;
        ans.push_back(i);
        ans.push_back(j);
        break;
      }
      if (b)
        continue;
      fout << "-1";
      return 0;
    }
    for (int i = 0; i < n; i += 2) {
      fout << ans[i] + 1 << " ";
    }
    for (int i = n - 1; i > 0; i -= 2) {
      fout << ans[i] + 1 << " ";
    }
  } else {
    bool reviveMintUsed = false;
    int middle = 0;
    for (int i = 0; i < n; i++) {
      b = false;
      if (vb[i])
        continue;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        if (vb[j])
          continue;
        if (!palin(k, vs[i], vs[j]))
          continue;
        b = true;
        vb[i] = true;
        vb[j] = true;
        ans.push_back(i);
        ans.push_back(j);
        break;
      }
      if (b)
        continue;
      if (!reviveMintUsed) {
        reviveMintUsed = true;
        middle = i;
      } else {
        fout << "-1";
        return 0;
      }
    }
    if (!palin(k, vs[middle], vs[middle])) {
      fout << "-1";
      return 0;
    }
    for (int i = 0; i < n - 1; i += 2) {
      fout << ans[i] + 1 << " ";
    }
    fout << middle + 1 << " ";
    for (int i = n - 2; i > 0; i -= 2) {
      fout << ans[i] + 1 << " ";
    }
  }
}