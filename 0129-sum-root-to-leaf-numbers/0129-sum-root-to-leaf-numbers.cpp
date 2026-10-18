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

    int func(TreeNode* root , int sum , int res){
        if(root == NULL) return res;

        sum = sum * 10 + root -> val ;
        if(root -> right == NULL && root -> left == NULL){
            res = res + sum ;
        }
        res = func(root -> left , sum , res );
        res = func(root -> right , sum , res);

        return res ;
    }
    int sumNumbers(TreeNode* root) {

        int res = 0;
        int sum = 0;
        
        return func(root , 0 , 0);
        
    }
};