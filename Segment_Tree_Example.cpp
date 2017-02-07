#include <iostream>

using namespace std;
void constructTree(int input[], int segTree[], int low, int high, int pos){ //minimum value in a range
    if(low==high){
        segTree[pos]=input[low];
        return;
    }
    int mid=(low+high)/2;
    constructTree(input, segTree, low, mid, 2*pos+1);
    constructTree(input, segTree, mid+1, high, 2*pos+2);
    segTree[pos]=min(segTree[2*pos+1], segTree[2*pos+2]);
}
int rangeMinQuery(int segTree[], int qlow, int qhigh, int low, int high, int pos){
    if(qlow <= low && qhigh >= high)
        return segTree[pos];
    if(qhigh < low || qlow > high )
        return INT_MAX;
    int leftMin=rangeMinQuery(segTree, qlow, qhigh, low, (low+high)/2, 2*pos+1);
    int rightMin=rangeMinQuery(segTree, qlow, qhigh, (low+high)/2+1, high, 2*pos+2);

    return min(leftMin, rightMin);
}
int main()
{
    int input[]={-1, 2, 4, 0};
    int segTree[7];
    constructTree(input, segTree, 0, 3, 0);
    for(int x=0; x<7; x++){
        cout<<segTree[x]<<" ";
    }
    cout<<endl;
    for(int x=0; x<4; x++){
        for(int y=0; y<=x; y++){
            cout<<y<<" "<<x<<" "<<rangeMinQuery(segTree, y, x, 0, 3, 0)<<endl;
        }
    }
    return 0;
}
