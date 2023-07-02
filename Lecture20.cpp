#include "bits/stdc++.h"
using namespace std;


//Que 1
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    vector<int> next(nums2.size());
    for(int i=nums2.size()-1;i>=0;i--){
        while(!st.empty()){
            if(st.top()>nums2[i]){
                next[i]=st.top();
                st.push(nums2[i]);
                break;
            }
            else{
                st.pop();
            }
        }
        if(st.empty()){
            st.push(nums2[i]);
            next[i]=-1;
        }
    }

    vector<int> res;
    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            if(nums1[i]==nums2[j]){
                res.push_back(next[j]);
            }
        }
    }
    return res;
}


//Que 2
void getNextSmallerIdx(vector<int>& res, vector<int>& heights){
    stack<int> s1;
    s1.push(-1);

    for(int i=n-1; i>=0; i--){
        int curr = heights[i];
        while(s1.top() != -1 and heights[s1.top()] >= curr){
            s1.pop();
        }

        res[i] = s1.top();
        s1.push(i);
    }
}

void getPrevSmallerIdx(vector<int>& res, vector<int>& heights){
    stack<int> s1;
    s1.push(-1);

    for(int i=0; i<n; i++){
        int curr = heights[i];
        while(s1.top() != -1 and heights[s1.top()] >= curr){
            s1.pop();
        }

        res[i] = s1.top();
        s1.push(i);
    }
}
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int res = 0;
    vector<int> nextSmaller(n), prevSmaller(n);

    getNextSmallerIdx(nextSmaller, heights);
    getPrevSmallerIdx(prevSmaller, heights);

    for(int i=0; i<n; i++){
        int currL = heights[i];
        if(nextSmaller[i] == -1) nextSmaller[i] = n;

        int currB = nextSmaller[i] - prevSmaller[i] - 1;
        int area = currL * currB;
        res = max(area, res);
    }

    return res;
}



int main(){
    cout<<"Good one"<<endl;
    return 0;
}