class Solution {
public:
    bool isPalindrome(string s) {
        // 1️⃣ Preprocess: remove non-alphanumeric & convert to lowercase
        string cleaned;
        for (char c : s) {
            if (isalnum(c)) cleaned.push_back(tolower(c));
        }

        // 2️⃣ Two-pointer check (simpler & faster than recursion here)
        int l = 0, r = cleaned.size() - 1;
        while (l < r) {
            if (cleaned[l] != cleaned[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};