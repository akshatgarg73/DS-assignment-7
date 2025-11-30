#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int min_idx = left;
        int max_idx = left;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[min_idx]) min_idx = i;
            if (arr[i] > arr[max_idx]) max_idx = i;
        }
        int temp = arr[left];
        arr[left] = arr[min_idx];
        arr[min_idx] = temp;

        if (max_idx == left) max_idx = min_idx;

        temp = arr[right];
        arr[right] = arr[max_idx];
        arr[max_idx] = temp;

        left++;
        right--;
    }
}

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
