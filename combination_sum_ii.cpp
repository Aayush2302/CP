#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>&ans,int target){
    // base case
    if(index >= nums.size()){
       if(target == 0){
        sort(output.begin(),output.end());
            auto it = find(ans.begin(),ans.end(),output);
            if(it == ans.end()){
                ans.push_back(output);
            }
       }
        return;
    }

    // exclude

    solve(nums,output,index+1,ans,target);

    // include

    int element = nums[index];
    if(element <= target){
        output.push_back(element);
        solve(nums, output,index+1,ans,target-element);
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        solve(nums,output,0,ans,8);
        return ans;
    }

int main(){
    vector<vector<int>>answer;
    vector<int>x = {10,1,2,7,6,1,5};

    answer = subsets(x);


    return 0;
}