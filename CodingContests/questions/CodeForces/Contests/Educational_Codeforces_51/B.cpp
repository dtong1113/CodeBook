#include <bits/stdc++.h>

using namespace std;

int main() {
  //ifstream cin("input.txt");
  //ofstream cout("out.txt");
  long long l, r;
  cin >> l >> r;
  cout << "YES" << endl;
  long long i =  l;
  for(; i < r; i+=2) {
    cout << i << " " << (i + 1) << endl;
  }
  return 0;
}
