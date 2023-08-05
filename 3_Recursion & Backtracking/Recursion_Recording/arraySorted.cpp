#include<iostream>
#include<vector>

using namespace std;

bool checkSorted(vector<int> vec, int ind){
    if(ind == vec.size() - 1) return true;
    if(vec[ind] > vec[ind+1]) return false;
    return checkSorted(vec, ind +1);
}




int main(){
    vector<int> vec {3,4,1,6,7,8,9};
    cout<<checkSorted(vec,0);
    
}