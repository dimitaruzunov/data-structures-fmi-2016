#ifndef COMPLEXITY_FUNCTIONS_H
#define COMPLEXITY_FUNCTIONS_H

#include <string>

using namespace std;

int sum(const int numbers[], int size);

int countOfDiv3(const int numbers[], int size);

bool contains(const int numbers[], int size, int element);

int sumOfDigits(int number);

bool binarySearch(const int numbers[], int size, int element);

int factorial(int n);

int fibonacci(int n);

bool contains(const int numbers[30][], int size, int element);

void bubbleSort(int numbers[], int size);

int productOfEvenPositions(int numbers[], int size);

bool searchString(string haystack, string needle);

string decimalToBinary(int number);

void straightSelectionSort(int numbers[], int size);

int naivePower(int number, int exponent);

int fastPower(int number, int exponent);

#endif //COMPLEXITY_FUNCTIONS_H
