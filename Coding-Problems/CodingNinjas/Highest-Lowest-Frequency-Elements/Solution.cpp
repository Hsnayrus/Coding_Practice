#include "myHeader.hpp"
/*
Problem Statement
Given an array 'v' of 'n' numbers

Your task is to find and return the highest and lowest frequency elements
If there are multiple elements that have the highest frequency or lowest
frequency, pick the smallest element.

Example:
Input: 'n' = 6, 'v' = {1, 2, 3, 1, 1, 4}
Output: 1 2
Explanation: The element having the highest frequency is '1', and the frequency
is 3. The elements with the lowest frequencies are '2', '3' and '4'. Since we
need to pick the smallest element, we pick '2'. Hence, we return {1, 2}.

Sample Input 1 :
6
1 2 3 1 1 4
Sample Output 1 :
1 2
Sample Explanation 1:
Input: ‘n' = 6, 'v' = [1, 2, 3, 1, 1, 4]

Output: 1 2

Explanation: The element having the highest frequency is '1', and the frequency
is 3. The elements with the lowest frequencies are '2', '3', and '4'. Since we
need to pick the smallest element, we pick '2'. Hence we return [1, 2]. Sample
Input 2 :
6
10 10 10 3 3 3
Sample Output 2 :
3 3
Sample Explanation 2:
Input: ‘n' = 6, 'v' = [10, 10, 10, 3, 3, 3]

Output: 3 3

Explanation: Since the frequency of '3' and '10' is 3. Therefore, the element
with the maximum and minimum frequency is '3'. Expected Time Complexity : The
expected time complexity is O(n), where n is the size of the array. Expected
Space Complexity : The expected time complexity is O(n), where n is the size of
the array. Constraints : 2 <=  n <= 10^4 1 <= v[i] <= 10^9 There are at least
two distinct elements in the array. Time Limit: 1 sec
 */

int findMaxElement(std::vector<int>& myV) {
    int max = INT_MIN;
    for (size_t i = 0; i < myV.size(); i++) {
        if (myV[i] > max) {
            max = myV[i];
        }
    }
    return max;
}
/**
 * Find the max element in the array
 * Create a vector, named frequencies with max elements of value 0
 * Iterate from the first element to the last element of the array
 * frequency[currentElement - 1] ++;
 * Create two variables, minF and maxF
 * Iterate through the frequency array
 * Initialize
 * minFI = 0
 * maxFI = 0
 * if(currentFrequency is < frequency[minFI]){
 * 	minFI = i;
 * }
 * if(currentFrequency is > frequency[maxFI]){
 * 	maxFI = currentFrequency
 * }
 * return a vector containing max and min
 */
std::vector<int> getFrequencies(std::vector<int>& v) {
    // Write Your Code Here
    int maxElement = findMaxElement(v);
    std::vector<int> frequencies(maxElement, 0);
    for (size_t i = 0; i < v.size(); i++) {
        frequencies[v[i] - 1]++;
    }
    int minFI = 0;
    int maxFI = 0;
    for (size_t i = 1; i < v.size(); i++) {
        if (frequencies[minFI] == 0 && frequencies[i] != 0) {
            minFI = i;
        }
        if (frequencies[i] != 0 && frequencies[i] < frequencies[minFI]) {
            minFI = i;
        }
        if (frequencies[i] > frequencies[maxFI]) {
            maxFI = i;
        }
    }
    std::vector<int> result;
    result.push_back(maxFI + 1);
    result.push_back(minFI + 1);
    return result;
}
int main() {
    int arr[] = {1, 2, 1, 1, 3, 4};
    std::vector<int> nums(arr, arr + (sizeof(arr) / sizeof(int)));
    std::vector<int> result = getFrequencies(nums);
    printList1D(result);
    return 0;
}
