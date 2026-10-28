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
Observation: Store nodes in preorder (Root -> Left -> Right)
using a queue. Connect consecutive nodes using right pointers
and set left = NULL.

Time: O(n)
Space: O(n)
*/


void helper(TreeNode* root,queue<TreeNode*>&q){
     if(root==NULL) return;
     q.push(root);
     helper(root->left,q);
     helper(root->right,q);
    }
    void flatten(TreeNode* root) {
    if(root==NULL) return;
     queue<TreeNode*>q;
     helper(root,q);
     TreeNode*temp = q.front();
     q.pop();
     while(q.size()>0){
        temp->right = q.front();
        q.pop();
        temp->left = NULL;
        temp = temp->right;
     }
     temp->left = NULL;
     
    }


/*
Approach -2- use recursion 
Time complexity  = O(n)
Space Complexity = O(n)

Observation: Flatten the tree in preorder (Root -> Left -> Right).
Find the rightmost node of the left subtree and connect it
to the original right subtree. Move left to right and set left = NULL.
*/


void flatten(TreeNode* root) {
    if(root==NULL) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode* r = root->right;
    root->right = root->left;
    root->left = NULL;
    TreeNode* temp = root;
    while(temp->right) temp = temp->right;
    temp->right = r;
    }


/*
Approach -3 likely to morris traversal 
 Time complexity = O(n)
 Space Complexit = O(1)
  Steps: 
  save right, find pred, link 

*/

void flatten(TreeNode* root) {
    if(root==NULL) return;
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left){
            // save the right 
            TreeNode * r = curr->right;
            curr->right = curr->left;
            // finding pred
            TreeNode* pred = curr->left;
            while(pred->right) pred = pred->right;
            // link
            pred->right = r;
            curr= curr->left;
        }
        else curr = curr->right;
    }
    curr = root;
    while(curr){
        curr->left = NULL;
        curr = curr->right;
    }
    }