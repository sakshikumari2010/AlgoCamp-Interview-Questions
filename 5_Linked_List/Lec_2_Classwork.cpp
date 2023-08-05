#include <iostream>

using namespace std;

// Que 1> Linked List Cycle
// Que 2> Linked List Cycle 2
// Que 3> Palindrome Linked List
// Que 4> Reverse Nodes in k-Group
// Que 5> Partition List

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Que 1> Linked List Cycle

bool hasCycle(ListNode *head){

    if (head == NULL || head->next == NULL)  return false;
    ListNode *slow = head, *fast = head->next;

    while (slow != fast){
        if (fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

// Que 2> Linke List Cycle 2

ListNode *detectCycle(ListNode *head){

    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow = head, *fast = head;

    do{
        slow = slow->next;
        if (fast->next == NULL || fast == NULL)
            break;
        fast = fast->next->next;
    } while ((slow && fast) && fast != slow);

    slow = head;
    while ((slow && fast) && slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    if (slow == fast)
        return slow;
    return NULL;
}

// Que 3> Palindrome Linked List

ListNode *reverseList(ListNode *head){
    ListNode *prev = NULL, *current = head;

    while (current != NULL){
        ListNode *nextPtr = current->next;
        current->next = prev;
        prev = current;
        current = nextPtr;
    }
    return prev;
}

bool isPalindrome(ListNode *head){
    if (head == NULL || head->next == NULL)
        return true;

    ListNode *slow = head, *fast = head, *prev = NULL;

    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = NULL;
    ListNode *rev = reverseList(slow);
    ListNode *p = head;
    while (p != NULL){
        if (p->val != rev->val)
            return false;
        p = p->next;
        rev = rev->next;
    }
    return true;
}

// Que 4> Reverse Nodes in k-Group

ListNode *reverseList(ListNode *head, int k){
    ListNode *prev = NULL, *current = head;
    int count = 0;

    while (current != NULL){
        ListNode *nextPtr = current->next;
        current->next = prev;
        prev = current;
        current = nextPtr;
        count++;
        if (count == k)
            break;
    }
    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k){
    int count = 0;
    ListNode *temp = head;
    while (temp != NULL){
        count++;
        temp = temp->next;
        if (count == k)
            break;
    }
    if (count == k){
        ListNode *revHead = reverseList(head, k);
        head->next = reverseKGroup(temp, k);
        return revHead;
    }
    return head;
}

// Que 5> Partition List
ListNode *partition(ListNode *head, int x){

    if (head == NULL || head->next == NULL)
        return head;
    ListNode *afterNode = new ListNode(0);
    afterNode->next = head;
    ListNode *beforeNode = new ListNode(0);
    beforeNode->next = head;

    ListNode *after = afterNode;
    ListNode *before = beforeNode;

    while (head != NULL){
        if (head->val < x)
        {
            before->next = head;
            head = head->next;
            before = before->next;
        }
        else{
            after->next = head;
            head = head->next;
            after = after->next;
        }
    }
    after->next = NULL;
    before->next = afterNode->next;
    return beforeNode->next;
}
