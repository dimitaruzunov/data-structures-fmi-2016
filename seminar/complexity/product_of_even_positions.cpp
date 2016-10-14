int productOfEvenPositions(int numbers[], int size) {
    int product = 1;

    for (int i = 0; i < size; i += 2) {
        product *= numbers[i];
    }

    return product;
}