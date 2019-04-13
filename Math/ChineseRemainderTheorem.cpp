#include <bits/stdc++.h>

using namespace std;


long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }

  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);

  *x = y1 - (b / a) * x1;
  *y = x1;

  return gcd;
}
// Returns n^(-1) mod p when n, p are co-prime
// Uses Extended Euclidean Algorithm
// Runs in O(log(p))
long long modInverse(long long n, long long p) {
  long long x, y;

  long long g = gcdExtended(n, p, &x, &y);
  if (g != 1) {
    cout << "ERROR NO INVERSE" << endl;
    return -1;
  } else {
    return (x % p + p) % p;
  }
}

// Returns the smallest x such that x % num[i] == rem[i] for all i
// Uses Chinese Remainder Theorem
// Runs in O(nlog(m)) were n = num.size() and m = product of num
long long crt(const vector<long long>& num, const vector<long long>&  rem) {
  long long prod = 1;
  for (int i = 0; i < num.size(); i++) {
    prod *= num[i];
  }

  long long res = 0;

  for (int i = 0; i < num.size(); i++) {
    long long pp = prod / num[i];
    long long val = rem[i] * modInverse(num[i], pp) * pp;
    res += rem[i] * modInverse(pp, num[i]) * pp;
  }

  return res % prod;
}

int main() {
  vector<long long> num {3, 4, 5};
  vector<long long> rem {2, 3, 1};

  cout << crt(num, rem) << endl;
}
