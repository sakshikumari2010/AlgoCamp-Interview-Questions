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


// Que 5> Stock Span Problem

 vector<int> nextGreaterElement(vector<int> arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        st.push(0);

        for (int i = 1; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }

vector<int> previousGreaterElement(vector<int> arr)
    {

        vector<int> ans(arr.size(), -1);
        reverse(arr.begin(), arr.end());
        ans = nextGreaterElement(arr);
        reverse(ans.begin(), ans.end());
        // cout<<"PGE : "<<endl;
        int n = arr.size();

        for (int i = 0; i < n; i++){
            if (ans[i] != -1){
                ans[i] = n - 1 - ans[i]; 
            }
        }
        return ans;
    }

vector<int> calculateSpan(int price[], int n)
    {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = price[i];

        vector<int> pge = previousGreaterElement(arr);
        vector<int> ans(n);

        for (int i = 0; i < n; i++){

            ans[i] = i - pge[i];
            
        }
        
        return ans;
    }




// Que 6> Largest Rectangle in Histogram.

vector<int> nextSmaller(vector<int> arr, int n){

        vector<int> ans(n, n);
        stack<int> st;
        st.push(0);

        for (int i = 1; i < n; i++){
            while (!st.empty() && arr[st.top()] > arr[i]){

                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
}

vector<int> previousSmaller(vector<int> arr, int n){

    vector<int> output(n, -1);
    vector<int> nse(n, -1);
    reverse(arr.begin(), arr.end());
    stack<int> st;
    st.push(0);
        for (int i = 1; i < n; i++){
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    reverse(nse.begin(), nse.end());
        for (int i = 0; i < n; i++){
            if (nse[i] != -1)
                output[i] = n - 1 - nse[i];
        }
    return output;
}

int largestRectangleArea(vector<int> &heights){

    int n = heights.size();
    vector<int> nse = nextSmaller(heights, n);
    vector<int> pse = previousSmaller(heights, n);
    vector<int> area(n);
    int maxi = -1;

    for (int i = 0; i < n; i++)
    {
        area[i] = (heights[i] * (nse[i] - pse[i] - 1));
        maxi = max(maxi, area[i]);
    }

    return maxi;
}

//-------------------------------------------------------------------------------------------

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
