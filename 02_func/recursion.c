#include <stdio.h>
#include <string.h>

void print_num(int n) {
    if (n >= 10)
        print_num(n / 10);
    printf("%d ", n % 10);
}

int my_strlen(char* str) {
    if (*str != '\0')
        return my_strlen(str + 1) + 1;
    else
        return 0;
}

int jump_stair(int n) {
    if (n == 1)
        return 1;
    else if (n == 2) 
        return 2;
    else
        return jump_stair(n - 1) + jump_stair(n - 2);
}

int main() {
    char arr[] = "abc";
    int len = jump_stair(3);
    printf("%d\n", len);
    return 0;
}
