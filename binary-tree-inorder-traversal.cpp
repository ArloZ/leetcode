/*
 * date: 2014-10-06
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack< pair<int,TreeNode*> > temppip;
        pair<int,TreeNode*> topNode;
        temppip.push(pair<int,TreeNode*>(1,root->right));
        temppip.push(pair<int,TreeNode*>(2,root));
        temppip.push(pair<int,TreeNode*>(1,root->left));
        while(!temppip.empty()){
            topNode = temppip.top();
            temppip.pop();
            if(topNode.second == NULL)
                continue;

            if(topNode.first == 1){
                temppip.push(pair<int,TreeNode*>(1,topNode.second->right));
                temppip.push(pair<int,TreeNode*>(2,topNode.second));
                temppip.push(pair<int,TreeNode*>(1,topNode.second->left));
            }else{
                result.push_back(topNode.second->val);
            }
        }
        return result;
    }
};

int main(){
    // create a tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(6);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);
    cout<<"Inorder Traversal: ";
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
