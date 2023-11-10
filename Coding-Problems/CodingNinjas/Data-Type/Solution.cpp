#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Problem Statement



Detailed explanation ( Input/output format, Notes, Images )


Sample Input 1:
Long


Sample Output 1:
8


Explanation Of Sample Input 1 :
The size of a Long variable is given as 8 bytes.


Sample Input 2:
Float


Sample Output 2:
4


Explanation Of Sample Input 2 :
The size of a Float variable is given as 4 bytes.


Expected Time Complexity :
The expected time complexity is O(1).


Constraints :
‘type’ is one of the data types given above.

Time limit: 1 second
 */
int dataTypes(std::string type) {
    // Write your code here
    type[0] = std::tolower(type[0]);
    if (type == "long" || type == "double") {
        return 8;
    } else if (type == "float" || type == "integer") {
        return 4;
    }
    return 1;
}
