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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr= NULL,*temp = NULL, *head = NULL;
        int carry =0,res;
        int data =  l1->val + l2->val;
        carry = data/10;
        data = data % 10;
        temp = new ListNode(data);
        ptr = temp;
        head = temp;
        l1 = l1->next;
        l2 = l2->next;

        while(l1 != NULL && l2 != NULL){
           
            data = l1->val + l2->val;
            res = ( data + carry);
            carry = res /10;
            res = res % 10;
            temp = new ListNode(res);
            ptr->next = temp;
            ptr = temp;
            l1 = l1->next;
            l2 = l2->next;

        }
        if(l2 == nullptr){
            while(l1 != nullptr){
                data = l1->val;
                res = ( data + carry);
                carry = res /10;
                res = res % 10;
                temp = new ListNode(res);
                ptr->next = temp;
                ptr = temp;
                l1 = l1->next;

            }
        }

        else if(l1 == nullptr){
            while(l2 != nullptr){
                data = l2->val;
                res = ( data + carry);
                carry = res /10;
                res = res % 10;
                temp = new ListNode(res);
                ptr->next = temp;
                ptr = temp;
                l2 = l2->next;

            }
        }
        if(carry > 0){
            temp =new ListNode(carry);
            ptr->next = temp;
            ptr = temp;
        }
        return head;
    }
};