/*
 * date: 2014-10-06
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
    stack<int> stock;
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int days = prices.size() - 1;
        for(int i = 0; i < days; i++) {
            if(stock.empty()){
                if(prices[i] <= prices[i + 1]) {
                    // buy stock
                    stock.push(prices[i]);
                }
            }else{
                if(prices[i] > prices[i + 1]){
                    // sell stock
                    profit += (prices[i] - stock.top());
                    stock.pop();
                }
            }
        }
        // sell the last day
        if(!stock.empty()){
            profit += (prices[prices.size()-1] - stock.top());
            stock.pop();
        }
        return profit;
    }
};

int main(){
    vector<int> prices;
    prices.push_back(3);
    prices.push_back(4);
    prices.push_back(7);
    prices.push_back(3);
    prices.push_back(5);
    prices.push_back(3);

    Solution sol;
    cout<<"Max Profit: "<<sol.maxProfit(prices)<<endl;

    return 0;
}
