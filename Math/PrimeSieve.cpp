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
// returns all primes <= limit
void simpleSieve(int limit, vector<int>& primes) {
  bool arr[limit+1];
  memset(arr, true, sizeof(arr));

  for (int i = 2; i*i <= limit; i++) {
    if (arr[i]) {
      for (int j = i*2; j <= limit; j+=i) {
        arr[j] = false;
      }
    }
  }

  for (int i = 2; i <= limit; i++) {
    if (arr[i]) {
      primes.push_back(i);
    }
  }
}

// returns all primes <= n
// Time Complexity - O(nloglog(n))
// Space Complexity - O(sqrt(n))
vector<int> segmentedSieve(int n) {
  int limit = sqrt(n);
  vector<int> primes;
  simpleSieve(limit, primes);

  vector<int> ret = primes;

  // [l , r)
  int l = limit + 1;
  int r = l + limit;
  while (l <= n) {
    bool arr[r - l];
    memset(arr, true, sizeof(arr));
    for (int i = 0; i < primes.size(); i++) {
      int lo = l/primes[i]*primes[i];
      if (lo < l)
        lo += primes[i];

      for (; lo < r; lo += primes[i]) {
        arr[lo - l] = false;
      }
    }
    for (int i = 0; i < r - l; i++) {
      if (arr[i]) {
        ret.push_back(i + l);
      }
    }
    l += limit;
    r = min(l + limit, n + 1);
  }
  return ret;
}

int main() {
  //ifstream cin("input.txt");
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> primes = segmentedSieve(101);
  for (int prime : primes)
    cout << prime << endl;
  return 0;
}
