/*
 * date: 2014-10-07
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/maximum-subarray/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n < 1){
            return 0;
        }
        int max = A[0];
        int sum = max;
        for(int i = 1; i < n; i++){
            if(sum < 0){
                sum = A[i];
            }else{
                sum += A[i];
                if(sum < 0){
                    sum = 0;
                }
            }

            if(sum > max){
                max = sum;
            }
        }
        return max;
    }
};

int main(){
    //int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int A[] = {-1};
    int n = sizeof(A)/sizeof(int);
    Solution sol;
    cout<<"Array: ";
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<"The largest sum of array is: "<<sol.maxSubArray(A,n)<<" !"<<endl;
}
