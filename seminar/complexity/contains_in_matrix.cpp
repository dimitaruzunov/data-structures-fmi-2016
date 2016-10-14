bool containsInMatrix(const int numbers[][3], int size, int element) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (numbers[i][j] == element) {
                return true;
            }
        }
    }

    return false;
}