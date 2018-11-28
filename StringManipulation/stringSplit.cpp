#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& str, const string& pattern) {
  vector<string> ret;

  string next = "";
  string buffer = "";
  int idx = 0;

  for (int i = 0; i < str.size(); i++) {
    cout << buffer << " " << next << endl;
    buffer += str[i];
    if (pattern[idx] == str[i]) {
      idx++;
    } else {
      next += buffer;
      buffer = "";
      idx = 0;
    }

    if (idx == pattern.size()) {
      ret.push_back(next);
      idx = 0;
      next = "";
      buffer = "";
    }
  }

  ret.push_back(next + buffer);

  return ret;
}
int main(){
    string a="A,,B,C,,D";

    vector<string> tokens = split(a, ",,");
    for (string token : tokens) {
      cout << token << endl;
    }
}
