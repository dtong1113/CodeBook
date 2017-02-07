#include <bits/stdc++.h>

using namespace std;

int main(){
    string a="A B C";
    stringstream ss;
    ss<<a;
    string token;
    int counter=0;
    vector<string> tokens;
    while(ss>>token){
        tokens.push_back(token);
    }
    for(int i=0; i<tokens.size(); i++){
        cout<<tokens[i]<<endl;
    }
}
