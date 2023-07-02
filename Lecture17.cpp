#include "bits/stdc++.h"
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {                              // Using extra space
    map<Node*, Node*> mp;
    Node* temp = head;
    while (temp) {
        mp[temp] =new Node(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp) {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}

Node* copyRandomList(Node* head) {                              // Using pointers only
    Node* iter = head;
    Node* front = head;

    //Step 1 Code
    while(iter){
        front = iter->next;
        Node* copy = new Node(iter->val);
        copy->next = iter->next;
        iter->next = copy;
        iter = front;
    }

    //Step 2 Code
    iter = head;
    while(iter){
        if(iter->random){
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    //Step 3 Code
    iter = head;
    Node* dummy = new Node(0);
    Node* deepcopy = dummy;
    while(iter){
        front = iter->next->next;
        deepcopy->next = iter->next;
        iter->next = front;
        deepcopy = deepcopy->next;
        iter = front;
    }
    return dummy->next;
}


int main(){
    cout<<"Nice one"<<endl;
    return 0;
}