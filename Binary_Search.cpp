#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int lo, int hi, int val){
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] == val){
            return mid;
        }else if(arr[mid] < val){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return -1;
}

int binarySearchCeil(int arr[], int lo, int hi, int val){   //finds the left most index of your val
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] < val){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return lo;
}
int binarySearchFloor(int arr[], int lo, int hi, int val){  //finds the right most index of your val
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] <= val){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return hi;
}

int maximumValue(vector<int> arr, int (*f)(int), int lo, int high){ //function that is first increasing then decreasing (must have unique values)
    int x = lo - 1;
    for(int i = high-lo; i >=1; i/=2){
        while(x + i + 1<= high && f(arr[x+i]) < f(arr[x + i + 1])){
            x += i;
            cout<<x<<endl;
        }
    }
    int k = x + 1;
    return k;
}
int func(int a){
    return a*a;
}
int main(){
    int arr[]={1, 1, 1, 1, 3, 5};
    vector<int> a ={-3, 1, 2, 3, 4, 5, 9, 11, 12, 8, 2};
    cout<<maximumValue(a, func, 0, a.size()-1)<<endl;
    cout<<binarySearch(arr, 0, 4, 1)<<endl;
    cout<<binarySearchCeil(arr, 0, 4, 1)<<endl;
    cout<<binarySearchFloor(arr, 0, 4, 1)<<endl;
}
