#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10000

void shuffle(int array[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    int numbers[MAX_NUM];

    // 배열 초기화
    for (int i = 0; i < MAX_NUM; i++) {
        numbers[i] = i + 1;
    }

    // 배열을 섞음
    shuffle(numbers, MAX_NUM);

    // 처음부터 중복되지 않는 수를 출력
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
