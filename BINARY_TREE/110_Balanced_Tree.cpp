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

// Approach 1 :
/*
Observation: Calculate the height of left and right subtrees
at every node. If their difference exceeds 1, return false.
Recursively check all nodes.

Time: O(n^2)
Space: O(h)
*/
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    bool helper(TreeNode* root){
        if(root==NULL) return true;
        int l = level(root->left);
        int r = level(root->right);
        if(abs(l-r)>1) return false;
        return helper(root->left) && helper(root->right);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root);
    }

// Approach - 2 :
/*
Observation: Calculate height using DFS and check balance
simultaneously. Return -1 if any subtree is unbalanced;
otherwise return the current subtree height.

Time: O(n)
Space: O(h)
*/

    int helper1(TreeNode* root){
        if(root==NULL) return 0;
        int l = helper1(root->left);
        if(l==-1) return l;
        int r = helper1(root->right);
        if(r==-1) return r;
        if(abs(l-r)>1) return -1;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        return helper1(root)!=-1;
    }