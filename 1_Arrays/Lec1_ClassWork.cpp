#include <iostream>
#include <vector>

using namespace std;

// Que 1> Product of Array Except Self

vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
    vector<int> left(n);
    vector<int> right(n);
    int prd = 1;
    left[0] = 1;
    for (int i = 1; i < n; i++){
        prd = nums[i - 1] * prd;
        left[i] = prd;
    }
    right[n - 1] = 1;
    prd = 1;
    for (int i = n - 2; i >= 0; i--){
        prd = prd * nums[i + 1];
        right[i] = prd;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] = left[i] * right[i];
    }
    return ans;
}

// Que2> First Missing Positive

int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int contains =0;
        for(int i =0; i<n ;i++) {
            if(nums[i] == 1){
                contains++;
                break;
            }
        }
        if(contains == 0) return 1;

        for(int i =0; i<n ;i++){
            if(nums[i] <=0 || nums[i] >n) nums[i] = 1;
        }

        for(int i =0; i<n; i++){
            int a = abs(nums[i]);
            if(a == n) nums[0] = -abs(nums[0]);
            else nums[a] = -abs(nums[a]);
        }
        for(int i =1; i<n; i++){
            if(nums[i] >0) return i;
        }
        if(nums[0] >0) return n;
        return n+1;
    }
