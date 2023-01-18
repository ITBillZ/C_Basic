#include <stdio.h>

struct Stu1
{
    char id[20];
    int age;
};

// typedef，换个名字
typedef struct Stu2
{
    char id[20];
    int age;
} Stu2;

typedef struct Class
{
    int id;
    Stu2 stu_arr[50];
    char* motto;
} Class;

void print_stu(Stu2 stu) {
    printf("%s\n", stu.id);
    printf("%d\n", stu.age);
}

// 这个更好，因为需要的时间或者空间都更少
void print_stu2(Stu2* stu) {
    printf("%s\n", stu->id);
    printf("%d\n", stu->age);
}

int main() {

    struct Stu1 s1;
    Stu2 s2 = {"374293", 15};

    Class class;
    printf("%d\n", class.stu_arr[0].age);
    print_stu(s2);
    print_stu2(&s2);
    
    return 0;
}
