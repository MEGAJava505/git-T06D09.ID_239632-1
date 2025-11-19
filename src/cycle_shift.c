#include <stdio.h>

#define MAX 10

int scan_single_int(int *x);  // Считывание одного числа строго
int scan_array(int *a, int n);     // Считывание массива
void shift(int *a, int n, int c);  // Сдвиг
void output(int *a, int n);        // Вывод

int main() {
  int n, c;
  int a[MAX];

  // 1. читаем n строго
  if (!scan_single_int(&n) || n <= 0 || n > MAX) {
    printf("n/a");
    return 0;
  }

  // 2. читаем массив ровно из n чисел
  if (!scan_array(a, n)) {
    printf("n/a");
    return 0;
  }

  // 3. читаем c строго
  if (!scan_single_int(&c)) {
    printf("n/a");
    return 0;
  }

  // выполнение сдвига
  shift(a, n, c);
  output(a, n);

  return 0;
}

// Строгое считывание 1 целого числа
int scan_single_int(int *x) {
  char end;
  if (scanf("%d%c", x, &end) != 2) return 0;  // если не прочитали два элемента
  if (end != '\n' && end != ' ')
    return 0;  // если после числа не пробел или новая строка
  return 1;
}

// Чёткое считывание массива по n
int scan_array(int *a, int n) {
  char end;
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &a[i]) != 1) return 0;  // поймали букву или пустоту
  }

  // Проверяем, что после последнего числа стоит \n, а не ещё текст
  if (scanf("%c", &end) != 1 || end != '\n') return 0;

  return 1;
}

void shift(int *a, int n, int c) {
  int temp[MAX];

  if (c >= 0)
    c %= n;
  else
    c = n - ((-c) % n);

  for (int i = 0; i < n; i++) temp[i] = a[(i + c) % n];

  for (int i = 0; i < n; i++) a[i] = temp[i];
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i < n - 1) printf(" ");
  }
}