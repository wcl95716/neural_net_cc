//
// Created by Panda on 2021/6/21.
//

#include "lib.h"
#include <iostream>

#include <cmath>
#include <string>

using namespace  std;
using std::swap;

#define LOWER 0
#define UPPER 300
#define STEP 20

void helloWorld(){
    cout<<"hello World!"<<endl;
}

void Wendu(){
    cout << "That is a temperate list" << endl;
    float farh, C;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    farh = lower;
    while (farh <= upper){
        C = (5.0 / 9.0) * (farh - 32);
        cout << farh << " " << C << endl;
        farh = farh + step;
    }
}

void WenDu2(){
    float farh, c;
    int lower, upper, step;

    lower = -17;
    upper = 148;
    step = 11;

    c = lower;
    while (c <= upper){
        farh = 9.0 * c / 5.0 + 32;
        cout << farh << " " << c << endl;
        c = c + step;
    }
}

void ForTest(){
    int farh;

    for(farh = 300; farh >= 0; farh = farh - 20){
        cout << farh << endl;
    }
}


void SymbolConstTest(){
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        cout << 5.0 / 9.0 * (fahr - 32) << endl;
}

void IfTest(){
    int a = 50;

    if (a == 10)
    {
        cout << "the value of a is 10" << endl;
    }
    else if (a == 20)
    {
        cout << "the value of a is 20" << endl;
    }
    else if (a == 30)
    {
        cout << "the value of a is 30" << endl;
    }
    else
    {
        cout << "there is no nothing to match" << endl;
    }
    cout << "the acurate value of a is " << a << endl;

}

int FunctionTest(int num1, int num2){
//    函数 值传递
    int result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}

void CmathTest(){
    //需要 #include <cmath>
    short s = 10;
    int   i = -1000;
    long  l = 100000;
    float f = 250;
    double d = 200.374;

    //数学运算
    cout << "sin(d) : " << sin(d) << endl;
    cout << "abs(i) :" << abs(i) << endl;
    cout << "floor(d) :" << floor(d) << endl;
    cout << "sqrt(f): " << sqrt(f) <<endl;
    cout << "pow(s, 2) :" << pow(s, 2) << endl;


}

void ShuZuTest(){
    double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    double b2[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    balance[4] = 100.0;

    double salary = balance[4];

    int n[10];

    for (int i=0; i < 10; i++){
        n[i] = i + 100;
    }
    cout << "Element   value" << endl;

    //print the element of n
    for (int j=0; j<10; j++){
        cout << j << "    " << n[j] << endl;
    }
}

void StringTest(){
    //C++中 单引号是字符常量，即char, 双引号是字符串常量，即string
    //使用string时，需要使用#include <string>
    char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};
    char site1[] = "RUNNOOB";

    cout << "cai niao jiaocheng:";
    cout << site << endl;

    string str1 = "runoob";
    string str2 = "google";
    string str3;
    int len;

    //copy str1 to str3
    str3 = str1;
    cout << "str3: " << str3 << endl;

    //joint str1 and str2
    str3 = str1 + str2;
    cout << "str1 + str2: " << str3 << endl;

    //the len of str3,值的长度计算是不包含 \0的
    len = str3.size();
    cout << "str3.size() :" << len << endl;

}
