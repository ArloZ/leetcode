/*
 * date: 2014-10-01
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    int maxDepth(TreeNode *root) {
        return treeDepth(root);
    }
    int treeDepth(TreeNode* node){
        if(node == NULL)
            return 0;
        int left_hight = treeDepth(node->left) + 1;
        int right_hight = treeDepth(node->right) + 1;
        return left_hight > right_hight ? left_hight : right_hight;
    }
};

int main(){
    // create a tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(2);

    Solution sol;
    cout<<"Tree depth: "<<sol.maxDepth(root)<<endl;
    return 0;
}
