#include <bits/stdc++.h>

using namespace std;

string word1;
string word2;
int arr[1000][1000];
bool visited[1000][1000];
/*
The DP state is the characters remaining in each word.
We begin by editing from the back of each word.
The cost of the state (a, b) is equal to the min between (a-1, b)+1, (a, b-1) + 1, (a-1, b-1) + c.
The options can be interpreted as removing a letter from a, adding a letter to a, and changing a letter in a
*/
int editDistance(int a, int b){
    if(visited[a][b])
        return arr[a][b];
    visited[a][b] = true;
    if(a == 0){
        arr[a][b] = b;
    }
    else if(b == 0){
        arr[a][b] = a;
    }else{
        arr[a][b] = min(min(editDistance(a-1, b)+1, editDistance(a, b-1)+1), editDistance(a-1, b-1) + (word1[a-1] != word2[b-1]));
    }
    return arr[a][b];
}
int main() {
    cin>>word1 >> word2;
    cout<<editDistance(word1.length(), word2.length());
    return 0;
}
