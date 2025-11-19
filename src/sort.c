#include <stdio.h>
#define SIZEOF 10

int read_array(int *arr) {
  char line[256];
  if (!fgets(line, sizeof(line), stdin)) return 0;

  int count = 0;
  char *ptr = line;
  while (count < SIZEOF) {
    int n;
    int chars;
    if (sscanf(ptr, "%d%n", &n, &chars) != 1) break;
    arr[count++] = n;
    ptr += chars;
  }

  int extra;
  if (sscanf(ptr, "%d", &extra) == 1) return 0;

  return (count == SIZEOF);
}

void sort_array(int *arr) {
  for (int i = 0; i < SIZEOF; i++) {
    for (int k = i + 1; k < SIZEOF; k++) {
      if (arr[i] > arr[k]) {
        int tpm = arr[i];
        arr[i] = arr[k];
        arr[k] = tpm;
      }
    }
  }
}

void print_array(int *arr) {
  for (int i = 0; i < SIZEOF; i++) {
    if (i > 0) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[SIZEOF];

  if (!read_array(arr)) {
    printf("n/a\n");
    return 0;
  }

  sort_array(arr);
  print_array(arr);

  return 0;
}
