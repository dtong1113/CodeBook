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
  int n;
  cin >> n;
  bool flag = false;
  for(int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if(temp) {
      flag = true;
    }
  }
  if(flag) {
    cout << "HARD" << endl;
  } else {
    cout << "EASY" << endl;
  }
  return 0;
}
