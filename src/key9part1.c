/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
  int n;
  if (scanf("%d", &n) != 1 || n <= 0 || n > 10) {
    printf("n/a");
    return 0;
  }

  int arr[10];

  getchar();

  char line[200];
  if (!fgets(line, sizeof(line), stdin)) {
    printf("n/a");
    return 0;
  }

  int pos = 0;
  int count = 0;
  int value, shift;

  // парсим  из строки
  while (sscanf(&line[pos], "%d%n", &value, &shift) == 1) {
    arr[count++] = value;
    pos += shift;

    if (count > n) {
      printf("n/a");
      return 0;
    }
  }

  if (count != n) {
    printf("n/a");
    return 0;
  }

  int sum = sum_numbers(arr, n);
  if (sum == 0) {
    printf("n/a");
    return 0;
  }

  int new_arr[10];
  int new_len = find_numbers(arr, n, sum, new_arr);

  printf("%d", sum);
  if (new_len > 0) {
    printf("\n");
    for (int i = 0; i < new_len; i++) {
      if (i > 0)
        printf(" ");
      printf("%d", new_arr[i]);
    }
  }

  return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      sum += buffer[i];
    }
  }
  if (sum == 0) {
    printf("n/a");
    return 0;
  }
  return sum;
}
/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] != 0) {
      if (number % buffer[i] == 0) {
        numbers[count] = buffer[i];
        count++;
      }
    }
  }
  return count;
}
