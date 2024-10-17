#include <iostream>
using namespace std;

int processArray(int arr[], int length);

int main() {
    // Read integers from standard input and store them in an array
    int inputArray[1000];
    int index = 0;

    while (true) {
        int num;
        cin >> num;
        if (num < 0) {
            break;
        }

        inputArray[index++] = num;
    }

    // Call the processArray function to modify the array
    int newLength = processArray(inputArray, index);

    // Print the modified contents of the array
    for (int i = 0; i < newLength; i++) {
        cout << inputArray[i] << endl;
    }

    return 0;
}

int processArray(int arr[], int length) {
    int newIndex = 0;
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] < 100) {
            sum += arr[i];
        } else {
            if (sum > 0) {
                arr[newIndex++] = sum;
                sum = 0;
            }
            arr[newIndex++] = arr[i];
        }
    }

    if (sum > 0) {
        arr[newIndex++] = sum;
    }

    return newIndex;
}
