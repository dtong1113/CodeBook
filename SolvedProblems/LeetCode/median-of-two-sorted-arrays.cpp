#include <bits/stdc++.h>

using namespace std;
double findNthSmallest(vector<int>& nums1, vector<int>&nums2, int N);
int main(){
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int a;
    cin>>a;
    while(a >= 0) {
        cout<<findNthSmallest(nums1, nums2, a);
        cin>> a;
    }

}
double findNthSmallest(vector<int>& nums1, vector<int>&nums2, int N) {
    int size1 = nums1.size();
    int size2 = nums2.size();

    int index1 = 0;
    int index2 = 0;
    while(index1 + index2 < N -1) {
        int step = (N - index1 - index2)/2;
        int step1 = index1 + step;
        int step2 = index2 + step;

        if(size1 > step1 - 1 && (size2 <= step2 - 1 || (nums1[step1-1] < nums2[step2-1]))) {
            index1 = step1;
        } else {
            index2 = step2;
        }
    }

    if(size1 > index1 && (size2 <= index2 || (nums1[index1] < nums2[index2]))) {
        return nums1[index1];
    } else {
        return nums2[index2];
    }
}
//https://stackoverflow.com/questions/4607945/how-to-find-the-kth-smallest-element-in-the-union-of-two-sorted-arrays
