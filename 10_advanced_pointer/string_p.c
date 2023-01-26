#include <stdio.h>

int main() {
    char* p = "abcdef";  // 常量字符串，无法修改
    const char* p_ = "abcdef";  // 更准确的写法
    // Segmentation fault - 段错误，非法访问内存
    // *p = 'w';
    printf("%s\n", p);

    char arr1[] = "abc";
    char arr2[] = "abc";
    char* p1 = "abc";
    char* p2 = "abc";
    
    // ==
    printf("%s\n", arr1 == arr2 ? "arr1 == arr2" : "arr1 != arr2");
    // !=
    printf("%s\n", p1 == p2 ? "p1 == p2" : "p1 != p2");


    return 0;
}
