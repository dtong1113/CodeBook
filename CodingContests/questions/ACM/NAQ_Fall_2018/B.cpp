#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

bool isTriangle(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3);
int mod = 1e9 + 7;
ll length(pll a) {
  return a.first*a.first + a.second*a.second;
}
bool isOblong(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
  pll v1 = mp(x1 - x2, y1 - y2);
  pll v2 = mp(x1 - x3, y1 - y3);
  pll v3 = mp(x1 - x4, y1 - y4);
  pll v4 = mp(x2 - x3, y2 - y3);
  pll v5 = mp(x2 - x4, y2 - y4);
  pll v6 = mp(x3 - x4, y3 - y4);

  vector<pll> edges{v1, v2, v3, v4, v5, v6};
  sort(edges.begin(), edges.end(), [](auto a, auto b) {
      return length(a) < length(b);
  });
  if(length(edges[0]) != length(edges[1])) return false;
  if(length(edges[2]) != length(edges[3])) return false;
  if(length(edges[4]) != length(edges[5])) return false;
  if(length(edges[0]) == length(edges[2])) return false;
  if(length(edges[0]) == length(edges[4])) return false;
  if(length(edges[2]) == length(edges[4])) return false;
  if(length(edges[0]) == 0) return false;
  if(length(edges[0]) + length(edges[2]) != length(edges[4])) return false;
  if(!isTriangle(x1, y1, x2, y2, x3, y3)) return false;
  if(!isTriangle(x1, y1, x2, y2, x4, y4)) return false;
  if(!isTriangle(x1, y1, x3, y3, x4, y4)) return false;
  if(!isTriangle(x2, y2, x3, y3, x4, y4)) return false;


  return true;
}
ll dotProd(pll v1, pll v2) {
  return v1.first *  v2.first + v1.second * v2.second;
}
bool isTriangle(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
  pll v1 = mp(x1 - x2, y1 - y2);
  pll v2 = mp(x1 - x3, y1 - y3);
  pll v3 = mp(x2 - x3, y2 - y3);
  vector<pll> edges{v1, v2, v3};
  sort(edges.begin(), edges.end(), [](auto a, auto b) {
      return length(a) < length(b);
  });

  if(length(edges[0]) == 0) {
    return false;
  }
  if(dotProd(edges[0], edges[1]) == 0l) {
    double l1 = sqrt(length(edges[0]));
    double l2 = sqrt(length(edges[1]));
    double l3 = sqrt(length(edges[2]));
    if(l1 + l2 - l3 > 1e-5) {
      //cout << l1 << " " << l2 << " " << l3 << endl;
      return true;
    }

  }
  return false;
}

int main() {
  int N;
  cin >> N;

  vector<int> xp(N, 0);
  vector<int> yp(N, 0);
  for(int i = 0; i < N; i++) {
    cin >> xp[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> yp[i];
  }
  int counter = 0;
  for(int a = 0; a < N; a++) {
    for(int b = a + 1; b < N; b++) {
      for(int c = b + 1; c < N; c++) {
        for(int d = c + 1; d < N; d++) {
          for(int e = 0; e < N; e++) {
            if(e == a || e == b || e == c || e == d)
              continue;
            for(int f = e + 1; f < N; f++) {
              if(f == a || f == b || f == c || f == d)
                continue;
              for(int g = f + 1; g < N; g++) {
                if(g == a || g == b || g == c || g == d)
                  continue;
                  if(isOblong(xp[a], yp[a], xp[b], yp[b], xp[c], yp[c], xp[d], yp[d])) {
                if(isTriangle(xp[e], yp[e], xp[f], yp[f], xp[g], yp[g])) {
                    counter ++;
                    //cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << endl;
                  }
                }

              }
            }

          }
        }
      }
    }
  }
  cout << counter << endl;

  return 0;
}
