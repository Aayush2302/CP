#include<bits/stdc++.h>

using namespace std;

void countingFreq(vector<int>nums){
    unordered_map<int,int>mp;

    for(auto x:nums){
        mp[x]++;
    }

    for( auto x:mp){
        cout<<x.first<<" "<<x.second<<endl;
    }

}

int main(){
    vector<int>nums={10,11,10,12,13,13,13};
    countingFreq(nums);
}