/*
 * date: 2014-10-07
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/single-number-ii/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n < 2)
            return A[0];
        int n1 = 0, n2 = 0, n3 = 0;
        // mod 3 use bits
        for (int i = 0; i < n; ++i)
        {
            /*
            n1 = (n1 & ~A[i]) | (~n1 & ~n2 & A[i]);
            n2 = (n2 & ~A[i]) | (~n1 & ~n2 & A[i]);
            */
            n1 = n1 | A[i];
            n2 = n2 ^ A[i];
            n3 = n2 & A[i] ^ n3;
            n1 = n1 & n3;
            n2 = n2 & n3;
        }
        return n3;
    }
};

int main(){
    //int A[] = {1,1,1,2,2,2,3,4,4,4};
    int A[] = {2,2,3,4,4,2,4};
    //int A[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
    int n = sizeof(A)/sizeof(int);

    cout<<"Array: ";
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    Solution sol;
    cout<<"The single number is: "<<sol.singleNumber(A,n)<<" !"<<endl;

}
