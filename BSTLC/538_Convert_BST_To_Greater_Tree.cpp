#include<iostream>
#include<queue>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

    void helper(TreeNode* root,int &sum){
        if(root==NULL) return;
        helper(root->right,sum);
        root->val+=sum;
        sum = root->val;
        helper(root->left,sum);

    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root,sum);
        return root;
    }