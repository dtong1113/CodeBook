#include <bits/stdc++.h>

using namespace std;

int main() {
  //ifstream cin("input.txt");
  //ofstream cout("out.txt");
  int n;
  cin >> n;

  map<long long, int> counts;
  vector<long long> num;
  for(int i = 0; i < n; i++) {
    long long t;
    cin >> t;
    counts[t] += 1;
    num.push_back(t);
  }
  int single = 0;
  int flex = 0;
  int triple = 0;
  for(auto it = counts.begin(); it != counts.end(); it++) {
    long long count = it->second;
    if(count == 1) {
      single++;
    } else if(count == 2) {
      flex++;
    } else {
      triple++;
    }
  }
  if(single % 2 == 1 && triple == 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  int mod = 0;
  bool nec = false;
  if(single % 2 == 1) {
    nec = true;
  }
  int used = 0;
  bool trig = false;
  long long temp = -123982340;
  char printTemp = 0;
  for(long long val : num) {
    if(counts[val] == 2) {
      cout << "A";
    } else if(counts[val] == 1) {
      if(used % 2 == 0) {
        cout << "A";
      } else {
        cout << "B";
      }
      used ++;
    } else if(trig && (val == temp)) {
      cout << printTemp;
    } else if(!nec) {
      cout << "A";
    } else {
      nec = false;
      trig = true;
      if(used % 2 == 0) {
        cout << "A";
        printTemp = 'B';
      } else {
        cout << "B";
        printTemp = 'A';
      }
      temp = val;
      used++;
    }
  }
  cout << endl;
  return 0;
}
