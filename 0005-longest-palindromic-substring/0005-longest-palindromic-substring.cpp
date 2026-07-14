class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;

        for (int center = 0; center < s.size(); center++) {
            // Odd length: two pointers start at same index
            int len1 = expand(s, center, center);
            // Even length: two pointers start adjacent
            int len2 = expand(s, center, center + 1);

            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = center - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    // classic two-pointer expansion
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;   // pointer 1 moves left
            right++;  // pointer 2 moves right
        }
        return right - left - 1;  // length when loop stops
    }
};