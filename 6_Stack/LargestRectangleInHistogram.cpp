#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> nextSmaller(vector<int> arr, int n)
    {
        vector<int> ans(n, n);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> previousSmaller(vector<int> arr, int n)
    {
        vector<int> output(n, -1);
        vector<int> nse(n, -1);
        reverse(arr.begin(), arr.end());
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        reverse(nse.begin(), nse.end());
        for (int i = 0; i < n; i++)
        {
            if (nse[i] != -1)
                output[i] = n - 1 - nse[i];
        }
        return output;
    }

    int largestRectangleArea(vector<int> &heights)
    {
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
};




// ---------------------Below code is same as above only some lines are commeneted to help me in dry run -------------------------------------




vector<int> nextSmaller(vector<int> arr, int n)
{
    vector<int> ans(n, n);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    //  cout<<"NSE : "<<endl;
    //     for(int i =0 ;i<n; i++){
    //          cout<<ans[i]<<" ";
    //     }
    //     cout<<endl;
    return ans;
}

vector<int> previousSmaller(vector<int> arr, int n)
{
    vector<int> output(n, -1);
    vector<int> nse(n, -1);
    reverse(arr.begin(), arr.end());
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // cout<<"NSE before reverse : "<<endl;
    // for(int i =0 ;i<n; i++){
    //      cout<<nse[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"NSE after reverse : "<<endl;
    reverse(nse.begin(), nse.end());
    // for(int i =0 ;i<n; i++){
    //      cout<<nse[i]<<" ";
    // }

    // cout<<"PSE : "<<endl;
    for (int i = 0; i < n; i++)
    {
        if (nse[i] != -1)
            output[i] = n - 1 - nse[i];
        //  cout<<output[i]<<" ";
    }
    // cout<<endl;
    return output;
}

int largestRectangleArea(vector<int> heights)
{
    int n = heights.size();
    vector<int> nse = nextSmaller(heights, n);
    vector<int> pse = previousSmaller(heights, n);
    vector<int> area(n);
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        area[i] = (heights[i] * (nse[i] - pse[i] - 1));
        // cout<<area[i]<<" ";
        maxi = max(maxi, area[i]);
    }
    return maxi;
}

int main()
{

    vector<int> vec = {2, 1, 5, 6, 2, 3};
    int n = vec.size();
    int ans = largestRectangleArea(vec);
    cout << ans << endl;
}