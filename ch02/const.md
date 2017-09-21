`top-level const`表示指针本身是个常量
`low-level const`表示指针所指的对象是一个常量
```C++
int i = 0;
// p1是一个指针常量
int *const p1 = &i;     // 不能改变p1的值，这是一个top-level const
// ci是一个普通常量
const int ci = 42;      // 不能改变c1的值，这是一个top-level const
// p2是一个指向常量的常量指针
const int *p2 = &ci;    // 允许改变p2的值，这是一个low-level const
```