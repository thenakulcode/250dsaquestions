// Approach 1 
// We store the size of the array
// Outer loop which will select first element of the pair 
// Inner loop picks the second element of the pair
//    Then for each pair we will run a condition that they are equal to the target or not 
//    If they are equal return their idx
//    if not return{}
//    The time Complexity is O(n2) and Space is O(1)



#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size(); 
    for (int i = 0; i < n; i++) {               
        for (int j = i + 1; j < n; j++) {       
            if (nums[i] + nums[j] == target) {  
                return {i, j};                   
            }
        }
    }
    return {}; 
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}






// Approach 2
// Create a hash map to store key(value) and its value(idx)
// Loop through the array 
//   We will find moreReq for every element 
//   Check if that moreReq is in the map or not 
//   If it is there return idx which return {seen[moreReq],i}
//   If it is not store the element in the map with its idx 

// Otherwise return false
// The time complexity of this code will be O(n) and the space complexity will be O(n)


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // key = number, value = index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // the number we need
        if (seen.find(complement) != seen.end()) {
            // Found complement → return indices
            return {seen[complement], i};
        }
        // Otherwise, store the current number with its index
        seen[nums[i]] = i;
    }

    return {}; // no pair found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}






// Approach 3
// Sorting 
// We will create a vector of pairs which will store the value and idx
// Then we run a loop to put all the elements in the array with their idx
// Then we sort the array 
// Initialze two pointer left pointing the first element and Right pointing the last element 
// Run a while loop till left< Right 
//     we will calculate sum of left and right array elements 
//     if My sum == target then we will return idx 
//     if sum is less decremnt the left pointer 
//     else Increment the right pointer 

// If nothing found return{}
// The time complexity of this code is O(nLogn) and space is O(n)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSumSorted(vector<int>& nums, int target) {
    vector<pair<int, int>> arr; // {value, original_index}

    for (int i = 0; i < nums.size(); i++) {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end()); // sort by value

    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left].first + arr[right].first;

        if (sum == target) {
            return {arr[left].second, arr[right].second}; // original indices
        } 
        else if (sum < target) {
            left++;  // need a bigger sum
        } 
        else {
            right--; // need a smaller sum
        }
    }
    return {};
}

int main() {
    vector<int> nums = {3, 8, 12, 4, 7, 9, 11};
    int target = 15;

    vector<int> res = twoSumSorted(nums, target);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;

    return 0;
}
