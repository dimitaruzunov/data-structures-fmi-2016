void bubbleSort(int numbers[], int size) {
    int t;

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                t = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = t;
            }
        }
    }
}