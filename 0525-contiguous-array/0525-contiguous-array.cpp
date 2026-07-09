class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // int n = nums.size();
        // int maxLen = 0;
       

        // for(int i=0; i<n; i++){
        //     int ones = 0;
        //     int zeroes = 0;
        //     for (int j=i; j<n; j++){
        //         if (nums[j]==0) zeroes++;
        //         else ones++;

        //         if (ones == zeroes){
        //             maxLen = max(maxLen , j-i+1);
        //         }
        //     }
        // }
        // return maxLen; Brute Force 

        int n = nums.size();
        int zero = 0;
        int one = 0;
        unordered_map<int , int> freq ;
        int res = 0;
        for (int i=0; i<n; i++){
            if (nums[i] == 0){
                zero++;
            }
            else one++;

            int diff = zero - one ;
            if(diff==0){
                res = max(res , i+1);
                continue ;
            }

            if(freq.find(diff) != freq.end()){
                res = max(res , i-freq[diff]);
            }
            else {
                freq[diff] = i ;
            }
        }
        return res ;
    }
};