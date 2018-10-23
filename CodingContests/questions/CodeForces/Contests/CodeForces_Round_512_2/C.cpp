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
  int n;
  cin >> n;
  vi arr;
  arr.resize(n);

  string s;
  cin >> s;
  int total = 0;
  for(int i = 0; i < n; i++) {
    arr[i] = s[i] - '0';
    total += arr[i];
  }

  for(int i = 2; i <= n; i++) {
    if(total % i != 0) {
      continue;
    }

    int target = total/i;
    int curr = 0;
    bool flag = false;
    for(int i = 0; i < n; i++) {
      curr += arr[i];
      if(curr == target) {
        curr = 0;
      }
      if(curr > target) {
        break;
      }
      if(i == n-1) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;

  return 0;
}
