#include <iostream>
using namespace std;
void selectionSort(int a[], int n) {
int i, j, minIndex, temp;
for (i = 0; i < n - 1; i++) {
minIndex = i;
for (j = i + 1; j < n; j++) {
if (a[j] < a[minIndex]) {
minIndex = j;
}
}
temp = a[i];
a[i] = a[minIndex];
a[minIndex] = temp;
}
}
void insertionSort(int a[], int n) {
int i, j, key;
for (i = 1; i < n; i++) {
key = a[i];
j = i - 1;
while (j >= 0 && a[j] > key) {
a[j + 1] = a[j];
j = j - 1;
}
a[j + 1] = key;
}
}
void bubbleSort(int a[], int n) {
int i, j, temp;
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - 1 - i; j++) {
if (a[j] > a[j + 1]) {
temp = a[j];
a[j] = a[j + 1];
a[j + 1] = temp;
}
}
}
}
void mergeArrays(int a[], int low, int mid, int high) {
int i, j, k;
int n1 = mid - low + 1;
int n2 = high - mid;
int left[100], right[100];
for (i = 0; i < n1; i++)
left[i] = a[low + i];
for (j = 0; j < n2; j++)
right[j] = a[mid + 1 + j];
i = 0;
j = 0;
k = low;
while (i < n1 && j < n2) {
if (left[i] <= right[j]) {
a[k] = left[i];
i++;
} else {
a[k] = right[j];
j++;
}
k++;
}
while (i < n1) {
a[k] = left[i];
i++;
k++;
}
while (j < n2) {
a[k] = right[j];
j++;
k++;
}
}
void mergeSort(int a[], int low, int high) {
if (low < high) {
int mid;
mid = (low + high) / 2;
mergeSort(a, low, mid);
mergeSort(a, mid + 1, high);
mergeArrays(a, low, mid, high);
}
}
int partitionArray(int a[], int low, int high) {
int pivot = a[high];
int i = low - 1;
int temp;
int j;
for (j = low; j < high; j++) {
if (a[j] <= pivot) {
i++;
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
temp = a[i + 1];
a[i + 1] = a[high];
a[high] = temp;
return i + 1;
}
void quickSort(int a[], int low, int high) {
if (low < high) {
int p;
p = partitionArray(a, low, high);
quickSort(a, low, p - 1);
quickSort(a, p + 1, high);
}
}
void printArray(int a[], int n) {
int i;
for (i = 0; i < n; i++) {
cout << a[i] << " ";
}
cout << endl;
}
int main() {
int n, i, choice;
int arr[100];
cout << "Enter number of elements (max 100): ";
cin >> n;
cout << "Enter " << n << " elements:" << endl;
for (i = 0; i < n; i++) {
cin >> arr[i];
}
cout << "\nOriginal array: ";
printArray(arr, n);
cout << "\nWhich sorting technique do you want to use?\n";
cout << "1. Selection Sort\n";
cout << "2. Insertion Sort\n";
cout << "3. Bubble Sort\n";
cout << "4. Merge Sort\n";
cout << "5. Quick Sort\n";
cout << "Enter your choice (1-5): ";
cin >> choice;
switch (choice) {
case 1:
selectionSort(arr, n);
cout << "\nArray after Selection Sort:\n";
break;
case 2:
insertionSort(arr, n);
cout << "\nArray after Insertion Sort:\n";
break;
case 3:
bubbleSort(arr, n);
cout << "\nArray after Bubble Sort:\n";
break;
case 4:
mergeSort(arr, 0, n - 1);
cout << "\nArray after Merge Sort:\n";
break;
case 5:
quickSort(arr, 0, n - 1);
cout << "\nArray after Quick Sort:\n";
break;
default:
cout << "\nWrong choice.\n";
return 0;
}
printArray(arr, n);
return 0;
}
