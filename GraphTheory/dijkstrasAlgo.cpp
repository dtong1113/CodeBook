#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

// y40y
class DijkstrasAlgo {
public:
  // graph[from][idx] = {cost, to}
  vector<vector<pii>> graph;
  vector<int> dist;

  DijkstrasAlgo(int nodes) {
    graph.resize(nodes + 1);
  }

  void addEdge(int from, int to, int cost, bool bidir=false) {
    graph[from].push_back({cost, to});
    if (bidir) graph[to].push_back({cost, from}); }

  void compute(int source) {
    dist.assign(graph.size(), INT_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, source});

    while (!pq.empty()) {
      pii curr = pq.top();
      pq.pop();

      for (pii edge : graph[curr.second]) {
        if (dist[curr.second] + edge.first < dist[edge.second]) {
          dist[edge.second] = dist[curr.second] + edge.first;
          pq.push({dist[edge.second], edge.second});
        }
      }
    }

  }

  int distanceTo(int dest) {
    return dist[dest];
  }
};

int main() {
  DijkstrasAlgo dijk(10);
  dijk.addEdge(1, 2, 3);
  dijk.addEdge(1, 3, 6);
  dijk.addEdge(2, 3, 2);

  int source = 1;
  dijk.compute(source);

  cout << dijk.distanceTo(3) << endl;
  cout << dijk.distanceTo(2) << endl;
  cout << dijk.distanceTo(1) << endl;
  cout << dijk.distanceTo(0) << endl;

  return 0;
}
