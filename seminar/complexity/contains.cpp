bool contains(const int numbers[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (numbers[i] == element) {
            return true;
        }
    }

    return false;
}