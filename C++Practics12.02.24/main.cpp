  // Copyright 2014 Google Inc. All Rights Reserved.


#include <iostream>
#include <cassert>
#include "MyString.h"

int main() {
    // Тест конструктора с одним параметром типа const char*
    MyString str1("Hello");
    assert(str1.length() == 5);

    // Тест конструктора с одним параметром типа std::string
    std::string s = "World";
    MyString str2(s);
    assert(str2.length() == 5);

    // Тест конструктора копирования
    MyString str3 = str1;
    assert(str3.length() == str1.length());


    // Тест деструктора
    {
        MyString str5("Test");
        MyString str4;
        str4.~MyString();
    }  // str5 выходит из области видимости и вызывается деструктор

    // Тест оператора +
    MyString str6;
    str6 = str1 + str3;
    assert(str6.length() == 10);

    // Тест оператора -
    MyString str7 = MyString("abcdefg") - MyString("aceg");
    assert(str7 == "bdf");

    // Тест оператора *
    MyString str8 = str1 * 3;
    assert(str8 == "HelloHelloHello");

    // Тест копирующего присваивания
    MyString str9;
    str9 = str1;
    assert(str9.length() == str1.length());


    // Тест операторов сравнения
    assert(str1 == "Hello");
    assert(str1 != "World");
    assert(str1 > "Gello");
    assert(str1 < "Mello");
    assert(str1 >= "Hello");
    assert(str1 <= "Hello");

    // Тест оператора !
    MyString str11("AbC");
    str11 = !str11;
    assert(str11 == "aBc");

    // Тест оператора []
    assert(str1[0] == 'H');
    assert(str1[4] == 'o');

    // Тест оператора ()
    assert((str1("el") == 1));
    assert((str1("llo") == 2));

    // Тест операторов ввода/вывода
    MyString str12;
    std::cout << "Enter a string: ";
    std::cin >> str12;
    std::cout << "You entered: " << str12 << std::endl;

    return 0;
}
