/*
 * date: 2014-10-06
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> temppip;
        TreeNode* topNode = NULL;
        temppip.push(root);
        while(!temppip.empty()){
            topNode = temppip.top();
            temppip.pop();
            if(topNode == NULL)
                continue;
            result.push_back(topNode->val);
            temppip.push(topNode->right);
            temppip.push(topNode->left);
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
    vector<int> result = sol.preorderTraversal(root);
    cout<<"Preorder Traversal: ";
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
