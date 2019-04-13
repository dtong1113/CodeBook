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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  vi nums;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }

  int mini = INT_MAX;

  for (int i = 1; i <= n; i++) {
    int total = 0;
    for (int j = 1; j <= n; j++) {
      int cost = abs(j - i) + j - 1 + i - 1;
      cost *= 2;
      total += cost*nums[j-1];
      //cout << i << " " << j << " " << cost << endl;
    }
    mini = min(mini, total);
  }
  cout << mini;

  return 0;
}
