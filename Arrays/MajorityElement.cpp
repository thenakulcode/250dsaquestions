// Approach 1 Time Complexity: O(n²) — two nested loops.

// Space Complexity: O(1) — no extra space used.
// Outer loop picks each element one by one.

// Inner loop counts its occurrences.

// If its count exceeds n/2, it’s our majority.


#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        if (count > n / 2) {
            return nums[i];
        }
    }
    return -1; // if no majority element (won't happen as per problem)
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 3, 3, 3};
    cout << "Majority Element: " << majorityElement(nums);
    return 0;
}




// Approach 2 
// Metric	Complexity	Explanation
// Time	O(n)	One pass through array, O(1) insert/lookup in hash map
// Space	O(n)	Extra space for frequency map
// We’ll use an unordered_map (hash table) to count how many times each element appears.

// Steps:

// Create an empty hash map freq.

// Traverse the array:

// For each element, increase its count in the map.

// After counting, traverse the map (or check during step 2 itself):

// If freq[element] > n/2, return that element.



#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();

    for (int num : nums) {
        freq[num]++;
        if (freq[num] > n / 2) {
            return num; // Early return if condition met
        }
    }
    return -1; // (not needed for this problem, as majority always exists)
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums);
    return 0;
}



// Approach 3 

// Initialize

// candidate = 0, count = 0

// Traverse array

// If count == 0: pick current element as new candidate, set count = 1

// Else if current element == candidate: count++

// Else: count--

// Result

// After the loop, candidate holds the majority element

// Intuition:

// Each vote for a different element cancels one vote of the candidate.

// Since the majority element appears more than half, it cannot be fully cancelled and survives to the end.

// Complexity:

// Time: O(n), Space: O(1) ✅


#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;
    int n = nums.size();

    // Step 1: Find candidate
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1; // ✅ directly start new candidate’s count
        } 
        else if (nums[i] == candidate) {
            count++;   // same as candidate → increment
        } 
        else {
            count--;   // different → cancel one vote
        }
    }

    // Step 2: Verify (optional if majority is guaranteed)
    int freq = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) freq++;
    }

    if (freq > n / 2)
        return candidate;
    
    return -1; // only if no majority exists
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums);
    return 0;
}
