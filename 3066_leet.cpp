#include <bits/stdc++.h>

using namespace std;

int minOperations(vector<int>& nums, int k) {
    int n = nums.size();

    if (n == 1) {
        return nums[0] == k ? 0 : -1;
    }

    int count = 0;
    while (!nums.empty() && nums[0] < k) {
        sort(nums.begin(), nums.end());

        if (nums.size() < 2) return -1; // Prevent out-of-bounds access

        long long x = nums[0];  // Use long long
        long long y = nums[1];  // Use long long

        cout << x << " " << y << endl;

        nums.erase(nums.begin(), nums.begin() + 2); // Remove first two elements

        long long temp = min(x, y) * 2LL + max(x, y); // Prevent overflow
        nums.push_back(temp);
        count++;
    }

    return (!nums.empty() && nums[0] >= k) ? count : -1;
}

int main() {
    vector<int> nums = {999999999, 999999999, 999999999};
    int k = 1000000000;
    cout << minOperations(nums, k);
}
