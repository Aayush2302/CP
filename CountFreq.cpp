#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    vector<int>nums = {1,2,2,1,4,6,4,3,2,1,4,3,2};
    unordered_map<int,int>mp;

    for(auto x:nums){
        mp[x]++;
    }

    for(auto x:mp){
        cout<<x.first<<" "<<x.second<<endl;
    }
}