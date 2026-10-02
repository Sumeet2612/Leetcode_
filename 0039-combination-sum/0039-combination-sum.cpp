class Solution {
public:

    void func (vector<int> &candidates , int n , int idx , vector<int>&diary , int sum , vector<vector<int>> & res , int target){
       

        if (sum == target){
            res.push_back(diary);
            return ;
        }
        if (idx == n) return ;

        func(candidates , n , idx+1 , diary , sum , res , target);
        if (candidates[idx] + sum <= target){
            diary.push_back(candidates[idx]);
            sum = sum + candidates[idx];
            func (candidates , n , idx , diary , sum , res , target);
            diary.pop_back();
            sum = sum - candidates[idx];
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();
        vector<int> diary ; int idx = 0; int sum = 0;
        vector<vector<int>> res ;

        func(candidates , n , idx , diary , sum , res ,target);

        return res; 
        
    }
};