class Solution {
public:

    void func(vector<int>& nums, int n, int idx,
              vector<int>& temp, vector<vector<int>>& ans) {

        // Base case
        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        // Don't take nums[idx]
        func(nums, n, idx + 1, temp, ans);

        // Take nums[idx]
        temp.push_back(nums[idx]);

        func(nums, n, idx + 1, temp, ans);

        // Backtrack
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;

        func(nums, n, 0, temp, ans);

        return ans;
    }
};