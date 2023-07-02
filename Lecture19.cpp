#include "bits/stdc++.h"
using namespace std;

//Ques 1
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> overlap_vector;
    for (int i = 0; i < intervals.size() - 1; i++) {
        if (intervals[i + 1][0] <= intervals[i][1]) {
            intervals[i + 1][0] = min(intervals[i][0], intervals[i + 1][0]);
            intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
        } else {
            overlap_vector.push_back(intervals[i]);
        }
    }
    overlap_vector.push_back(intervals.back()); // Add the last interval
    return overlap_vector;
}


//Ques 2
struct comp {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int i: nums){
        freq[i]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq(freq.begin(),freq.end());
    vector<int> result;
    for(int i=1;i<=k;i++){
        result.push_back(pq.top().first);
        pq.pop();
    }
    return result;
}

int main(){
    cout<<"Excellent"<<endl;
    return 0;
}