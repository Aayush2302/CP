#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void findsymmetric(vector<pair<int,int>>&pairs){
    unordered_map<int,int>mp;
    for(auto p:pairs){
        int first = p.first;
        int second = p.second;

        if(mp.find(second) != mp.end() && mp[second]==first){
            cout<<"("<<second<<","<<first<<")";
        }
        mp[first] = second;
    }
}

int main(){
    int n;
    cout<<"Enter Number:";
    cin>>n;

    vector<pair<int,int>>pairs(n);

    cout<<"Enter pairs (a b) separate by space\n";

    for(int i = 0; i<n; i++){
        cin>> pairs[i].first>>pairs[i].second;
    }

    findsymmetric(pairs);
    return 0;
}