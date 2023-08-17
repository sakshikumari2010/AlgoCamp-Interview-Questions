#include <iostream>
#include <stack>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<long long int> nse(vector<int> arr)
    {
        int n = arr.size();
        vector<long long int> res(n, n);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<long long int> pse(vector<int> arr)
    {
        vector<long long int> ans(arr.size(), -1);
        stack<int> st;
        int n = arr.size();
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
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
};