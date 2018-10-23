#include <bits/stdc++.h>

using namespace std;

int main() {
  //ifstream cin("input.txt");
  //ofstream cout("out.txt");

  int n, k;
  cin >> n >> k;

  int flip = k*2+1;

  if(n <=  k) {
    cout << 1 << endl;
    cout << n/2;
  } else {
    int num = n - (n/flip - 1)*flip;
    int total = n/flip - 1;
    vector<int> vals;
    if(num == flip) {
      vals.push_back(k);
      for(int i = 0; i < total; i++) {
        vals.push_back(vals[vals.size() - 1] + flip);
      }
      total ++;
    } else {
      int diff = num - flip;
      int half = diff/2;
      vals.push_back(half);
      for(int i = 0; i <= total; i++) {
        vals.push_back(vals[vals.size() - 1] + flip);
      }
      total += 2;
    }
    cout << total << endl;
    for(int i = 0; i < vals.size(); i++) {
      cout << vals[i] << " ";
    }
  }
  return 0;
}
