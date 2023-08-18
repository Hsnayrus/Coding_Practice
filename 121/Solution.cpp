#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>

/*
You are given an array prices where prices[i] is the price of a given stock on
the ith day.

You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
6-1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because
you must buy before you sell. Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

class Solution {
  private:
    size_t findHighestElementIndex(size_t startIndex,
                                   std::vector<int>& prices) {
        size_t maxElementIndex = startIndex;
        for (size_t i = startIndex; i < prices.size(); i++) {
            if (prices[maxElementIndex] < prices[i]) {
                maxElementIndex = i;
            }
        }
        return maxElementIndex;
    }

  public:
    int maxProfit(std::vector<int>& prices) {
        int currentDifference = 0;
        int maxDifference = 0;
        for (size_t i = 0; i < prices.size(); i++) {
            currentDifference =
                prices[findHighestElementIndex(i, prices)] - prices[i];
            if (maxDifference < currentDifference) {
                maxDifference = currentDifference;
            }
        }
        return maxDifference;
    }
};

int main() {
    Solution s1;
    std::vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    // prices.push_back();
    // prices.push_back();
    std::cout << s1.maxProfit(prices) << std::endl;
}
