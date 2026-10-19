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

    int func(TreeNode* root ,  int &res ){

        if (root == NULL) return 0 ;
        int left = func(root -> left , res);
        int right = func(root -> right , res);
        res = max(res , left+ right);

        return max(left , right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        func(root , res);

        return res;

        
    }
};