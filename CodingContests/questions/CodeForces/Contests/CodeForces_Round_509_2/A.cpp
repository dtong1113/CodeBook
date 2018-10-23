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

  int mini= INT_MAX, maxi = INT_MIN;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mini = min(t, mini);
    maxi = max(t, maxi);
  }
  cout << maxi - mini + 1 - n << endl;
  return 0;
}
