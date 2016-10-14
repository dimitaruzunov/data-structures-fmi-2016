int countOfDiv3(const int numbers[], int size) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (numbers[i] % 3 == 0) {
            ++count;
        }
    }

    return count;
}