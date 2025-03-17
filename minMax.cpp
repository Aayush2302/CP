#include<stdio.h>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int>nums){

    int min = INT_MAX;
    for(int i = 0; i<nums.size();i++){
        if(nums[i]<min ){
            min = nums[i];
        }else
        continue;
    }

    return min;
}

int main(){
    vector<int>nums={5,3,1,4,5,-6};
    cout<<solution(nums);
}