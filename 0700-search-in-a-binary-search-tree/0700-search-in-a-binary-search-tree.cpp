
class Solution {
public:
    TreeNode* func(TreeNode* node, int val) {
        if (node == nullptr) return nullptr;

        if (node->val == val) {
            return node;
        }

        if (val < node->val) {
            return func(node->left, val);
        } else {
            return func(node->right, val);
        }
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return func(root, val);
    }
};
