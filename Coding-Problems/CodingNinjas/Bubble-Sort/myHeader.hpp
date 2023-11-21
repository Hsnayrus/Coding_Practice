#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

/**
 * Print a single dimensional vector
 *
 * This function prints the contents of a single-dimensional vector in a
 * comma-separated format. For a vector containing numbers from 1 to 5, this
 * function would print something like this:
 * 		{1, 2, 3, 4, 5}
 *
 * @param myVector Vector containing values of a particular Type
 *
 * @note Make sure that the vector's data is printable. Non-generic types
 * overload their own ostream operator in order to print.
 */
template <typename T>
void printList1D(std::vector<T> & myVector, bool newLine = true) {
    typename std::vector<T>::iterator myIterator = myVector.begin();
    std::cout << "{";
    while (myIterator != myVector.end()) {
        std::cout << *myIterator;
        ++myIterator;
        if (myIterator != myVector.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "}";
    if (newLine) {
        std::cout << std::endl;
    }
}

/**
 * Print contents of a two-dimensional vector
 *
 * This function prints the contents of a two-dimensional vector in a
 * comma-separated fashion. For example if you have a 3x3 identity matrix, this
 * function would print it like:
 * 		{
 * 			{1, 0, 0},
 * 			{0, 1, 0},
 * 			{0, 0, 1}
 * 		}
 *
 * @param myVector A two-dimensional vector.
 * @note Make sure that the data type is printable, i.e., custom data types
 * should overload their own ostream operator.
 */
template <typename T>
void printList2D(std::vector<std::vector<T> > & myVector) {
    std::cout << "{\n";
    size_t i = 0;
    while (i < myVector.size()) {
        std::cout << "    ";
        printList1D(myVector[i], false);
        ++i;
        if (i < myVector.size()) {
            std::cout << ",";
            std::cout << "\n";
        }
    }
    std::cout << "\n}\n";
}
