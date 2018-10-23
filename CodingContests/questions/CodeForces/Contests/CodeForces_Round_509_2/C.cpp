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
  int n, length, d;
  cin >> n >> length >> d;

  vector<int> res(n, 0);

  map<int, int> num2idx;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    num2idx[temp] = i;
  }

  int counter = 0;
  while (!num2idx.empty()) {
    counter ++;
    int cur = INT_MIN;

    bool flag = true;
    while (flag == true) {
      auto it = num2idx.find(cur);
      if (it != num2idx.end()) {
        cur = cur + d + 1;
        res[it->second] = counter;
        num2idx.erase(it);
      } else {
        num2idx[cur] = -1;
        auto it = num2idx.find(cur);
        auto it1 = it++;
        if (it != num2idx.end()) {
          cur = it->first + d + 1;
          res[it->second] = counter;
          num2idx.erase(it);
        } else {
          flag = false;
        }
        num2idx.erase(it1);
      }
    }
  }
  cout << counter << endl;
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << endl;


  return 0;
}
