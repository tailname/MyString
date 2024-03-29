// Copyright 2014 Google Inc. All Rights Reserved.
#pragma once
#include <iostream>
#include<string>
class MyString {
 protected:
    char* my_string;
    int len;

 private:
    int FindLen(const char* CharString) const;
    char* WriteString(char* WhereToWriteString,
                      const char* CharString, int len);


 public:
    explicit MyString(const char* char_is_string);
    explicit MyString(const std::string& is_string);
    MyString(const MyString& exist_string);
    explicit MyString(MyString&& exist_string);

    MyString();
    ~MyString();

    char* get() const;
    unsigned int length() const;

    MyString& operator=(const MyString& is_string);
    MyString& operator=(MyString&& is_string);
    MyString operator!();

    bool operator!= (const MyString& is_string) const;
    bool operator== (const MyString& is_string) const;
    bool operator> (const MyString& is_string) const;
    bool operator< (const MyString& is_string) const;
    bool operator<= (const MyString& is_string) const;
    bool operator>= (const MyString& is_string) const;
    bool operator!= (const char* char_is_string) const;
    bool operator== (const char* char_is_string) const;
    bool operator> (const char* char_is_string) const;
    bool operator< (const char* char_is_string) const;
    bool operator<= (const char* char_is_string) const;
    bool operator>= (const char* char_is_string) const;


    char& operator[](unsigned int index) const;
    int operator()(const char* is_string) const;


    friend std::ostream& operator<<(std::ostream& os,
                                    const MyString& is_string);
    friend std::istream& operator>>(std::istream& is, MyString& is_string);
    friend MyString operator-(const MyString& where_del_string,
                              const MyString& what_del_string);
    friend MyString operator+(const MyString& is_string,
                              const char* string_char);
    friend MyString operator+(const MyString& string_first,
                              const MyString& string_second);
    friend MyString operator*(MyString is_string, unsigned int lenght);
};

