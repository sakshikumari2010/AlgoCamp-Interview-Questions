#include<iostream>
#include<map>
using namespace std;

class ListNode{

    public:
        int key;
        int val;
        ListNode *next;
        ListNode *prev;

    ListNode(int key, int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;

    }
};

class LRUCache{ 

    public:
    int capacity;
    map<int, ListNode*> mpp;
    ListNode *head,*tail;
    LRUCache(int capacity){
            this->capacity = capacity;
            head = new ListNode(-1,-1);
            tail = new ListNode(-1,-1);
            head->next = tail;
            tail->prev = head;

    }

    int get(int key){
        
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        ListNode *node  = mpp[key];
        remove(node);
        add(node);
        return node->val;
    }

    void remove(ListNode *node){
        node->prev ->next = node->next;
        node->next->prev = node->prev;
        


    }

    void add(ListNode *node){
        node->prev = tail->prev;
        node->next = tail;
        tail->prev ->next = node;
        tail->prev = node;


    }



};