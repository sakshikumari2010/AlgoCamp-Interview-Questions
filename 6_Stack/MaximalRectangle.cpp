#include <bits/stdc++.h>

using namespace std;

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
