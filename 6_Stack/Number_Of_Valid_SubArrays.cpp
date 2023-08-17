#include<bits/stdc++.h>
using namespace std;

// Que 1> Number of Valid Subarrays

vector<int> nextSmallerEle(vector<int> arr){
    vector<int> res(arr.size(), arr.size());
    stack<int> st;
    st.push(0);
    for(int i = 1; i< arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}


int validSubarray(vector<int> vec){
    int ans = 0;
    vector<int> nextSmall = nextSmallerEle(vec);
    for(int i = 0; i< vec.size() ; i++){
        ans = ans + (nextSmall[i] - i);

    }
    return ans;
}


