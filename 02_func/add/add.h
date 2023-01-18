// if not define, 第一次引入头文件时，此条件为真，
// 编译器会在第一次引用的地方把实现的代码放进去
// 后面再引用这个头文件时，就不会再复制一份头文件，
// 防止同一头文件被多次引入代码
#ifndef __ADD_H_  
#define __ADD_H_
int add(int, int);
#endif