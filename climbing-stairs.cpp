/*
 * date: 2014-10-07
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/climbing-stairs/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n < 2)
            return 1;
        int ele1 = 1;
        int ele2 = 1;
        int totle = ele1 + ele2;
        int pre = 0;
        for(int i = 2; i <= n; i++){
            totle = ele1 + ele2;
            pre = totle;
            ele2 = ele1;
            ele1 = pre;
        }
        return totle;
    }
};

int main(){
    int n = 6;
    Solution sol;
    cout<<"Climbing "<<n<<" stairs needs "<<sol.climbStairs(n)<<" steps!"<<endl;
}
