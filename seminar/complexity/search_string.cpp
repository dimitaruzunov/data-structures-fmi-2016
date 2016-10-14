#include "functions.h"

int searchString(string haystack, string needle) {
    int hSize = haystack.size();
    int nSize = needle.size();

    bool correct;
    for (int i = 0; i < hSize - nSize + 1; ++i) {
        correct = true;
        for (int j = 0; j < nSize; ++j) {
            if (haystack[i + j] != needle[j]) {
                correct = false;
                break;
            }
        }
        if (correct) {
            return i;
        }
    }

    return -1;
}