#include<iostream>

// Solution is explained here: 👇

// https://leetcode.com/problems/odd-even-linked-list/solutions/3795540/easy-c-solution-with-image-self-explanatory-code-with-o-1-space/

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd =new ListNode(0);
        ListNode *even =new ListNode(0);
        ListNode *temp = head,*oddptr = odd, *evenptr = even ;
        while(temp != NULL){
            oddptr->next = temp;
            oddptr = temp; 
            temp = temp->next;
             oddptr->next = NULL;
            if(temp != NULL){
            evenptr->next = temp;
             evenptr = temp;
            temp = temp->next;
            evenptr->next = NULL;
            }
        }
        oddptr->next = even->next;
        return odd->next;
    }
};