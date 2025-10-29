




#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    
    for (auto &word : strs) {
        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());
        mp[sorted_word].push_back(word);
    }
    
    vector<vector<string>> result;
    for (auto &entry : mp)
        result.push_back(entry.second);
    
    return result;
}

int main() {
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groups = groupAnagrams(words);

    for (auto &group : groups) {
        for (auto &word : group)
            cout << word << " ";
        cout << endl;
    }
}









#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (auto &word : strs) {
        vector<int> count(26, 0);
        for (char c : word)
            count[c - 'a']++;
        
        string key = "";
        for (int num : count)
            key += "#" + to_string(num);
        
        mp[key].push_back(word);
    }

    vector<vector<string>> result;
    for (auto &entry : mp)
        result.push_back(entry.second);
    
    return result;
}

int main() {
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groups = groupAnagrams(words);

    for (auto &group : groups) {
        for (auto &word : group)
            cout << word << " ";
        cout << endl;
    }
}
