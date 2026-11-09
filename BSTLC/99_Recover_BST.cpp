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


// Approach 1: Inorder Traversal using Vector
/*
Inorder traversal of BST gives sorted order.
Store all nodes in a vector and find the misplaced nodes.
If two nodes are swapped, there will be one or two inversions.
Finally, swap the values of the misplaced nodes.

Time Complexity: O(N)
Space Complexity: O(N)
*/

    void helper(TreeNode* root, vector<TreeNode*>& temp) {
        if(root == NULL) return;

        helper(root->left, temp);
        temp.push_back(root);
        helper(root->right, temp);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> temp;
        helper(root, temp);

        TreeNode* temp1 = NULL;
        TreeNode* temp2 = NULL;

        for(int i = 1; i < temp.size(); i++) {
            if(temp[i-1]->val > temp[i]->val) {
                if(!temp1) temp1 = temp[i-1];
                temp2 = temp[i];
            }
        }
        swap(temp1->val, temp2->val);
    }



//Approach 2: Inorder Traversal using DFS (Recursion)
/*
Inorder traversal of BST gives sorted order.
Use prev to track the previously visited node.
If prev->val > curr->val, an inversion is found.
Store the first misplaced node in temp1 and update temp2
whenever another inversion is found.
Finally, swap their values.

Time Complexity: O(N)
Space Complexity: O(H) - Recursion Stack
*/

    void helper(TreeNode* root,TreeNode* &temp1 ,TreeNode* &temp2,TreeNode* &prev) {
        if(root == NULL) return;

        helper(root->left, temp1,temp2,prev);
        if(root && !prev) prev = root;
        else if(root && prev->val>root->val){
            if(!temp1) temp1 = prev;
            temp2 = root;
        }
            prev = root;

        helper(root->right, temp1,temp2,prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* temp1 = NULL;
        TreeNode* temp2 = NULL;
        helper(root, temp1,temp2,prev);
        swap(temp1->val, temp2->val);
    }


//Approach 3: Morris Inorder Traversal
/*
Morris traversal performs inorder traversal without recursion or stack.
Find the inorder predecessor and create temporary threads.
Use prev to detect inversions and identify the misplaced nodes.
Remove every temporary thread while traversing.
Finally, swap the values of the misplaced nodes.

Time Complexity: O(N)
Space Complexity: O(1) - Auxiliary Space
*/

    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* temp1 = NULL;
        TreeNode* temp2 = NULL;
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
            TreeNode* pred = curr->left;
             while(pred->right && pred->right!=curr) pred = pred->right;
             if(!pred->right){
                pred->right = curr;
                curr= curr->left;
             }
            
            else {
              pred->right = NULL;
              if(prev && prev->val > curr->val){
                if(!temp1) temp1 = prev;
                temp2 = curr;
              }
              prev = curr;
              curr = curr->right;
            }
            }
            else{
                if(prev && prev->val>curr->val){
                    if(!temp1) temp1 = prev;
                    temp2 = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
        swap(temp1->val,temp2->val);
    }