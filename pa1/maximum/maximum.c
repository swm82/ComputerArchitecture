#include <stdlib.h>
#include <stdio.h>

void heapify(int arr[], int length);
void sink(int arr[], int k, int length);
void swap(int arr[], int a, int b);
void getMaxN(int heap[], int length, int res[], int n);
void getNumbers(FILE* fp, int arr[], int n);
void printResults(int arr[], int n);

int main(int argc, char* argv[]) {
  // Open file
  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    perror("fopen failed");
    return EXIT_FAILURE;
  }

  // Get number of ints, N
  int numInts = 0;
  int N = 0;
  fscanf(fp, "%d", &numInts);
  fscanf(fp, "%d", &N);
  int nums[numInts];

  getNumbers(fp, nums, numInts);
  heapify(nums, numInts);
  int result[N];
  getMaxN(nums, numInts, result, N);
  printResults(result, N);

  // Close file
  fclose(fp);
  return EXIT_SUCCESS;
}

// Read numbers from file
void getNumbers(FILE* fp, int arr[], int n) {
  for (int i = 0; i < n; i++) {
    fscanf(fp, "%d", &arr[i]);
  }
}

// Heapify array
void heapify(int arr[], int length) {
  int k = (length - 1) / 2;
  while (k >= 0) {
    sink(arr, k, length);
    k--;
  }
}

// Max-heapify - top down
void sink(int arr[], int k, int length) {
  while ((2*k + 1) <= length - 1) {
    int max = k;
    if (arr[2*k + 1] > arr[k]) {
      max = 2*k + 1;
    }
    if (2*k + 2 <= length - 1 && arr[max] < arr[2*k + 2]) {
      max = 2*k + 2;
    }
    if (max != k) {
      swap(arr, max, k);
      k = max;
    } else {
      break;
    }
  }
}

// Swap helper method
void swap(int arr[], int a, int b) {
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

// Get N maximum values in heap
void getMaxN(int heap[], int length, int res[], int n) {
  for (int i = 0; i < n; i++) {
    res[i] = heap[0];
    heap[0] = heap[--length];
    sink(heap, 0, length);
  }
}

// Print results
void printResults(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}