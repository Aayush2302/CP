#include<bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    stack<int> st;
    st.push(asteroids[n-1]);
    vector<int> ans;
    
    for(int i = n-2; i >= 0; i--) {
        if((st.top() + asteroids[i]) == 0) {
            st.pop();
        } else if(st.top() < asteroids[i]) {
            st.pop();
            st.push(asteroids[i]);
        } else {
            st.push(asteroids[i]);
        }
    }

    cout << st.size() << endl;

    // Corrected part: Properly emptying the stack
    while(!st.empty()) { 
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());  // Reverse because we pop in reverse order

    return ans;
}

int main() {
    vector<int> nums = {8,-8};
    vector<int> ans = asteroidCollision(nums);
    for(auto x: ans) {
        cout << x << " ";
    }
    return 0;
}
