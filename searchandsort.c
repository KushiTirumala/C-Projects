#include <stdio.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
int linearSearch(int arr[], int n, int key);
int binarySearch(int arr[], int n, int key);
void printArray(int arr[], int n);

int main() {
    int arr[100], n, choice, key, result;

    printf("=== Searching and Sorting Algorithms Suite ===\n");
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search (Array must be sorted)\n");
        printf("6. Display Array\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                bubbleSort(arr, n);
                printf("✅ Array sorted using Bubble Sort:\n");
                printArray(arr, n);
                break;
            case 2:
                selectionSort(arr, n);
                printf("✅ Array sorted using Selection Sort:\n");
                printArray(arr, n);
                break;
            case 3:
                insertionSort(arr, n);
                printf("✅ Array sorted using Insertion Sort:\n");
                printArray(arr, n);
                break;
            case 4:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = linearSearch(arr, n, key);
                if(result != -1) 
                    printf("✅ Key %d found at position %d\n", key, result + 1);
                else
                    printf("❌ Key not found\n");
                break;
            case 5:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = binarySearch(arr, n, key);
                if(result != -1) 
                    printf("✅ Key %d found at position %d\n", key, result + 1);
                else
                    printf("❌ Key not found\n");
                break;
            case 6:
                printf("Current Array:\n");
                printArray(arr, n);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("❌ Invalid choice. Try again.\n");
        }

    } while(choice != 7);

    return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int minIndex, temp;
    for(int i = 0; i < n-1; i++) {
        minIndex = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[minIndex]) minIndex = j;
        temp = arr[i]; arr[i] = arr[minIndex]; arr[minIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int key, j;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++)
        if(arr[i] == key) return i;
    return -1;
}

// Binary Search (array must be sorted)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Print Array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
