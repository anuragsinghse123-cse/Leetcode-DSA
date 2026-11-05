#include<iostream>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*
Observation:
Use BFS (Level Order Traversal) to traverse the N-ary tree.
Maintain a queue to process nodes level by level.
For each level, store the current queue size to process
only the nodes belonging to that level.
Add each node's value to a separate vector and push all
its children into the queue for the next level.
Store the level vector in the answer.

Time: O(n)
Space: O(n)
*/

    vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<Node*>q;
    q.push(root);
    while(q.size()>0){
        vector<int>v;
        int n = q.size();
        for(int i =0;i<n;i++){
            Node* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            for(auto child : temp->children){
                q.push(child);
            }
        }
        ans.push_back(v);
    }
     return ans;
    }