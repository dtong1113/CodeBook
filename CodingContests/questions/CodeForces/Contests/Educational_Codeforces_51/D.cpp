#include <bits/stdc++.h>

using namespace std;

int getKey(int state, int parts, int pos) {
  int key = parts;
  key *= 10;
  key += state;
  key *= 100000000;
  key += pos;
  return key;
}
int mod = 998244353;

vector<int> states{ 0, 1, 2, 3 };

unordered_map<int, long long> dp;
long long n, k;
long long bruteForce(int state, int parts, int pos) {
  auto key = getKey(state, parts, pos);
  //cout << key << endl;
  if(dp.count(key)) {
    return dp[key];
  }
  if(pos == n) {
    if(state == 0 || state == 3) {
      parts ++;
    } else {
      parts += 2;
    }
    if(parts == k) {
      dp[key] = 1l;
      return dp[key];
    }
    dp[key] = 0l;
    return dp[key];
  }
  if(parts >= k) {
    dp[key] = 0l;
    return dp[key];
  }
  long long total = 0;
  if(state == 0) {
    total += bruteForce(0, parts, pos+1);
    total %= mod;
    total += bruteForce(1, parts, pos+1);
    total %= mod;
    total += bruteForce(2, parts, pos+1);
    total %= mod;
    total += bruteForce(3, parts+1, pos+1);
    total %= mod;
  } else if(state == 1) {
    total += bruteForce(0, parts+1, pos+1);
    total %= mod;
    total += bruteForce(1, parts, pos+1);
    total %= mod;
    total += bruteForce(2, parts+2, pos+1);
    total %= mod;
    total += bruteForce(3, parts+1, pos+1);
    total %= mod;
  } else if(state == 2) {
    total += bruteForce(0, parts+1, pos+1);
    total %= mod;
    total += bruteForce(1, parts+2, pos+1);
    total %= mod;
    total += bruteForce(2, parts, pos+1);
    total %= mod;
    total += bruteForce(3, parts+1, pos+1);
    total %= mod;
  } else {
    total += bruteForce(0, parts+1, pos+1);
    total %= mod;
    total += bruteForce(1, parts, pos+1);
    total %= mod;
    total += bruteForce(2, parts, pos+1);
    total %= mod;
    total += bruteForce(3, parts, pos+1);
    total %= mod;
  }
  dp[key] = total;
  return dp[key];
}
int main() {
  //ifstream cin("input.txt");
  //ofstream cout("out.txt");
  //
  cin >> n >> k;

  long long l1 = bruteForce(0, 0, 1);
  long long l2 = bruteForce(1, 0, 1);
  long long total = l1 + l2;
  total %= mod;
  total *= 2;
  total %= mod;
  cout << total << endl;


  return 0;
}
