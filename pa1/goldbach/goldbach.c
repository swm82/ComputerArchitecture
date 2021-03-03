#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//Function declerations
bool is_prime(int n);
void generatePrimes(int *arr, int n);

int main(int argc, char* argv[]) {
  
  if (argc < 2) {
    printf("Please enter a valid number\n");
    return EXIT_FAILURE;
  }

  int number = atoi(argv[1]);
  if (number <= 5 || (number > 5 && number % 2 == 0)) {
    printf("Please enter an odd number greater than 5");
  }

  int nums[number];
  
  generatePrimes(nums, number);

  // Try each combination of 2 prime numbers 
  for (int i = 2; i < number; i++) {
    if (nums[i] == 0) continue;
    for (int j = 2; j < number; j++) {
      if (nums[j] == 0) continue;
      int last = number - i - j;
      if (nums[last] == 0) continue;
      printf("%d = %d + %d + %d\n", number, i, j, last);
      return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}

// Generate primes less than N
void generatePrimes(int *arr, int n) {
  // Set all numbers less than N to 1
  for (size_t i = 0; i < n; i++) {
    arr[i] = 1;
  }

  // Use sieve method to set non-primes to 0
  for (size_t i = 2; i < n; i++) {
    if (arr[i] == 0) continue;
    // Set all multiples of i to 0
    for (size_t j = i + i; j < n; j += i) {
      arr[j] = 0;
    }
  }
  arr[0] = 0;
  arr[1] = 0;
}