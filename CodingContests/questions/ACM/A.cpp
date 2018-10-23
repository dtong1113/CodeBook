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
  int N;
  cin >> N;
  vector<bool> seen(N, false);
  for(int i = 0; i < N - 1; i++) {
    int temp;
    cin >> temp;
    seen[temp-1] = true;
  }

  for(int i = 0; i < N; i++) {
    if(!seen[i]) {
      cout << i + 1 << endl;
    }
  }
}
