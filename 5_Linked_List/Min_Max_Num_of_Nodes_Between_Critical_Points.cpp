#include<bits/stdc++.h>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};    


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};
        if(head->next->next == NULL ) return ans;
        vector<int> dist;
        int n =0;
        ListNode *prev = head, *curr = head->next, *nextPtr = head->next->next;
        while(nextPtr != NULL){
            n++;
            if(curr->val > prev->val && curr->val > nextPtr->val){
                dist.push_back(n);

            }else if(curr->val < prev->val && curr->val < nextPtr->val){
                dist.push_back(n);
            }
            prev = prev->next;
            curr = curr->next;
            nextPtr = nextPtr->next;
        }
        int N = dist.size();
        if(N == 0 || N == 1) return ans;
        int minDistance = INT_MAX;

        for(int i =0; i< N-1 ; i++){
            int diff = dist[i+1] - dist[i];
             minDistance = min(minDistance, diff);
        }
        
        int maxDistance = dist[N-1] - dist[0];
        ans[0]= minDistance;
        ans[1] = maxDistance;
        return ans;
         
        
    }
};