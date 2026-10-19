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

    bool func(TreeNode* root ,TreeNode* &prev ,  bool &ans){
        if(root == NULL) return true ;

        func(root -> left , prev , ans) ;

        if(prev == NULL) prev = root ;
        else {
            if (root -> val <= prev -> val){
                ans = false;
            }
            prev = root;
        }
        func(root -> right , prev , ans);

        return ans ;
    }

    bool isValidBST(TreeNode* root) {

        TreeNode* prev = NULL ;
        bool ans = true ;

        func(root , prev , ans);

        return ans;

        
    }
};