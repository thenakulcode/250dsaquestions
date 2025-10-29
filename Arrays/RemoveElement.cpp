

// Approach 1 
// Time complexity: 

// O(n)
// Space complexity: 

// O(n)
// Create an empty vector result.

// Iterate through the original nums.

// If an element is not equal to val, push it into result.

// At the end, copy result back to nums (if you need to modify the original array) and return the new length.



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> result;  // New vector to store valid elements
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                result.push_back(nums[i]);  // Keep only valid elements
            }
        }

        // Optional: Copy back to original nums (to reflect in-place changes)
        nums = result;

        // Return the new length
        return result.size();
    }
};

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution sol;
    int k = sol.removeElement(nums, val);

    cout << "Remaining elements count: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}




// Approach 2 
// We’ll use two pointers:

// i — scans every element in the array

// k — marks the position where the next valid element should be placed

// If nums[i] != val, we copy it to nums[k] and move k forward.
// This effectively overwrites unwanted values and keeps valid ones in order.

// Time complexity: 
// O(n)
// Space complexity: 
// O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // placement pointer
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution sol;
    int k = sol.removeElement(nums, val);

    cout << "Remaining elements count: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}


// Approach 3

// // Time complexity: 
// // O(n)
// // Space complexity: 
// // O(1)

// If the order of elements doesn’t matter, we can remove elements more efficiently:

// Use two pointers:

// i → start (scan from beginning)

// n → end (marks the “current valid size” of array)

// Whenever we find an unwanted element (nums[i] == val):

// Replace it with the last element (nums[n-1])

// Reduce the valid size (n--)
// Don’t increment i, because the swapped element needs to be checked again


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[--n]; // replace with last element
            } else {
                i++;
            }
        }
        return n;
    }
};

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution sol;
    int k = sol.removeElement(nums, val);

    cout << "Remaining elements count: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}
