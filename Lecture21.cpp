#include "bits/stdc++.h"
using namespace std;


//Que 1
void insertAtBottom(stack<int> &stack,int ele){

    if(stack.empty()){
        stack.push(ele);
        return;
    }

    int top = stack.top();
    stack.pop();
    insertAtBottom(stack,ele);

    stack.push(top);

}

void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    // Write your code here
    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,top);
}



//Que 2
class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    list<int> dll;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    void moveToFirst(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        moveToFirst(key);
        return mp[key].second;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key].second=value;
            moveToFirst(key);
        }
        else{
            dll.push_front(key);
            mp[key]={dll.begin(), value};
            cap--;
        }
        if(cap<0){
            mp.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }
};

int main(){
    cout<<"Seems Nice.!"<<endl;
    return 0;
}