#include "bits/stdc++.h"
using namespace std;

//Ques 1
bool isValid(string s) {
    if(s.empty()){
        return true;
    }
    stack<char> st;
    for(char i : s){
        if(i=='(' || i=='{' || i=='['){
            st.push(i);
        }
        else{
            if((!st.empty())&&((st.top()=='(' && i==')') || (st.top()=='{' && i=='}') || (st.top()=='[' && i==']'))){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}


//Ques 2
int minSwaps(string s) {
    stack<char> st;

    for(char ch : s){
        if(ch=='['){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    return ((st.size()/2)+1)/2;
}

int main(){
    cout<<"Good one"<<endl;
    return 0;
}