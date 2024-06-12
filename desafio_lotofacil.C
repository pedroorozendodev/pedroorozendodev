#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_and_print_combination(int num) {
    if (num < 15 || num > 18) {
        printf("Quantidade inválida. Deve ser entre 15 e 18.\n");
        return;
    }

    int numbers[25];
    int combination[num];

    for (int i = 0; i < 25; i++) {
        numbers[i] = i + 1;
    }

    for (int i = 0; i < 25; i++) {
        int temp = numbers[i];
        int random_index = rand() % 25;
        numbers[i] = numbers[random_index];
        numbers[random_index] = temp;
    }

    for (int i = 0; i < num; i++) {
        combination[i] = numbers[i];
    }

    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (combination[i] > combination[j]) {
                int temp = combination[i];
                combination[i] = combination[j];
                combination[j] = temp;
            }
        }
    }

    printf("Sua combinação é: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", combination[i]);
    }
    printf("\n");
}

int main() {
    int num;
    srand(time(NULL));

    while (1) {
        printf("Informe a quantidade de números para apostar (15-18) ou 0 para sair: ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        generate_and_print_combination(num);
    }

    printf("Programa encerrado.\n");
    return 0;
}
