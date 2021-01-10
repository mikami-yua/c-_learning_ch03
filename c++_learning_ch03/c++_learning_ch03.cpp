// c++_learning_ch03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "c++_learning_ch03.h"
#include <string> 
using namespace std;

void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void buubleSort(int *arr,int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
}

void printArray(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//1.创建学生数据类型
struct Student
{
    //成员列表
    string name;
    int age;
    int score;
}s3;

//2.通过学生类型创建具体学生
//2.1 struct Student s1;
//2.2 struct Student s1={...}
//2.3 在定义结构体变量的同时顺便赋值

struct Teacher
{
    int id;
    string name;
    int age;
    Student stu;//辅导的学生
};

//值传递
void printStu1(Student s1) {
    cout << "information in print function " << s1.name << " "
        << s1.age << " " << s1.score << endl;
}

//地址传递：需要使用指针接受一个地址
void printStu2(const Student* s1) {//防止修改的误操作
    //s1->age = 100;
    cout << "information in print function2 " << s1->name << " "
        << s1->age << " " << s1->score << endl;
}

int main()
{
    //1.定义指针
    int a = 10;
    //定义指针的语法：数据类型 * 指针变量
    int* p;
    //让指针记录地址
    p = &a;//&取地址
    cout << "address of a:" << &a << endl;
    cout << "pointer p:" << p << endl;

    //2.使用指针
    //可以使用引用的方式来找到指针指向的内存
    //指针前加*代表解引用，找到指针指向的内存中的数据
    *p = 1000;
    cout << a << endl;

    //3.指针所占的内存空间
    /*
    指针中存的是地址
    无论什么类型的指针，都是占用4个字节（32位）64位占8字节
    */
    int* p1 = &a;//定义和指向同时完成
    cout << "sizeof(int *)" << sizeof(p1) << endl;//4
    cout << "sizeof(float *)" << sizeof(float *) << endl;//4

    //4.空指针和野指针
    /*
    空指针：指针内存中编号为0的空间（空指针指向的内存是不能访问的）
    空指针用于给指针变量初始化
    0~255之间的内存编号是系统占用的

    野指针：指向的非法的内存空间
    */
    int* p2 = NULL;

    int* p3 = (int*)0x1100;//野指针

    //5.const修饰指针
    /*
    1、const修饰指针---常量指针
    2、const修饰常量---指针常量
    3、const即修饰又修饰常量
    */
    int a1 = 10;
    int b1 = 10;
    
    const int* p4 = &a1;//常量指针 指针前面加上const限定
    /*
    指针的指向可以改，指针指向的值不能修改
    */
    //*p = 20;//错误，指向的值不能改
    //p = &b1;//正确,指向可以改

    int* const p5 = &a1;//指针常量 
    /*
    指针的指向不能修改，指针指向的值可以修改
    */
    //*p = 20;//正确
    //p = &b1;//错误

    const int* const p6 = &a1;
    /*
    指针指向的值，指针的指向都不能修改
    */









    cout << "*****************************" << endl;
    /*
    指针和数组
    */
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    cout << "first item " << arr[0] << endl;
    int* p7 = arr;
    cout << "first item " << *p7 << endl;
    p7++;//指针向后偏移4个字节
    cout << "second item " << *p7 << endl;

    int* p8 = arr;
    for (int i = 0; i < 10; i++) {
        cout << *p8 << endl;
        p8++;
    }
     
    cout << "*****************************" << endl;
    /*
    指针和函数
    1.值传递
        普通的函数调用方式

    2.地址传递
        可以修改实参

    需要改变实参就用地址传递
    */
    int aa = 10;
    int bb = 20;
    swap(&aa, &bb);
    cout << "aa: " << aa << endl;
    cout << "bb: " << bb << endl;




    /*
    指针加数组加函数
    */
    int arr3[10] = { 4,3,6,9,1,2,10,7,8,5 };
    int len = size(arr3);
    //1.函数实现冒泡排序
    buubleSort(arr3, len);//数组名就是地址
    printArray(arr3, len);






    cout << "*****************************" << endl;
    /*
    结构体：用户自定义的数据类型
    */
    Student s1;//struct关键字可以省略
    s1.name = "zhangsan";
    s1.age = 18;
    s1.score = 90;
    cout << s1.name << " " << s1.age << " " << s1.score << endl;

    struct Student s2 = {"lisi",20,80};
    cout << s2.name << " " << s2.age << " " << s2.score << endl;

    s3.name = "wangwu";
    s3.age = 18;
    s3.score = 60;
    cout << s3.name << " " << s3.age << " " << s3.score << endl;

    /*
    结构体数组
    */
    //1.定义

    //2.创建数组
    Student stuArray[3] = {
        {"zhangsan",18,100},
        {"lisi",19,90},
        {"wangwu",20,80}
    };
    stuArray[2].name = "zhaoliu";

    //遍历
    for (int i = 0; i < 3; i++) {
        cout << "name " << stuArray[i].name << " " << "age " << stuArray[i].age;
        cout << " " << "score " << stuArray[i].score << endl;
    }

    /*
    结构体指针
    ->
    */
    //1.通过指针指向结构体变量
    Student* p9 = &s1; 

    //2.通过指针访问结构体变量中的数据
    cout << p9->name << " " << p9->age << " " << p9->score << endl;


    /*
    结构体嵌套结构体
    */
    //创建老师
    Teacher t;
    t.age = 50;
    t.id = 10000;
    t.name = "laowang";
    t.stu.name = "xiaowang";
    t.stu.age = 19;
    t.stu.score = 87;

    cout << t.name << " " << t.age << " " << t.stu.name << endl;


    /*
    结构体做函数参数
    1.值传递
        不改变实参
    2.地址传递
        改变实参
    
    函数打印学生的所有信息
    */
    cout << "information in main function " << s1.name << " "
        << s1.age << " " << s1.score << endl;
    printStu1(s1);
    printStu2(&s1);
    cout << "information in main function " << s1.name << " "
        << s1.age << " " << s1.score << endl;

    /*
    结构体的const
    */
    printStu1(s2);//使用值传递会在函数中复制一个新对副本
    printStu2(&s2);//使用地址传递可以减少内存空间的消耗，而且不会产生新对副本
    //地址传递会导致函数体内修改值，影响了原有的数据，在形参前加const






    system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

/*
p65
c++
*/
