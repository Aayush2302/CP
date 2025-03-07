#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int longestSubarray(vector<int>& nums) {
        int low = 0; 
        int high = 0;
        int i = 0;
        int countZero = 0;
        while(high<nums.size()){
           if(nums[high] == 0){
                countZero++;

           }
           if(countZero>1){
            if(nums[low] == 0){
                countZero--;
            }
            low++;
           }
              high++;
        }
        return high - low - 1;
}

int main(){
    vector<int>nums = {1,1,1};
    cout << longestSubarray(nums);
    return 0;
}
