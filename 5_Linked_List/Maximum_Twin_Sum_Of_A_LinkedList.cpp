#include<iostream>
#include<vector>

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

    ListNode * getMiddle(ListNode *head){
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

        }
        return slow;
    }

    ListNode * reverse(ListNode * head){
        ListNode *prev =NULL,*current = head, *nextNode= head->next;
        if(head == NULL || head->next == NULL) return head;
        while(current->next != NULL){
            
            current->next = prev;
            prev = current;
            current = nextNode;
            nextNode =  nextNode->next;
        }
         current->next = prev;

        return current;
    }

    int maxSum(ListNode *a, ListNode *b){
        int maxVal = 0;
        while(a != NULL ){
            int res = a->val + b->val;
            maxVal = max(maxVal, res);
            a = a->next;
            b = b->next;
        }
        return maxVal;
    }
    
    int pairSum(ListNode* head) {
        
        ListNode *mid = getMiddle(head);
        ListNode *revHead = reverse(mid->next);
        mid->next = NULL;
        int res = maxSum(head, revHead);
        return res;
        
    }
};