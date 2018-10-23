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
ll h = 0;
ll binarySearch(vector<ll>& sum, vector<pii>& points, int start, int r) {
  //l, r inclusive

  if (sum[r] - sum[start] + h > points[r].first - points[start].first) {
    return sum[r+1] - sum[start] + h;
  }
  r--;
  int l = start;

  while(l <= r) {
//    cout << l << " " << r << endl;
    int mid = (l + r)/2;
    ll total = sum[mid] - sum[start];
    if (total + h > points[mid].first - points[start].first) {
      int temp = mid + 1;
      if (sum[temp] - sum[start] + h > points[temp].first - points[start].first) {
        l = mid + 1;
      } else {
        return h + sum[mid + 1] - sum[start];
      }

    } else {
      r = mid - 1;
    }
  }
  return -1;
}
int main() {
  int n;

  cin >> n >> h;
  vector<pii> points;
  for (int i = 0; i < n; i++) {
    int x1, x2;
    cin >> x1 >> x2;
    points.pb(mp(x1, x2 - x1));
  }

  vector<ll> sum(n + 1, 0);

  ll total = 0;
  for (int i = 0; i < n; i++) {
    total += points[i].second;
    sum[i+1] = total;
  }

  ll maxi = 0;
  for (int i = 0; i < n; i++) {
    ll score = binarySearch(sum, points, i, n -1);
    maxi = max(maxi, score);
  }

  cout << maxi << endl;

  return 0;
}
