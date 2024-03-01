#include "myHeader.hpp"
/*
There is an undirected star graph consisting of n nodes labeled from 1 to n. A
star graph is a graph where there is one center node and exactly n - 1 edges
that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates
that there is an edge between the nodes ui and vi. Return the center of the
given star graph.



Example 1:


Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other
node, so 2 is the center. Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1


Constraints:

3 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph.
 */
class Solution {
  public:
    /**
     * Algorithm Mark1:
     * Create a hashmap where key is the node value and value is the number
     * of times the node has appeared, call it frequency
     * Iterate through the graph of edges
     * Increase the count of each edge
     * If count of any edge crosses 2, return that edge
     *
     */
    int findCenter(std::vector<std::vector<int> >& edges) {
        std::unordered_map<int, int> frequencyMap;
        int result = INT_MIN;
        for (std::vector<std::vector<int> >::iterator it = edges.begin();
             it != edges.end(); it++) {
            // Couldn't find element
            for (std::vector<int>::iterator edgesIterator = it->begin();
                 edgesIterator != it->end(); edgesIterator++) {
                if (frequencyMap.find(*edgesIterator) == frequencyMap.end()) {
                    // New entry
                    frequencyMap[*edgesIterator] = 1;
                } else {
                    result = *edgesIterator;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    std::cout << "ello orld\n";
    return EXIT_SUCCESS;
}