/*
 * date: 2014-10-08
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/integer-to-roman/
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
    map<int,string> num_map;
public:
    Solution(){
        num_map[1] = "I";
        num_map[5] = "V";
        num_map[10] = "X";
        num_map[50] = "L";
        num_map[100] = "C";
        num_map[500] = "D";
        num_map[1000] = "M";
    }
    string intToRoman(int num) {
        string str;
        if(num < 1 || num > 3999)
            return str;
        string label, character;
        int quotient = 0;
        int i;
        while(num > 0){
            for(i = 1000; i > 0 ; i /= 10){
                quotient = num / i;
                if(quotient < 4){
                    while(quotient --){
                        str += num_map[i];
                    }
                }else if(quotient < 5){
                    str += num_map[i] + num_map[i*5];
                }else if(quotient < 9){
                    str += num_map[i*5];
                    quotient -= 5;
                    while(quotient --){
                        str += num_map[i];
                    }
                }else{
                    str += num_map[i] + num_map[i*10];
                }
                num %= i;
            }
        }

        return str;
    }
};

int main(){
    int num;
    cout<<"please input int value: ";
    cin>>num;
    Solution sol;
    cout<<"The roman number: "<<sol.intToRoman(num)<<" with integer value: "<<num<<" !"<<endl;

}
