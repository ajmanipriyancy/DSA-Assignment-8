#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i (for max heap)
void heapifyMax(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// Function to heapify for min heap (for decreasing order)
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// Heap sort in increasing order (using Max Heap)
void heapSortIncreasing(int arr[], int n) {
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapifyMax(arr, i, 0);
    }
}

// Heap sort in decreasing order (using Min Heap)
void heapSortDecreasing(int arr[], int n) {
    // Build Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapifyMin(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[100], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n1. Sort in Increasing Order\n2. Sort in Decreasing Order\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        heapSortIncreasing(arr, n);
        cout << "\nArray sorted in Increasing Order:\n";
        printArray(arr, n);
    } else if (choice == 2) {
        heapSortDecreasing(arr, n);
        cout << "\nArray sorted in Decreasing Order:\n";
        printArray(arr, n);
    } else {
        cout << "Invalid choice!";
    }

    return 0;
}
