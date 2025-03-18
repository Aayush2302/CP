#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool subset(vector<int>nums1,vector<int>nums2){
    
    // unordered_map<int,int>mp;
    int n1 = nums1.size();
    int n2 = nums2.size();


    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());


    int low=0,high=0;
    while (high < n1 && nums2[low] != nums1[high]) {
        high++;
    }
    while (high < n1) {
        
        if(nums2[low] == nums1[high]){
            low++;
            high++;
        }else{
            high++;
        }
    }

    if(low == n2)return true;

    return false;
    
}

int main(){

    vector<int>nums1 = {1, 2, 3, 4, 5, 6};
    vector<int>nums2 = {1,2,4};

    bool res = subset(nums1,nums2);
    if(res)cout<<"Subset is true";
    else{
        cout<<"Not a subset";
    }
}