#include <iostream>
#include <vector>
using namespace std;

// ==========================
// Priority Queue using Heap
// ==========================
class PriorityQueue {
    vector<int> heap;  // underlying array representation
    bool isMaxHeap;    // true for Max-Heap, false for Min-Heap

public:
    // Constructor
    PriorityQueue(bool type = true) {
        isMaxHeap = type; // default: Max-Heap
    }

    // Get parent, left, and right child indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Function to compare values depending on heap type
    bool compare(int a, int b) {
        return isMaxHeap ? a > b : a < b;
    }

    // (a) Insert element into heap
    void push(int value) {
        heap.push_back(value);
        int i = heap.size() - 1;

        // Bubble up to maintain heap property
        while (i != 0 && compare(heap[i], heap[parent(i)])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // (b) Remove top (highest/lowest priority) element
    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty.\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    // Heapify to restore heap property after deletion
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int extreme = i;

        if (l < heap.size() && compare(heap[l], heap[extreme]))
            extreme = l;

        if (r < heap.size() && compare(heap[r], heap[extreme]))
            extreme = r;

        if (extreme != i) {
            swap(heap[i], heap[extreme]);
            heapify(extreme);
        }
    }

    // (c) Get top element (highest or lowest priority)
    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty.\n";
            return -1;
        }
        return heap[0];
    }

    // (d) Display all elements in heap order
    void display() {
        if (heap.empty()) {
            cout << "Priority Queue is empty.\n";
            return;
        }
        cout << "Priority Queue elements: ";
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }

    // (e) Check if empty
    bool empty() {
        return heap.empty();
    }
};

// ==========================
// Main Function
// ==========================
int main() {
    int choice, value, typeChoice;
    cout << "Select Type of Priority Queue:\n";
    cout << "1. Max-Heap (Higher value = Higher priority)\n";
    cout << "2. Min-Heap (Lower value = Higher priority)\n";
    cout << "Enter choice: ";
    cin >> typeChoice;

    PriorityQueue pq(typeChoice == 1);

    do {
        cout << "\n--- Priority Queue Operations ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Top Element\n";
        cout << "3. Get Top Element\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.push(value);
                break;

            case 2:
                pq.pop();
                break;

            case 3:
                cout << "Top element: " << pq.top() << endl;
                break;

            case 4:
                pq.display();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
