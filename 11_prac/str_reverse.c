#include <stdio.h>
#include <string.h>

void str_reverse(char* s) {
    int len = strlen(s);
    char tmp;
    char* left = s;
    char* right = s - 1 + len;
    while (left < right) {
        tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int main() {
    char s[200] = {0};   // 不能写char* s，否则会Segmentation fault(const!!)
    scanf("%[^\n]", s);  // 可以读取空格， 回车结束输入
    str_reverse(s);
    printf("%s\n", s);
    return 0;
}
