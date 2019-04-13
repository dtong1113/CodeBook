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

  string s;
  cin >> s;

  ll total = 0;
  ll counter = 0;
  for (char c : s) {
    if (c == 'a') {
      counter ++;
    }
    if (c == 'b') {
      if (counter != 0) {
        total += counter*total;
        total %= mod;
        total += counter;
        total %= mod;
        counter = 0;
      }
    }
  }
  if (counter != 0) {
    total += counter*total;
    total %= mod;
    total += counter;
    total %= mod;
    counter = 0;
  }
  cout << total << endl;
  return 0;
}
