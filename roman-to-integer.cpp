/*
 * date: 2014-10-07
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/roman-to-integer/
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
    map<string,int> num_map;
public:
    Solution(){
        num_map["I"] = 1;
        num_map["V"] = 5;
        num_map["X"] = 10;
        num_map["L"] = 50;
        num_map["C"] = 100;
        num_map["D"] = 500;
        num_map["M"] = 1000;
    }
    int romanToInt(string s) {
        int end = s.length() -1;
        int num = 0;
        string label, character;
        while(end >= 0){
            character = s[end--];
            // character is invalid
            if(num_map.find(character) == num_map.end()){
                return -1;
            }
            if(label.length() == 0){
                label = character;
                num = num_map[character];
                continue;
            }
            if(num_map[label] > num_map[character]){
                num -= num_map[character];
            }else{
                num += num_map[character];
                label = character;
            }
        }
        return num;
    }
};

int main(){
    string str;
    cout<<"please input roman: ";
    cin>>str;
    Solution sol;
    cout<<"The roman number: "<<str<<" is: "<<sol.romanToInt(str)<<" !"<<endl;

}
