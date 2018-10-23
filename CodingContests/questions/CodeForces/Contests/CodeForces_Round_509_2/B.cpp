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
ll gcd(ll a, ll b) {
  if (a == 0) return b;

  return gcd(b%a, a);
}
int main() {
  ll w, h, x, y;
  // w/h = x/y
  cin >> w >> h >> x >> y;

  ll gc = gcd(x, y);
  x = x/gc;
  y = y/gc;

  ll poss = w/x;
  poss = min(poss, h/y);

  cout << poss << endl;


  //ifstream cin("input.txt");
  //ofstream cout("out.txt");
  return 0;
}
