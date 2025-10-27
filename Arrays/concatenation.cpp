
// in this approach we are creating the new array by repeating the given one  
// Time Complexity - o(n)
// Space Complexity - o(n)

#include <iostream>
#include <vector>
using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(2 * n);

    for (int i = 0; i < n; i++) {
        ans[i] = nums[i];       // First copy
        ans[i + n] = nums[i];   // Second copy
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> result = getConcatenation(nums);

    cout << "Concatenated array: ";
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}


// Approach 2 
// In this we are iterating 2 times over the input array and append each element to a new vector using push_back

// Time Complexity and Space complexity is O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < 2; ++i) {        // Outer loop runs 2 times
            for (int num : nums) {           // Inner loop iterates over nums
                ans.push_back(num);          // Add each num to ans
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};
    vector<int> result = obj.getConcatenation(nums);

    cout << "Result: ";
    for (int val : result)
        cout << val << " ";
    return 0;
}
