/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int func(TreeNode* node , TreeNode* p , TreeNode* q , TreeNode* &ans){

        if (node == NULL) return 0 ;

        int left = func(node -> left , p , q , ans) ;
        int right = func(node -> right , p , q , ans);
        int self = 0; int total = 0;
        if (node == p || node == q) self = 1;

        total = left + right + self ;

        if (total == 2 && ans == NULL) {
            ans = node;
        }
        return total ;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* ans = NULL;
        
        func(root, p , q , ans);

        return ans;
    }
};