## 指针类型的意义
1. 指针类型决定了指针进行解引用操作的时候，`能够访问的空间的大小`。如int\*可以访问4个字节，char\*可以访问1个字节，double\*可以访问8个字节。
2. 指针类型决定指针+1跳过多少个字节（步长）。

## 野指针
1. def: 指针指向的位置是不可知的(随机的，不正确的，没有明确限制的)
2. 出现原因：
   - 指针未初始化
   - 指针越界访问
   - 使用的时候，该空间已经被释放(函数调用)
3. 避免：
   - 使用NULL初始化、释放指针
   - 指针使用之前检验有效性

## C语言的一个指针规定
```C
for (int* p = &arr[sz - 1]; p >= &arr[0]; vp--)
   *vp = 0;
```
C语言规定允许p与arr[sz]比较，但不允许p与arr[-1]比较。