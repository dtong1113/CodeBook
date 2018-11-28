#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

// y34y
class BinarySearchTree {
public:
  set<int> repr;

  void insert(int val) { repr.insert(val); }

  bool contains(int val) { return repr.count(val) != 0; }

  int nextLargest(int val) {
    bool contained = contains(val);
    if (!contained) repr.insert(val);

    auto it = repr.find(val);

    int ret = it == repr.end() ? INT_MAX : *(++it);

    if (!contained) repr.erase(val);

    return ret;
  }

  int nextSmallest(int val) {
    bool contained = contains(val);
    if (!contained) repr.insert(val);

    auto it = repr.find(val);

    int ret = it == repr.begin() ? INT_MIN: *(--it);

    if (!contained) repr.erase(val);

    return ret;
  }
};

// y34y
class BinarySearchTreeMap {
public:
  map<int, int> repr;

  void insert(int key, int val) { repr[key] = val; }

  bool contains(int val) { return repr.count(val) != 0; }

  int nextLargest(int val) {
    bool contained = contains(val);
    if (!contained) repr[val] = -1;

    auto it = repr.find(val);

    int ret = it == repr.end() ? -1 : (++it)->second;

    if (!contained) repr.erase(val);

    return ret;
  }

  int nextSmallest(int val) {
    bool contained = contains(val);
    if (!contained) repr[val] = -1;

    auto it = repr.find(val);

    int ret = it == repr.begin() ? -1 : (--it)->second;

    if (!contained) repr.erase(val);

    return ret;
  }
};

int main() {

  BinarySearchTree bst;
  bst.insert(5);
  bst.insert(3);

  cout << bst.contains(3) << endl;
  cout << bst.contains(4) << endl;
  cout << bst.nextLargest(4) << endl;
  cout << bst.nextSmallest(4) << endl;

  BinarySearchTreeMap bstm;

  bstm.insert(5, 5);
  bstm.insert(3, 3);

  cout << bstm.contains(3) << endl;
  cout << bstm.contains(4) << endl;
  cout << bstm.nextLargest(4) << endl;
  cout << bstm.nextSmallest(4) << endl;
  cout << bstm.nextSmallest(3) << endl;

  return 0;
}
