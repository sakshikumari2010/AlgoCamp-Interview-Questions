#include<bits/stdc++.h>

using namespace std;

// Que 1> Find Next greater element.
// Que 2> Find Next smaller element.
// Que 3> Find previous greater element.
// Que 4> Find previous smaller element.
// Que 5> Stock Span Problem
// Que 6> Largest Rectangle in Histogram.

// Que 1> Find Next greater element.

vector<int> nextGreaterElement(vector<int> arr){
    int n = arr.size();
    vector<int> res(n,-1);
    stack<int> st;
    st.push(0);
    
    for(int i =1; i<n; i++){

        while(!st.empty() && arr[st.top()] < arr[i]){
            res[st.top()] = arr[i];
            st.pop();

        }  
        st.push(i);
    }

    while(!st.empty()){
        res[st.top()] = -1;
        st.pop();
    }
    cout<<"NGE : "<<endl;
    for(auto x : res) std :: cout<<x<<" ";
    cout<<endl;
    return res;

}

// Que 2> Find Next smaller element.


vector<int> nextSmallerElement(vector<int> arr){
    int n = arr.size();
    vector<int> res(n,-1);
    stack<int> st;
    st.push(0);
    
    for(int i =1; i<n; i++){

        while(!st.empty() && arr[st.top()] >= arr[i]){
            res[st.top()] = arr[i];
            st.pop();

        }  
        st.push(i);
    }
    cout<<"NSE : "<<endl;

    for(auto x : res) std :: cout<<x<<" ";
    cout<<endl;
    return res;

}

// Que 3> Find previous greater element.


vector<int> previousGreaterElement(vector<int> arr){
    vector<int> ans(arr.size(), -1);
    reverse(arr.begin(), arr.end());
    cout<<"Reverse of : ";
    ans = nextGreaterElement(arr);
    reverse(ans.begin(), ans.end());
    cout<<"PGE : "<<endl;
    int n = arr.size();
    for(auto x : ans) {
           cout<<x<<" ";
    }
    cout<<endl;
    return ans;

}

// Que 4> Find previous smaller element.

vector<int> previousSmallerElement(vector<int> arr){
    vector<int> ans(arr.size(), -1);
    reverse(arr.begin(), arr.end());
    cout<<"Reverse of : ";
    ans = nextSmallerElement(arr);
    reverse(ans.begin(), ans.end());
    cout<<"PSE : "<<endl;

    for(auto x : ans) std :: cout<<x<<" ";
    cout<<endl;
    return ans;

}

int main(){
    // vector<int> vec = {100, 80, 60, 70, 60, 75, 85};
    vector<int> vec = {11, 9, 8, 7, 10, 12};
    // {12, 10, 7, 8, 9, 11}
    vector<int> ans = nextGreaterElement(vec);
    
    ans = nextSmallerElement(vec);
    ans = previousSmallerElement(vec);
    ans = previousGreaterElement(vec);
    return 0;
}
