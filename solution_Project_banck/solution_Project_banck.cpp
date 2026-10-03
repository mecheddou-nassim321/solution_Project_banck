#include <iostream>
#include "clsLoginScreen.h"
#include"clsCurrency.h"
#include"cstdio"
template<class T>
class calculator {
private:
    T number1;
    T number2;
public:
    calculator(T n1, T n2) {
        number1 = n1;
        number2 = n2;
    }
    void printResult() {
        cout << "Numbers:" << number1 << "and " << number2;
    
        cout << "\n" << number1 << "+" << number2 << "=" << add();
        cout << "\n" << number1 << "-" << number2 << "=" << substr();
        cout << "\n" << number1 << "*" << number2 << "=" << multiply();
        cout << "\n" << number1 << "/" << number2 << "=" << Devide();

    }
    T add() {
        return number1 + number2;
    }
    T substr() {
        return number1 - number2;
    }
    T multiply() {
        return number1 * number2;
    }
    T Devide() {
        return number1 / number2;
    }
};
template<typename T>T myMax(T number1, T number2) {
    return number1 > number2 ? number1 : number2;
}
int main()

{
    int num;
    cout << "please enter number of students:";
    cin >> num;
    float* ptr;
    ptr = new float[num];
    cout << "please enter grade of student:\n";
    for (int i = 0; i < num; i++) {
        cout << "student " << i + 1<<":";
        cin >> *(ptr + i);
    }
    for (int i = 0; i < num; i++) {
        cout <<"student"<<i+1<<":"<< * (ptr + i)<<endl;
    }
    delete[]ptr;
    return 0;
}