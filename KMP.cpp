#include <bits/stdc++.h>

using namespace std;

int *pattern(string b){
    int* lps=new int[b.length()];
    for(int i=0; i<b.length(); i++){
        lps[i]=0;
    }
    int index=0;
    for(int i=1; i<b.length();){
        if(b[i]==b[index]){
            lps[i]=index+1;
            index++;
            i++;
        }else{
            if(index !=0){
                index=lps[index-1];
            }else{
                lps[i++]=0;
            }
        }
    }

    cout<<endl;
    return lps;
}
int kmp(string a, string b){    //finds string b in a
    int *lps=pattern(b);
    int i=0;
    int j=0;
    int counter=0;
    while(i <a.length() && j<b.length()){
        counter++;
        if(a[i] == b[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    delete(lps);
    if(j==b.length())
        return i-b.length();
    return -1;
}
int main(){
    string a="abcabcdaaaaabcabcdaaaaabcabcdaaaaabcabcdaaaaabcabcdaaaaabcabcdaaaaabcabcdaaaaabcabcdaaaaabcabcdaaaaabcabcdaaaaz";
    string b="aaaabcabcdaaaaz";
    cout<<kmp(a, b)<<endl;
}
