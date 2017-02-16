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
int main(){
    int arr[]={1, 1, 1, 1, 3, 5};

    cout<<binarySearch(arr, 0, 4, 1)<<endl;
    cout<<binarySearchCeil(arr, 0, 4, 1)<<endl;
    cout<<binarySearchFloor(arr, 0, 4, 1)<<endl;
}
