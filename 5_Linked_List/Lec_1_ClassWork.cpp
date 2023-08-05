#include <iostream>
using namespace std;

// Que1> Reverse a Linked List
// Que2> Middle of a Linked List
// Que3> Merge two sorted List
// Que4> Intersection of two Linked List
// Que5> Reorder List


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Que 1> Reverse a Linked List  -  Iterative Solution

ListNode *reverseList(ListNode *head){
    ListNode *prev = NULL, *current = head;
    while (current != NULL)
    {
        ListNode *nextPtr = current->next;
        current->next = prev;
        prev = current;
        current = nextPtr;
    }
    return prev;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

// Que 1> Reverse a Linked List  - Recursive Solution
// (Note :  Change the function name before submitting to LeetCode)

ListNode *reverseListRecursive(ListNode *head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *p = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
    // Time Complexity: O(n)
    // Space Complexity: O(n)
}

// Que 2> Middle of a Linked List
ListNode *middleNode(ListNode *head){
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

// Que 3> Merge two Sorted List

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
    ListNode *prevHead = new ListNode(-1);
    ListNode *prev = prevHead;
    while (list1 != NULL && list2 != NULL){
        if (list1->val > list2->val){
            prev->next = list2;
            list2 = list2->next;
        }
        else{
            prev->next = list1;
            list1 = list1->next;
        }
        prev = prev->next;
    }
    prev->next = list1 == NULL ? list2 : list1;
    return prevHead->next;

    // Time Complexity: O(n + m)
    // Space Complexity: O(1)
}

// Que 4> Intersection of two Linked List
ListNode *helper(ListNode *h1, ListNode *h2, int diff){
    while (diff--)  h1 = h1->next;
    
    while (h1 != h2){
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){

    ListNode *h1 = headA, *h2 = headB;
    int len1 = 1, len2 = 1;
    while (headA->next != NULL)  len1++, headA = headA->next;
    while (headB->next != NULL)  len2++, headB = headB->next;
    int difference = abs(len1 - len2);

    if (len1 > len2) return helper(h1, h2, difference);
    else {
        return helper(h2, h1, difference);
    }

    return NULL;
    // Time Complexity: O(n) where n is longest length of list.
    // Space Complexity: O(1)
}

// Que 5> ReOrder  List
// Solution: Find Mid of List -> Divide list from mid element -> Reverse second half of list -> Merge two linked list

ListNode *middleNode(ListNode *head){
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    } 
    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}

void mergeList(ListNode *h1, ListNode *h2){
    ListNode *m1 = h1, *m2 = h2;
        while(h1 != NULL && h2 != NULL){
            m1 = h1->next;
            m2 = h2->next;
            h1->next = h2;
            h2->next = m1;
            h1 = m1;
            h2 = m2;    
    }
}


void reorderList(ListNode* head) {
    ListNode *mid = middleNode(head);
    ListNode *h2 = mid->next;
    mid->next = NULL;
    ListNode *rev = reverseList(h2);
    mergeList(head, rev);
        
}