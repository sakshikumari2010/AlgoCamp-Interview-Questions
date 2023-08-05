#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findNum(vector<int> num , int target, int ind){
    if(num[ind] == target) return ind;
    if(ind == num.size()) return -1;

    return findNum(num, target, ind+1); 
}



int main(){
    vector<int> vec {12,4,5,6,7,8,9,1};
    int target = 10;
    int i =0;
    cout<<findNum(vec,target,i);


    return 0;
}