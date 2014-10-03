/*
 * date: 2014-10-01
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/single-number/
 */

#include <iostream>

using namespace std;

class Solution {

public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for(int i = 0; i < n; i++){
            // xor for every elements because of the same number xor it self get 0
            result = result ^ A[i];
        }
        return result;
    }

    // a upgrade for singlenumber problem: two different number in a array
    pair<int,int> twoDiffNumber(int B[], int n){
        int result = 0;
        for(int i = 0; i < n; i++){
            result = result ^ B[i];
        }
        int mask = 1;
        while((result & mask) == 0){
            mask = mask << 1;
        }
        result = 0;
        int result2 = 0;
        for(int i = 0; i < n; i++){
            // put into two array ensure that the two different number in each array
            if((B[i] & mask) == 1){
                result = result ^ B[i];
            }else{
                result2 = result2 ^ B[i];
            }
        }
        return pair<int,int>(result,result2);
    }
};

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1};
    int b[] = {10,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1};
    int n = sizeof(a)/sizeof(int);
    int nb = sizeof(b)/sizeof(int);
    Solution sol;
    cout<<"Array length: "<<n<<endl;
    cout<<"Single Number is: "<<sol.singleNumber(a,n)<<endl;
    pair<int,int> res = sol.twoDiffNumber(b,nb);
    cout<<"Two Number is: "<<res.first<<" and "<<res.second<<endl;
    return 0;
}
