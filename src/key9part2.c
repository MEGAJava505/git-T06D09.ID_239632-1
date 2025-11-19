#include <stdio.h>

#define LEN 100

int input_number(int *buff, int *len);
void sum(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length);
int compare(int *buff1, int len1, int *buff2, int len2);
void sub(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length);
void print_number(int *buff, int len);

int main() {
  int a[LEN], b[LEN], res[LEN + 1];
  int lenA = 0, lenB = 0, lenR = 0;

  // ввод первого числа
  if (!input_number(a, &lenA)) {
    printf("n/a");
    return 0;
  }

  // ввод второго числа
  if (!input_number(b, &lenB)) {
    printf("n/a");
    return 0;
  }

  // SUM
  sum(a, lenA, b, lenB, res, &lenR);
  print_number(res, lenR);
  printf("\n");

  // SUB
  if (compare(a, lenA, b, lenB) < 0) {
    printf("n/a");
    return 0;
  }

  sub(a, lenA, b, lenB, res, &lenR);
  print_number(res, lenR);

  return 0;
}

int input_number(int *buff, int *len) {
  char end;
  for (int i = 0; i < LEN; i++) {
    int digit;
    if (scanf("%d%c", &digit, &end) != 2)
      return 0;
    if (digit < 0 || digit > 9)
      return 0;

    buff[i] = digit;
    (*len)++;

    if (end == '\n')
      return 1;
    if (end != ' ')
      return 0;
  }
  return 1;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length) {
  int carry = 0;
  int i = len1 - 1, j = len2 - 1, k = 0;

  while (i >= 0 || j >= 0 || carry) {
    int x = (i >= 0 ? buff1[i] : 0);
    int y = (j >= 0 ? buff2[j] : 0);
    int s = x + y + carry;
    carry = s / 10;
    result[k++] = s % 10;
    i--;
    j--;
  }

  *result_length = k;

  // reverse
  for (int l = 0; l < k / 2; l++) {
    int tmp = result[l];
    result[l] = result[k - 1 - l];
    result[k - 1 - l] = tmp;
  }
}

int compare(int *buff1, int len1, int *buff2, int len2) {
  if (len1 > len2)
    return 1;
  if (len1 < len2)
    return -1;
  for (int i = 0; i < len1; i++) {
    if (buff1[i] > buff2[i])
      return 1;
    if (buff1[i] < buff2[i])
      return -1;
  }
  return 0;
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length) {
  int borrow = 0;
  int i = len1 - 1, j = len2 - 1, k = 0;

  while (i >= 0) {
    int x = buff1[i] - borrow;
    int y = (j >= 0 ? buff2[j] : 0);

    if (x < y) {
      x += 10;
      borrow = 1;
    } else
      borrow = 0;

    result[k++] = x - y;
    i--;
    j--;
  }

  // remove leading zeros
  while (k > 1 && result[k - 1] == 0)
    k--;

  *result_length = k;

  // reverse
  for (int l = 0; l < k / 2; l++) {
    int tmp = result[l];
    result[l] = result[k - 1 - l];
    result[k - 1 - l] = tmp;
  }
}

void print_number(int *buff, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d", buff[i]);
    if (i < len - 1)
      printf(" ");
  }
}