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


/*
Observation: Merge two binary trees by adding corresponding
node values. If one node is NULL, return the other subtree.
Recursively merge left and right children.

Time: O(n + m)
Space: O(h)
*/


TreeNode* helper(TreeNode* root1 ,TreeNode* root2){
    if(!root1 && !root2 ) return NULL;
        if(!root1 || !root2){
            if(root1) return root1;
            else return root2;
    }
    TreeNode * temp = new TreeNode(root1->val + root2->val);
    temp->left = helper(root1->left,root2->left);
    temp->right = helper(root1->right,root2->right);
    return temp;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    return helper(root1,root2);
    }