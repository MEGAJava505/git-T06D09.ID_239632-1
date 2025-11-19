#include <stdio.h>

#define SIZE 10

// ------ Ввод массива ------
int read_array(int *arr) {
  char line[256];
  if (!fgets(line, sizeof(line), stdin)) return 0;

  int count = 0;
  char *ptr = line;
  while (count < SIZE) {
    int num, len;
    if (sscanf(ptr, "%d%n", &num, &len) != 1) break;
    arr[count++] = num;
    ptr += len;
  }

  if (count != SIZE) return 0;

  int extra;
  if (sscanf(ptr, "%d", &extra) == 1) return 0;

  return 1;
}

// ------ QuickSort ------
void quick_sort(int *arr, int low, int high) {
  if (low >= high) return;

  int i = low;
  int j = high;
  int pivot = arr[(low + high) / 2];

  while (i <= j) {
    while (arr[i] < pivot) i++;
    while (arr[j] > pivot) j--;

    if (i <= j) {
      int t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
      i++;
      j--;
    }
  }

  if (low < j) quick_sort(arr, low, j);
  if (i < high) quick_sort(arr, i, high);
}

// ------ HeapSort ------
void heapify(int *arr, int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest]) largest = l;
  if (r < n && arr[r] > arr[largest]) largest = r;

  if (largest != i) {
    int t = arr[i];
    arr[i] = arr[largest];
    arr[largest] = t;
    heapify(arr, n, largest);
  }
}

void heap_sort(int *arr) {
  for (int i = SIZE / 2 - 1; i >= 0; i--) {
    heapify(arr, SIZE, i);
  }

  for (int i = SIZE - 1; i > 0; i--) {
    int t = arr[0];
    arr[0] = arr[i];
    arr[i] = t;
    heapify(arr, i, 0);
  }
}

// ------ Вывод массива ------
void print_arr(int *arr) {
  for (int i = 0; i < SIZE; i++) {
    if (i > 0) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr1[SIZE];
  int arr2[SIZE];

  if (!read_array(arr1)) {
    printf("n/a\n");
    return 0;
  }

  // Копируем arr1 в arr2
  for (int i = 0; i < SIZE; i++) arr2[i] = arr1[i];

  quick_sort(arr1, 0, SIZE - 1);
  heap_sort(arr2);

  print_arr(arr1);
  print_arr(arr2);

  return 0;
}