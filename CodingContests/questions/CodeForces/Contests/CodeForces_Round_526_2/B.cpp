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

  ll n,s;
  cin >> n >> s;

  vll nums;
  ll total = 0;
  for (int i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    nums.push_back(temp);
    total += temp;
  }
  ll mini = *(min_element(begin(nums), end(nums)));
  if (total < s) {
    cout << -1;
    return 0;
  } else {
    ll t = (total - s)/n;
    cout << min(mini, t);
    return 0;
  }
}
