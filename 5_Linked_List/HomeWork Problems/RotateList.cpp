#include<iostream>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *start = head, *last =head, *prev = NULL;
        if(start == NULL) return NULL;
        int count =1;
        while(last->next != NULL) {   
            last = last->next;
            count++;

        }
        last->next = head;
        k = k % count;
        int val = count - k -1;
        prev = head;
        while(val--){
            start =  start->next;
        }
        prev = start->next;
        start->next = NULL;
        return prev;
        
    }
};