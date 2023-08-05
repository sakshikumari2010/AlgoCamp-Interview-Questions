#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = nullptr;
        temp = node;
         ListNode *prev= temp;
            while(temp->next != nullptr){
            temp->val = temp->next->val;
            prev = temp;
            temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }        
    
};