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

// Approach :
/*
Observation:
Use DFS to traverse the entire binary tree.
Check whether the current node has a left child.
If the left child is a leaf node (both left and right
children are NULL), add its value to the sum.
Recursively traverse the left and right subtrees
to find all left leaves.

Time: O(n)
Space: O(h) due to recursion stack.
*/
    void helper(TreeNode* root ,int & sum){
        if(root==NULL) return;
       if(root->left){
        if(!root->left->left && !root->left->right)
         sum+=root->left->val;
         }
        helper(root->left,sum);
        helper(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        int sum = 0;
        helper(root,sum);
        return sum;
   
    }