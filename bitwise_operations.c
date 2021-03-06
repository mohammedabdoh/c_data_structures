#include <stdio.h>

int main() {

    int a = 10; // 00000000 00000000 00000000 00001010
    int b = 11; // 00000000 00000000 00000000 00001011

    // Bitwise AND &&
    printf("a&b is: %d\n", a&b); // 00000000 00000000 00000000 00001010

    // Bitwise OR |
    printf("a|b is: %d\n", a|b); // 00000000 00000000 00000000 00001011

    // Bitwise XOR ^
    printf("a^b is: %d\n", a^b); // 00000000 00000000 00000000 00000001

    // Bitwise NOT ~
    printf("~a is: %d\n", ~a); // 11111111 11111111 11111111 11110101
    printf("~b is: %d\n", ~b); // 11111111 11111111 11111111 11110100

    // Bitwise left shift <<
    printf("a<<3 is: %d\n", a<<3); // 00000000 00000000 00000000 01010000
    printf("b<<3 is: %d\n", b<<3); // 00000000 00000000 00000000 01011000

    // Bitwise right shift >>
    printf("a>>3 is: %d\n", a>>3); // 00000000 00000000 00000000 00000001
    printf("b>>3 is: %d\n", b>>3); // 00000000 00000000 00000000 00000001

    return 0;
}