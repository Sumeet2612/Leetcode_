class Solution {
public:
    int strStr(string haystack, string needle) {

        int i = 0;
        int j = 0;

        while (i < haystack.size()) {

            int start = i;

            while (i < haystack.size() &&
                   j < needle.size() &&
                   haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.size()) {
                return start;
            }

            i = start + 1;
            j = 0;
        }

        return -1;
    }
};