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

    int lh(TreeNode *root)
    {
        if(root==nullptr) return 0;
        int l=lh(root->left);
        int r=lh(root->right);

        return 1+max(l,r);
    }

     int maxi=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;

        int l=lh(root->left);
        int r=lh(root->right);

       

        maxi=max(maxi,l+r);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);


        return maxi;

    }
};