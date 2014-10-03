/*
 * date: 2014-10-03
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/reverse-integer/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // do not handle overflow of a integer number
    int reverse(int x) {
        char str[32] = {};
        char tmp;
        sprintf(str,"%d",x);
        int end = strlen(str) - 1;
        int begin = (str[0] == '-') ? 1 : 0;

        //reverse str
        while(begin < end){
            tmp = str[end];
            str[end] = str[begin];
            str[begin] = tmp;
            begin ++;
            end --;
        }

        return atoi(str);
    }
};

int main(){
    Solution sol;
    int a = -938200;
    cout<<"Reverse Integer: "<<a<<" to "<<sol.reverse(a)<<endl;
    return 0;
}
