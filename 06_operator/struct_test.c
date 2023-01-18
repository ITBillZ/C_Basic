#include <stdio.h>

struct Stu
{
    char name[20];
    int age;
    char id[20];
};


int main() {
    struct Stu s = {"Bill", 20, "118570101"};
    struct Stu* ps = &s;
    printf("%s\n", s.name);
    // 结构体指针 -> 成员名
    printf("%d\n", ps->age);

    printf("%ld\n", sizeof(struct Stu*));

    return 0;
}
