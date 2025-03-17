#include<stdio.h>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int>nums){

    int min = INT_MAX,secondMin = INT_MAX;
    int max = INT_MIN, secondMax = INT_MIN;

    for(int i = 0; i<nums.size();i++){
        if(nums[i]<min ){
            min = nums[i];
        }else if(nums[i]>max)
        {
            max = nums[i];
        }
        continue;
    }

    for(int i = 0;i<nums.size(); i++){
        if(nums[i]<secondMin && nums[i]!=min){
            secondMin = nums[i];
        }
        else if(nums[i]>secondMax && nums[i]!=max){
            secondMax = nums[i];
        }
    }

    cout<<"First= "<<min<<"second= "<<secondMin<<endl;
    cout<<"First= "<<max<<"second= "<<secondMax<<endl;

    return min;
}

int main(){
    vector<int>nums={5,3,1,4,5,-6};
    cout<<solution(nums);
}