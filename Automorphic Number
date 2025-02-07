#include <stdio.h>

int main() {
    int num, square, temp, flag = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    square = num * num;

    temp = num;
    while (temp > 0) {
        if (temp % 10 != square % 10) {
            flag = 0; // Not Automorphic
            break;
        }
        temp /= 10;
        square /= 10;
    }

    if (flag)
        printf("%d is an Automorphic number.\n", num);
    else
        printf("%d is not an Automorphic number.\n", num);

    return 0;
}
