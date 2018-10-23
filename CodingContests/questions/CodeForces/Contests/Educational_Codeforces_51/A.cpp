#include <bits/stdc++.h>

using namespace std;

void increment(vector<int>& arr, char c, int num) {
  if (c >= 'a' && c <= 'z') {
    arr[0]+= num;
  } else if (c >= 'A' && c <= 'Z') {
    arr[1]+= num;
  } else {
    arr[2]+= num;
  }
}

bool isValid(vector<int>& arr) {
  if(arr[0] > 0 && arr[1] > 0 && arr[2] > 0) {
    return true;
  }
  return false;
}
int main() {
  //ifstream cin("input.txt");
  //ofstream cout("out.txt");
  
  int t = 0;
  cin >> t;
  while(t > 0) {
    t--;
    string pass;
    cin >> pass;

    vector<int> counts(3, 0);
    for(int i = 0; i < pass.size(); i++) {
      increment(counts, pass[i], 1);
    }

    if (isValid(counts)) {
      cout << pass << endl;
      continue;
    }
    vector<string> rep{"a", "A", "1", "aA", "a1", "Aa", "A1", "1a", "1A",
      "aA1", "a1A", "1aA", "1Aa", "Aa1", "A1a"};

    for(auto s : rep) {
      bool flag = false;
      for (int i = 0; i <= pass.size() - s.size(); i++) {
        string temp = pass;
        for(int j = 0; j < s.size(); j++) {
          temp[i + j] = s[j];
        }
        vector<int> count(3, 0);
        for(int i = 0; i < pass.size(); i++) {
          increment(count, temp[i], 1);
        }
        if(isValid(count)) {
          cout << temp << endl;
          flag = true;
          break;
        }
      }
      if(flag)
        break;
    }
  }

  return 0;
}
