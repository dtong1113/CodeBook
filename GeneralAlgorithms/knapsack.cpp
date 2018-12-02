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

// n - # of items
// m - limit
// Time Complexity - O(nm)
// Memory Complexity - O(m)
// y26y
int knapsack(vector<int> profit, vector<int> weight, int maxWeight) {
  int arr[2][maxWeight + 1];

  int* curr = arr[0];
  int* next = arr[1];

  memset(curr, 0, (maxWeight+1)*sizeof(int));

  for (int i = 0; i < profit.size(); i++) {
    for (int j = 0; j <= maxWeight; j++) {
      next[j] = curr[j];
      if (j - weight[i] >= 0) {
        next[j] = max(next[j], curr[j - weight[i]] + profit[i]);
      }
    }
    swap(curr, next);
  }

  int ret = INT_MIN;

  for (int i = 0; i <= maxWeight; i++) {
    ret = max(curr[i], ret);
  }

  return ret;
}
int main() {

  vector<int> val = {60, 100, 120};
  vector<int> wt = {10, 20, 30};
  int  W = 50;
  cout << knapsack(val, wt, W);
  return 0;
}
