/*
 * date: 2014-10-08
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        return getHeight(root) > 0;
    }

    int getHeight(TreeNode* root){
        if(root == NULL) return 0;

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        if(left < 0 || right < 0 || abs(left - right) > 1)
            return -2;
        return 1 + (left > right ? left : right);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    /*
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(1);
    */
    root->left->right = new TreeNode(1);

    Solution sol;
    cout<<"Is balanced tree: "<<sol.isBalanced(root)<<endl;
}
