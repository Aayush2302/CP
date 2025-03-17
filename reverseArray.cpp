#include<stdio.h>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void reverse(vector<int>&nums){
    int n = nums.size();

    if(n%2 != 0){
        n--;
    }


    for(int i = 0; i<n/2; i++){
        swap(nums[i],nums[n-i-1]);
    }

    for(auto x:nums){
        cout<<x<<" ";
    }
}

int main(){
    vector<int>nums = {1,2,3,4,5,6};
    reverse(nums);
}