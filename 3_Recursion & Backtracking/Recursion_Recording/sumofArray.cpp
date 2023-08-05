#include<iostream>
#include<vector>
using namespace std;

// Question: Find the sum of array element recursively.

int sumofArr(vector<int> arr, int i){
    if(i == arr.size()) return 0;
    return arr[i] + sumofArr(arr, i+1);
}
int main(){
    vector<int> arr {2,3,-1,5,4,6};
    cout<<sumofArr(arr, 0);

    return 0;
}