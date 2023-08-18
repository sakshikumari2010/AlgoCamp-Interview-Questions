#include <bits/stdc++.h>

using namespace std;

// Que 1> Maximal Rectangle 
// Que 2> Sum of Subarray Minimums
// Que 3> Number of Valid Subarrays
// Que 4> Decoded string at index



// Que 1> Maximal Rectangle 

vector<int> nextSmaller(vector<int> arr, int n ){
    vector<int> ans(n, n);
    stack<int> st;
    st.push(0);
    for(int i =1; i< n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
       }
    return ans;   
   }

vector<int> previousSmaller(vector<int> arr , int n ){
    vector<int> output(n,-1);
    vector<int> nse(n,-1);
    reverse(arr.begin(), arr.end());
    stack<int> st;
    st.push(0);
    for(int i =1; i<n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);

    }
    reverse(nse.begin(), nse.end());
    for(int i =0 ;i<n; i++){
        if(nse[i] != -1)
        output[i] = n- 1 - nse[i];
    }
    return output;
}


int largestRectangleArea(vector<int> heights) {
        int n = heights.size();
            vector<int> nse =  nextSmaller(heights,n);
            vector<int> pse = previousSmaller(heights,n);
            vector<int> area(n);
            int maxi = -1;
            for(int i =0; i<n; i++){
                area[i] = (heights[i] * (nse[i] - pse[i] - 1));
                maxi = max(maxi, area[i]);
            }
        return maxi;
}



int maximalRectangle(vector<vector<char>>& matrix) {
       int rowSize = matrix.size();
       int colSize = matrix[0].size();

        vector<vector<int>> arr(rowSize, vector<int> (colSize,0));
        for (int i = 0; i < rowSize; i++){
            for (int j = 0; j < colSize; j++) {
                arr[i][j] = matrix[i][j] - '0';
            }
        }

        int area = largestRectangleArea(arr[0]);
        for(int i = 1; i< rowSize; i++){
            for(int j =0; j< colSize; j++){
                  if(arr[i][j] == 1)
                    arr[i][j] = arr[i][j] + arr[i-1][j];
                
            }
            int newArea = largestRectangleArea(arr[i]);
            area = max(area, newArea);
        }
        return area;
        
}


// Que 2> Sum of Subarray Minimums

    
 vector<long long int> nse(vector<int> arr){
        int n = arr.size();
        vector<long long int> res(n, n);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++){
            while (!st.empty() && arr[st.top()] > arr[i]){
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<long long int> pse(vector<int> arr){
        vector<long long int> ans(arr.size(), -1);
        stack<int> st;
        int n = arr.size();
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int> &vec)
    {
        vector<long long int> nse_ele = nse(vec);
        vector<long long int> pse_ele = pse(vec);
        vector<int> sum(vec.size());
        int count = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < vec.size(); i++)
        {
            count = ((vec[i] * (i - pse_ele[i]) * (nse_ele[i] - i)) + count) % mod;
        }

        return count;
    }



// Que 3> Number of Valid Subarrays 

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



// Que 4> Decoded string at index


string decodeAtIndex(string s, int k){

    stack<pair<char,  long long int>> st;
    long long  int len = 0;
    string ch;
    for (int i = 0; i < s.size(); i++){

        if (k > len){
            if (s[i] > 48 && s[i] <= 57) {
                len = len * (s[i] - '0');
            }
            else{
                len = len + 1;
            }
            
        }

     if (s[i] > 58 || s[i] < 47)  st.push({s[i], len});
          
     if (len >= k)   break;
    }

    while (k != 0)
    {
        pair<char, int> p;
        p = st.top();
        len = p.second;
        k = k % len;
        ch = p.first;
        st.pop();
    }
    return ch;
}
 

