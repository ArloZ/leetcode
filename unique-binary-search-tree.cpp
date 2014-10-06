/*
 * date: 2014-10-06
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/unique-binary-search-trees/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        if(n == 1)
            return 1;
        int totle = subNTrees(n);
        return totle;
    }
    int subNTrees(int n){
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        if(n == 3){
            return 5;
        }
        int totle = 0;
        int left = 1;
        int right = 1;
        for(int i = 1; i <= n; i ++) {
            if((i-1) > 1)
                left = subNTrees(i-1);
            else
                left = 1;
            if((n-i) > 1)
                right = subNTrees(n - i);
            else
                right = 1;
            totle += (left * right);
        }
        return totle;
    }
};

int main(){
    int n = 6;
    Solution sol;
    cout<<"With given n: "<<n << " Unique BSTs is: "<<endl<<sol.numTrees(n)<<endl;
    return 0;
}
