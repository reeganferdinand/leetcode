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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;

        if((root->val)==(p->val)) return p;
        else if((root->val)==(q->val))  return q;


        TreeNode *t1 = lowestCommonAncestor(root->left,p,q);
        TreeNode *t2 = lowestCommonAncestor(root->right,p,q);

        if(t1==nullptr) return t2;
        else if(t2==nullptr) return t1;

        else return root;
        
    }
};