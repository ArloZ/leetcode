/*
 * date: 2014-10-08
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() <= 0) return NULL;
        TreeNode* root = createBST(num,0,num.size()-1);
        return root;
    }
    TreeNode* createBST(vector<int>& num,int begin,int end){
        if(begin > end){
            return NULL;
        }
        int mid = (end + begin)/2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = createBST(num,begin,mid - 1);
        root->right = createBST(num,mid + 1,end);
        return root;
    }
};

void preTraversal(TreeNode* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preTraversal(root->left);
    preTraversal(root->right);
}
void inTraversal(TreeNode* root){
    if(root == NULL) return;
    preTraversal(root->left);
    cout<<root->val<<" ";
    preTraversal(root->right);
}

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);

    Solution sol;

    TreeNode* root = sol.sortedArrayToBST(num);

    cout<<"preTraversal:"<<endl;
    preTraversal(root);
    cout<<endl<<"inTraversal:"<<endl;
    inTraversal(root);
    cout<<endl;

    return 0;
}
