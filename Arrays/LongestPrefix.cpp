
// Approach 1 Brute force
// Use the first string as a reference.

// Compare each character position across all strings.

// Stop when any string differs or ends.

// Return the part of the first string before the mismatch.





#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Loop through characters of the first string
    for (int i = 0; i < strs[0].size(); i++) {
        char ch = strs[0][i]; // Current character to compare

        // Compare this character with all other strings
        for (int j = 1; j < strs.size(); j++) {
            // If index is out of range OR mismatch occurs
            if (i >= strs[j].size() || strs[j][i] != ch) {
                return strs[0].substr(0, i); // Return prefix till now
            }
        }
    }

    // If loop completes, the whole first string is the prefix
    return strs[0];
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}



