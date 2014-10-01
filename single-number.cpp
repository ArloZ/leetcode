/*
 * date: 2014-10-01
 * author: qile68@163.com
 */

#include <iostream>

using namespace std;

class Solution {

public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for(int i = 0; i < n; i++){
            result = result ^ A[i];
        }
        return result;
    }
};

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1};
    int n = sizeof(a)/sizeof(int);
    Solution sol;
    cout<<"Array length: "<<n<<endl;
    cout<<"Single Number is: "<<sol.singleNumber(a,n)<<endl;
    return 0;
}
