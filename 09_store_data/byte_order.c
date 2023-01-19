#include <stdio.h>

int check_sys() {
    int i = 1;
    return *(char*)&i;
}

int main() {
    int a = 0x11223344;
    char* p = (char*)&a;
    for (int i = 0; i < 4; i++) {
        printf("%x ", *p++);  // 0x44332211, 小端
    }
    printf("\n");

    printf("%s\n", check_sys ? "小端" : "大端");
    return 0;
}
