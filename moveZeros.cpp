#include<bits/stdc++.h>

using namespace std;

void moveZero ( vector<int>nums){
    int low = 0;
    int high = 1;
    int n = nums.size();
    if(nums.size()==1)return;
    // if(nums.size()==2); 
    while(high != n ){
        if(nums[low]==0 && nums[high] != 0){
            swap(nums[low],nums[high]);
        }else{
            if(nums[low]!=0){
                low++;
            }else if(nums[high] ==0){
                high++;
            }
        }

    }
    for(auto x:nums){
        cout<<x<<" ";
    }
    // return nums;
}

int main()
{
    vector<int>nums={0,1,0,3,12};
    moveZero(nums);
}