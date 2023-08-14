#include<bits/stdc++.h>
using namespace std;

// Problem Link --> https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1


class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.

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
        // while(!st.empty()){
        //     res[st.top()] = -1;
        //     st.pop();
        // }

        // for(auto x : res) std :: cout<<"NGE: "<< x<<" ";
        // cout<<endl;
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
                ans[i] = n - 1 - ans[i]; // This line is magic. New Learning from this.How to play with index
            }
        }
        return ans;
    }

    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = price[i];

        vector<int> pge = previousGreaterElement(arr);
        //   for(auto x : pge) cout<<"PGE: "<< x <<" ";
        //     cout<<endl;

        vector<int> ans(n);

        for (int i = 0; i < n; i++){

            ans[i] = i - pge[i];
            //   cout<<i<<" : "<<ans[i]<<" ";
        }
        //   cout<<endl;
        return ans;
    }
};
