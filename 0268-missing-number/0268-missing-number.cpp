class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int mis = 0 ; 
        unordered_map<int , int> freq ;

        for (int i=0; i<nums.size(); i++){
            freq[nums[i]] ++ ;
        }

        for (int j=0; j<=nums.size(); j++){
            if(freq.find(j) == freq.end()){
                mis = j;
            }
            else {
                continue ;
            }

        }

        return mis ;
        
    }
};