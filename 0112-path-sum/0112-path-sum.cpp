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
public:

    bool func (TreeNode* root , int sum , int targetSum){

        bool res = false ;

        if (root == NULL) return false ;

        sum = sum + root -> val ;

        if (root->left == NULL && root->right == NULL && sum == targetSum) return true;

        return func (root -> left , sum , targetSum) || func(root -> right , sum , targetSum);


    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        int sum = 0;

        return func(root , 0 , targetSum);
        
    }
};