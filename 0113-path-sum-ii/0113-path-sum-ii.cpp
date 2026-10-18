/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    vector<vector<int>> func(TreeNode* root , int targetSum , vector<int> diary , vector<vector<int>> res , int sum) {


        if(root == NULL) return res ;

        sum = sum + root -> val ;
        diary.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL){
            if(sum == targetSum){
                res.push_back(diary);
                diary.pop_back();
                return res ;
            }
        }
        res = func(root-> left , targetSum , diary , res , sum);
        res = func(root-> right , targetSum , diary , res , sum);

        return res;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        int sum = 0;
        vector<int> diary ;
        vector<vector<int>> res ;

        return func(root , targetSum , diary , res , 0);
        
    }
};