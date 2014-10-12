/*
 * date: 2014-10-12
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/powx-n/
 */

#include <iostream>

using namespace std;

class Solution {
    public:
    double pow(double x, int n) {
        if(n == 0)
            return 1;
        bool neg = false;
        bool plus = false;
        if(n < 0) {
            neg = true;
            if( (n&0x7fff) == 0){
                plus = true;
                n = 0 - (n + 1);
            }else{
                n = 0 - n;
            }
        }
        double num = mul2(x,n);
        if(plus)
            num *= x;
        if(neg)
            num = 1 / num;
        return num;
    }
    double mul2(double x,int n){
        if(n == 1)
            return x;
        double num = 0;
        if( (n & 1) == 0){
            num = mul2(x,n>>1);
            return num * num;
        }else{
            num = mul2(x,n>>1);
            return num * num * x;
        }
    }
};

int main(){
    Solution sol;
    int n = -2147483648;
    double x = 1;
    cout<<"pow("<<x<<","<<n<<")"<<" = "<<sol.pow(x,n)<<endl;
}
