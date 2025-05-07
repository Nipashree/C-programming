#include <stdio.h>
#include <math.h>


int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}


int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

int rotateNumber(int num, int digits) {
    int lastDigit = num % 10;  
    num /= 10;                     
    return lastDigit * pow(10, digits - 1) + num; 
}

int isCircularPrime(int num) {
    int digits = countDigits(num);
    int rotatedNum = num;

    for (int i = 0; i < digits; i++) {
        if (!isPrime(rotatedNum)) return 0; // If any rotation is not prime, return false
        rotatedNum = rotateNumber(rotatedNum, digits); // Get next rotation
    }
    return 1;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isCircularPrime(num))
        printf("%d is a Circular Prime.\n", num);
    else
        printf("%d is NOT a Circular Prime.\n", num);

    return 0;
}
