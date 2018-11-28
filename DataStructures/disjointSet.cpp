#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

// y38y
class DisjointSet {
  vector<int> ds;
public:
  DisjointSet(int n): ds(vector<int>(n, -1)) {}

  int root(int n) {
    while (ds[n] != -1) {
      if (ds[ds[n]] != -1) {
        ds[n] = ds[ds[n]];
      }
      n = ds[n];
    }
    return n;
  }

  void join(int a, int b) {
    int rootA = root(a);
    int rootB = root(b);

    if (rootA == rootB) return;
    ds[rootA] = rootB;
    return;
  }

  bool isConnected(int a, int b) {
    return root(a) == root(b);
  }

  int numSets() {
    int counter = 0;
    for (int idx : ds) {
      if (idx == -1) {
        counter++;
      }
    }
    return counter;
  }
};

int main() {

  DisjointSet ds(500);

  ds.join(1, 2);
  ds.join(3, 4);

  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      cout << ds.isConnected(i, j) << endl;
    }
  }


  return 0;
}
