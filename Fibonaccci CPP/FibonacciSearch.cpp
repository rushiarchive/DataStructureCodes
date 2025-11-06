#include <iostream>
using namespace std;

int search(int arr[], int x, int n) {
    int a = 0, b = 1, c = a + b;

    // Find smallest Fibonacci number >= n
    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }

    int offset = -1;

    // While elements remain to be inspected
    while (c > 1) {
        // Calculate index to compare
        int i = min(offset + a, n - 1);

        if (arr[i] < x) {
            c = b;
            b = a;
            a = c - b;
            offset = i;
        }
        else if (arr[i] > x) {
            c = a;
            b = b - a;
            a = c - b;
        }
        else {
            return i; // element found
        }
    }

    // Check if last element matches
    if (b && arr[offset + 1] == x)
        return offset + 1;

    return -1; // not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int res = search(arr, x, n);
    if (res != -1)
        cout << "Element found at index: " << res;
    else
        cout << "Element not found";

    return 0;
}
