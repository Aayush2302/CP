#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        unordered_map<int, pair<int, int>> mp; // Stores two largest numbers for each digit sum

        for (auto x : nums) {
            int y = 0, num = x;
            while (num > 0) { 
                y += num % 10;
                num /= 10;
            }
            temp.push_back(y); 

            // Store the two largest numbers for each digit sum
            if (mp.find(y) == mp.end()) {
                mp[y] = {x, -1}; // First number added, second is empty
            } else {
                auto& p = mp[y];
                if (x > p.first) {  
                    p.second = p.first;  // Update second largest
                    p.first = x;  // Update first largest
                } else if (x > p.second) {  
                    p.second = x;  // Update second largest if it's greater than current second
                }
            }
        }

        int maxSum = -1;
        for (auto& x : mp) {
            if (x.second.second != -1) {  // Only consider if there are at least 2 numbers
                maxSum = max(maxSum, x.second.first + x.second.second);
            }
        }

        return maxSum;
    }
};

int main() {
    vector<int> nums = {368, 369, 307, 304, 384, 138, 90, 279, 35, 396, 114, 328, 251, 364, 300, 191, 438, 467, 183};
    Solution sol;
    cout << "Maximum Sum: " << sol.maximumSum(nums) << endl;
    return 0;
}
