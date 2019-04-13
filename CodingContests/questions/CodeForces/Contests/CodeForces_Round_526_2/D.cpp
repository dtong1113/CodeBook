#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

map<ll, vector<pll> > adj;
map<ll, ll> visited;
vector<ll> gas;
map<ll , int> counts;
ll check(ll from) {
  ll total = gas[from - 1];

  vector<pll>& adja = adj[from];
  priority_queue<ll, vector<ll>> pq;
  for (pll p : adja) {
    ll to = p.first;
    ll cost = p.second;
    if (visited.count(to)) {
      ll gain = visited[to] - cost;
      if (gain > 0) {
        pq.push(gain);
      }
    }
  }
  if (!pq.empty()) {
    total += pq.top();
    pq.pop();
  }
  visited[from] = total;
  if (!pq.empty()) {
    total += pq.top();
    pq.pop();
  }
  return total;
}
int mod = 1e9 + 7;
int main() {
  //ifstream cin("input.txt");
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll g;
    cin >> g;
    gas.push_back(g);
  }

  for (int i = 0; i < n - 1; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    counts[a]++;
    counts[b]++;
  }
  ll val = numeric_limits<long long>::min();
  queue<ll> qq;
  set<ll> queued;
  for (int i = 1; i <= n; i++) {
    if (counts[i] <= 1) {
      qq.push(i);
      queued.insert(i);
    }
  }

  while (!qq.empty()) {
    ll t = qq.front();
    qq.pop();
    ll checked = check(t);
    val = max(val, checked);
    //map<ll, vector<pll> > adj;
    vector<pll>& adja = adj[t];
    for (pll p : adja) {
      counts[p.first]--;
      if (counts[p.first] <= 1 && !queued.count(p.first)) {
        queued.insert(p.first);
        qq.push(p.first);
      }
    }
  }
  /*
  for (auto it = visited.begin(); it != visited.end(); ++it) {
    cout << it-> first << " " << it->second << endl;
  }
  */
  cout << val << endl;

  return 0;
}
