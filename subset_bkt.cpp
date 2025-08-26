#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>&ans){
    // base case
    if(index >= nums.size()){
        for(auto a:output){
            cout<<a;
        }
        cout<<endl;
        ans.push_back(output);
        return;
    }

    // exclude

    solve(nums,output,index+1,ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output,index+1,ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        solve(nums,output,0,ans);
        return ans;

    }

int main(){
    vector<vector<int>>answer;
    vector<int>x = {10,1,2,7,6,1,5};

    answer = subsets(x);

    for(auto a:answer){
        
    }

    return 0;
}