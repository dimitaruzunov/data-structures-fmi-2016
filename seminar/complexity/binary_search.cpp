int binarySearch(const int numbers[], int size, int element) {
    int l = 0;
    int r = size;
    int mid;

    while (l < r) {
        mid = (l + r) / 2;
        if (numbers[mid] == element) {
            return mid;
        }
        else if (numbers[mid] < element) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    if (numbers[l] == element) {
        return l;
    }
    else {
        return -1;
    }
}