#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rearange(vector<int>nums){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for(int i = 0; i<=(n/2-1) ; i++){
        cout<<nums[i]<<" ";
    }
    for(int j = n-1; j>=n/2 ; j--){
        cout<<nums[j]<<" ";
    }
}

int main(){
    vector<int>nums={4,2,8,6,15,5,9,20};
    rearange(nums);
}