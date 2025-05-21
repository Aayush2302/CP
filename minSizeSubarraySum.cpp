#include<bits/stdc++.h>

using namespace std;


int minSubArrayLen(int target, vector<int>& nums){
    int temp=0;
    int size = nums.size();
    int minLength = INT_MAX;
    int start = 0;
    int end = 0;
    for(end = 0; end< size; end++){

        temp += nums[end];

        while(temp >= target){
            minLength = min(minLength, end - start + 1);
            temp -= nums[start];
            start++;
        }
    }
    if(minLength == INT_MAX){
        return 0;
    }   
    return minLength;
}
int main()
{
    vector<int>nums = {2,3,1,2,4,3};
    int target = 7;
    cout<<minSubArrayLen(target, nums)<<endl; // Output: 2
}