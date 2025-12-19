#include "octal.h"
#include <iostream>
#include <fmt/core.h>
using namespace std;



int main() {
    string s1, s2;
    cout << "Введите первое восьмиричное число:  ";
    cin >> s1;
    cout << "Введите второе восьмиричное число:  ";
    cin >> s2;

    Octal* o1 = Octal::fromstring(s1);
    Octal* o2 = Octal::fromstring(s2);

    cout << o1->tostring() << endl;
    cout << o2->tostring() << endl;

    Octal* sum = o1->add(*o2);
    Octal* difference = o1->subtract(*o2);

    cout << fmt::format("{} + {} = {}", o1->tostring(), o2->tostring(), sum->tostring()) << endl;
    cout << fmt::format("{} - {} = {}", o1->tostring(), o2->tostring(), difference->tostring()) << endl;

    cout << fmt::format("{} > {} = {}", o1->tostring(), o2->tostring(), o1->gt(*o2)) << endl;
    cout << fmt::format("{} < {} = {}", o1->tostring(), o2->tostring(), o1->lt(*o2)) << endl;
    cout << fmt::format("{} == {} = {}", o1->tostring(), o2->tostring(), o1->eq(*o2)) << endl;

    delete o1, o2, sum, difference;
}
