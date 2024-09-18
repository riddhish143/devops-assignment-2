//Assignment 2 of DevOps

#include <bits/stdc++.h>

using namespace std;

enum class SortAlgorithm {
    BUBBLE_SORT,
    MERGE_SORT,
    QUICK_SORT,
    // Add other sorting algorithms here if not mentioned and also change the sortArray function accordingly and the cout in selecting the sorting algorithm
};

// Name of Contributor
void bubbleSort(vector<int>& arr) {
    
}

// Function to merge two subarrays into a single sorted array
// Sahil Kirti
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays to hold the subarrays
    vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void quickSort(vector<int>& arr) {

}
void insertionSort(vector<int>& arr){
    for(int i = 1;i < arr.size() ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key
    }
}

void sortArray(vector<int>& arr, SortAlgorithm algorithm) {
    switch (algorithm) {
        case SortAlgorithm::BUBBLE_SORT:
            bubbleSort(arr);
            break;
        case SortAlgorithm::MERGE_SORT:
            mergeSort(arr);
            break;
        case SortAlgorithm::QUICK_SORT:
            quickSort(arr);
            break;
        default:
            cerr << "Invalid sorting algorithm selected." << endl;
            break;
    }
}

int main() {
    int numElements;
    cout << "Enter the number of elements: ";
    cin >> numElements;

    vector<int> arr(numElements);
    cout << "Enter the elements: ";
    for (int i = 0; i < numElements; ++i) {
        cin >> arr[i];
    }

    int choice;
    cout << "Choose sorting algorithm (0: Bubble, 1: Merge, 2: Quick): ";
    cin >> choice;

    SortAlgorithm algorithm = static_cast<SortAlgorithm>(choice);
    sortArray(arr, algorithm);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
