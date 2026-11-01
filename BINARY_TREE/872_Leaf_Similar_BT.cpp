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
Observation:
Use DFS to traverse both trees and store leaf node
values (Left -> Right) in separate vectors.
Compare both vectors to check whether the leaf
sequences are identical.

Time: O(n + m)
Space: O(n + m)
*/

    void helper(TreeNode* root ,vector<int>&ans){
      queue<TreeNode*>q;
      q.push(root);
      while(q.size()>0){
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left==NULL && temp->right==NULL) ans.push_back(temp->val);
        if(temp->left) helper(temp->left,ans);
        if(temp->right) helper(temp->right,ans);
      }

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1;
        vector<int>ans2;
        helper(root1,ans1);
        helper(root2,ans2);

        return ans1 == ans2;
    }