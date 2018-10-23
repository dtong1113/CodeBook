#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

int mod = 1e9 + 7;
int main() {
  //ifstream cin("input.txt");
  //ofstream cout("out.txt");
  int n, d, m;
  cin >> n >> d;
  cin >> m;

  // x + d, x - d, -x + d, -x + 12
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if((y - x <= d) && (y - x >= (0 - d)) && (y + x >= d) && (y + x <= (2*n - d))) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
