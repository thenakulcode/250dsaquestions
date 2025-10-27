// Brute Force 
// Approach in this we use 2 nested loops the outer loop will select one element and the inner loop will
//  compare that element that comes after nums[i]
// if any 2 are equal then the duplicate is found otherwise false The time complexity is o(n2) and space is o(1)

#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();

    // Compare every pair of elements
    for (int i = 0; i < n - 1; i++) {           // outer loop
        for (int j = i + 1; j < n; j++) {       // inner loop
            if (nums[i] == nums[j]) {           // check if duplicate found
                return true;
            }
        }
    }
    return false;  // no duplicates
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 2};

    if (containsDuplicate(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}


// Approach 2 
// Sort the array
// Loop throught the array 0 to n-2
// Compare each element with the next one if it is same return true 
// Otherwise false The time and space complexity O(nlogn) and O(1)


#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Step 1: Sort the array
    
    for (int i = 0; i < nums.size() - 1; i++) { // Step 2: Compare neighbors
        if (nums[i] == nums[i + 1]) {           // If any two adjacent are same
            return true;                        // Duplicate found
        }
    }
    return false;                               // No duplicates found
}

int main() {
    vector<int> nums = {3, 1, 4, 2, 3};

    if (containsDuplicate(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}



// Approach 3 is Hash set 
// We are declearing a hash set seen
// Loop through the array check that the element is already in the set 
// IF it is return true and insert the element in the set and if is not return false
// The time Complexity is O(n) and space is O(n)


#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen; // Step 1: Create a hash set
    
    for (int i = 0; i < nums.size(); i++) { // Step 2: Traverse the array
        if (seen.find(nums[i]) != seen.end()) { // Step 3: If already in set
            return true; // Duplicate found
        }
        seen.insert(nums[i]); // Step 4: Otherwise, add it to the set
    }
    
    return false; // Step 5: No duplicates found
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 2};

    if (containsDuplicate(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}
