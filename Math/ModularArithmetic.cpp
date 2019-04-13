#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

ll mod = 1e9 + 7;

map<int, long long> fmap;

long long factorial(int a) {

  fmap[0] = 1;

  if (fmap.count(a)) { return fmap[a];
  }

  int largest = fmap.rbegin()->first;
  long long res = fmap.rbegin()->second;

  for (int i = largest + 1; i <= a; i++) {
    res *= i;
    res %= mod;
    fmap[i] = res;
  }

  return res;
}

// Iterative Function to calculate (x^y)%p  in O(log y)
long long power(long long x, long long y, long long p) {
  long long res = 1;

  x = x % p;

  while (y > 0)
  {
    if (y & 1)
      res = (res*x) % p;

    y = y>>1;
    x = (x*x) % p;
  }
  return res;
}


// Returns n^(-1) mod p when p is prime
// Uses Fermat's Little Theorem
// Runs in O(log p)
long long modInversePrime(long long n, long long p) {
  return power(n, p-2, p);
}

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

// returns nCk % p
long long choose(int n, int k, int p = 1e9 + 7) {
  if (k == 0)
    return 1;

  return (factorial(n) * modInverse(factorial(k), p) % p * modInversePrime(factorial(n - k), p) % p) % mod;

}
long long chooseMod1(int n, int k, int p = 1e9 + 7) {
  if (k == 0)
    return 1;

  return (factorial(n) * modInverse(factorial(k), p) % p * modInverse(factorial(n - k), p) % p) % mod;

}

int main() {
  cout << factorial(3) << endl;
  cout << factorial(5) << endl;
  cout << choose(5, 2) << endl;
  cout << choose(500 , 200) << endl;
  cout << choose1(500 , 200) << endl;
  return 0;
}
