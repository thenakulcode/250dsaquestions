// Approach 1 
// In this first we will check that the both length of the strings are equal or not 
// Then we will sort the string 
// If the ch are same we will return true otherwise false 
// The time complexity will be O(nlogn) and space will be O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: If lengths are not equal, they can’t be anagrams
        if (s.length() != t.length()) return false;

        // Step 2: Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Step 3: Compare the sorted strings
        return s == t;
    }
};

int main() {
    Solution sol;
    
    string s1 = "listen";
    string t1 = "silent";
    
    if (sol.isAnagram(s1, t1))
        cout << "True (They are anagrams)" << endl;
    else
        cout << "False (Not anagrams)" << endl;

    string s2 = "rat";
    string t2 = "car";
    
    if (sol.isAnagram(s2, t2))
        cout << "True (They are anagrams)" << endl;
    else
        cout << "False (Not anagrams)" << endl;

    return 0;
}



// Approach 2 using hash maps 
// Check length: If not equal → can’t be anagrams.

// Count difference: For every character in both strings:

// +1 for characters in s

// -1 for characters in t

// Validate: All counts must be 0 for a valid anagram.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Check if both strings have the same length
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Create a single hash map to track character frequencies
        unordered_map<char, int> count;

        // Step 3: Traverse both strings simultaneously
        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;  // Increment for character in s
            count[t[i]]--;  // Decrement for character in t
        }

        // Step 4: Verify that all counts are zero
        for (auto &p : count) {
            if (p.second != 0) {
                return false;  // Frequency mismatch found
            }
        }

        // Step 5: All checks passed, strings are anagrams
        return true;
    }
};

// Driver code for testing
int main() {
    Solution obj;
    string s = "listen";
    string t = "silent";

    if (obj.isAnagram(s, t))
        cout << "✅ The strings are anagrams." << endl;
    else
        cout << "❌ The strings are not anagrams." << endl;

    return 0;
}







// Approach 3
// 1. Length Check

// If the lengths of s and t are not equal, they cannot be anagrams.
// So we immediately return false
// 2. Use Frequency Array

// We create a vector<int> count(26, 0) to store the frequency of each lowercase letter ('a' to 'z').

// Each index i of the array represents a letter:
// 3. Count Characters Simultaneously

// We traverse both strings in a single loop.

// For each position i:

// Increase the count of the letter in s

// Decrease the count of the letter in t

// This way, if both strings have the same characters with the same frequencies,
// every increase (+1) will be canceled out by a decrease (-1)
//     4. Final Check
// The time and space will be O(n) and O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Check if lengths differ
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Create frequency array for 26 lowercase letters
        vector<int> count(26, 0);

        // Step 3: Update counts for both strings
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;  // increment for s
            count[t[i] - 'a']--;  // decrement for t
        }

        // Step 4: Check if all counts are zero
        for (int val : count) {
            if (val != 0) {
                return false;  // imbalance means not anagram
            }
        }

        // Step 5: All balanced → valid anagram
        return true;
    }
};

int main() {
    Solution sol;

    string s = "aabbcc";
    string t = "abcabc";

    if (sol.isAnagram(s, t)) {
        cout << "✅ The strings are anagrams." << endl;
    } else {
        cout << "❌ The strings are not anagrams." << endl;
    }

    return 0;
}




