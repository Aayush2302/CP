#include<bits/stdc++.h>

using namespace std;

int maxSubarraySum(vector<int>&nums,int k){
    int maxSUM = 0;

    for(int i = 0; i<=k;i++){
        maxSUM+=nums[i];
    }

    for(int i = 0; i< nums.size()-k; i++){
        // cout<<nums[i]<<" "<<nums[k+i]<<endl;
        int temp = maxSUM - nums[i] + nums[k+i];
        cout<<"Temp"<<temp<<endl;
        maxSUM = max(maxSUM,temp);
    }
    return maxSUM;
}

int main(){
    vector<int>nums = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int result = maxSubarraySum(nums, k);
    cout << result << endl; // Output: 9
    return 0;
}