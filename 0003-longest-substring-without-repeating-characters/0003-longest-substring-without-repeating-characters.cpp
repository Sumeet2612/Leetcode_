class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int res = 0;
        int n = s.size();
        unordered_map<int,int> count ; 
        for (int high = 0; high < n; high++){
            count[s[high]]++;
            int k = high-low + 1;
            while (count.size() < k){
                count[s[low]]--;
                if(count[s[low]]==0){
                    count.erase(s[low]);
                }
                low++;
                k = high - low + 1;
            }
            int len = high - low + 1;
            res = max(len , res);
        }
        return res; 
    }
};