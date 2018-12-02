#include <bits/stdc++.h>

//https://leetcode.com/problems/regular-expression-matching/description/
using namespace std;
bool isMatch(string s, string p);
bool isMatchHelp(string s, string p, char prev);
map<pair<int, int>, bool> visited;
int main()
{

}
bool isMatch(string s, string p) {
        return isMatchHelp(s, p, '*');
    }
bool isMatchHelp(string s, string p, char prev) {
    bool check = false;

    if(s.length() == 0 && p.length() == 0) {
        return true;
    }
    map<pair<int, int>, bool>::iterator it = visited.find(make_pair(s.length(), p.length()));
    if(it != visited.end()) {
        return it->second;
    }
    if(s.length() > 0 && ((s[0] == p[0]) || (p[0] == '.'))) {
        check = check || isMatchHelp(s.substr(1), p.substr(1), p[0]);
    }
    if(p.length() > 1 && (p[1] == '*')) {
        check = check || isMatchHelp(s, p.substr(2), '*');
    }

    if((p.length() > 0) && (s.length() > 0) && (p[0] == '.')) {
        check = check || isMatchHelp(s.substr(1), p.substr(1), prev);
    }
    if(p.length() > 0 && p[0] == '*') {
        if(s.length() > 0 && (s[0] == prev || prev == '.')){
            check = check || isMatchHelp(s.substr(1), p, prev);
        }
        check = check || isMatchHelp(s, p.substr(1), '*');
    }

    visited[make_pair(s.length(), p.length())] = check;
    return check;
}
