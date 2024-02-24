  // Copyright 2014 Google Inc. All Rights Reserved.
#include"MyString.h"
MyString::MyString() {
    len = 0;
    my_string = nullptr;
}


MyString::MyString(const char* CharString) {
    len = FindLen(CharString);
    my_string = WriteString(my_string, CharString, len);
}

MyString::MyString(const std::string& is_string) {
    len = is_string.length()+1;
    my_string = WriteString(my_string, is_string.c_str(), len);
}

MyString::MyString(const MyString& exist_string) {
    len = exist_string.length()+1;
    my_string = WriteString(my_string, exist_string.get(), len);
}

MyString::MyString(MyString&& exist_string) {
    my_string = exist_string.get();
    len = exist_string.length()+1;
    exist_string.len = 0;
    exist_string.my_string = nullptr;
}

MyString::~MyString() {
    len = 0;
    if (my_string == nullptr) {
        return;
    }
    delete[] my_string;
    my_string = nullptr;
}
MyString operator+(const MyString& is_string, const char* string_char) {
    MyString ms(string_char);
    return is_string + ms;
}

MyString operator+(const MyString& string_first,
                   const MyString& string_second) {
    char* my_plus_char = new char[string_first.length() +
                                  string_second.length() +
                                  1];
    std::snprintf(my_plus_char, string_first.length() + 1,
                  "%s", string_first.get());
    std::snprintf(my_plus_char+ (string_first.length()),
                  string_second.length()+1,
                  "%s", string_second.get());
    my_plus_char[string_first.length() + string_second.length()] = '\0';
    MyString plus_string(my_plus_char);
    delete[] my_plus_char;
    return plus_string;
}
MyString MyString::operator!() {
    MyString flip_register(my_string);
    for (int i = 0; i < flip_register.length(); ++i) {
        if (flip_register.get()[i] >= 'a' && flip_register.get()[i] <= 'z') {
            flip_register.my_string[i] = flip_register.get()[i] - 'a' + 'A';
        } else if (flip_register.get()[i] >= 'A' &&
                 flip_register.get()[i] <= 'Z') {
            flip_register.my_string[i] = flip_register.my_string[i]-'A' + 'a';
        }
    }
    return flip_register;
}




char* MyString::get() const {
    return my_string;
}

unsigned int MyString::length() const {
    if (len == 0) {
        return len;
    }
    return len - 1;
}

char* MyString::WriteString(char* WhereToWriteString,
                            const char* CharString, int len) {
    WhereToWriteString = new char[len];
    if (len == 0) {
        return nullptr;
    }

    std::snprintf(WhereToWriteString, len, "%s", CharString);
    return WhereToWriteString;
}
MyString operator-(const MyString& where_del_string,
                   const MyString& what_del_string) {
    char* minus_char = new char[where_del_string.length()+1];
    int len = 0;
    for (int i = 0; i < where_del_string.length() ; ++i) {
        bool flag = true;
        for (int j = 0; j < what_del_string.length(); ++j) {
            if (where_del_string[i] == what_del_string[j]) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            minus_char[len++] = where_del_string[i];
        }
    }
    minus_char[len] = '\0';
    MyString minus_string(minus_char);
    delete[] minus_char;
    return minus_string;
}
MyString operator*(MyString is_string, unsigned int lenght) {
    char* multiplication_char = new char[is_string.length() * lenght+1];
    for (int i = 0; i < lenght; ++i) {
        std::snprintf(multiplication_char + i * is_string.length(),
                      is_string.length()+1, "%s", is_string.get());
    }
    multiplication_char[is_string.length() * lenght] = '\0';
    MyString multiplication_string(multiplication_char);
    return multiplication_string;
}
MyString& MyString::operator=(const MyString& is_string) {
    delete[] my_string;
    my_string = WriteString(my_string, is_string.get(), is_string.length()+1);
    len = is_string.length() + 1;
    return *this;
}
MyString& MyString::operator=(MyString&& is_string) {
    if (is_string.get() == my_string) {
        return *this;
    }
    delete[] my_string;
    my_string = is_string.get();
    len = is_string.length()+1;
    is_string.my_string = nullptr;
    is_string.len = 0;
    return is_string;
}





bool MyString::operator!= (const MyString& is_string) const {
    if (len != is_string.length()+1) {
        return true;
    }
    for (int i = 0; i < len; ++i) {
        if (my_string[i] != is_string.get()[i]) {
            return true;
        }
    }
    return false;
}
bool MyString::operator== (const MyString& is_string) const {
    return !(*this != is_string);
}
bool MyString::operator> (const MyString& is_string) const {
    return (*this >= is_string) && (*this != is_string);
}
bool MyString::operator< (const MyString& is_string) const {
    return (*this <= is_string) && (*this != is_string);
}
bool MyString::operator<= (const MyString& is_string) const {
    return !(*this >= is_string) || (*this == is_string);
}
bool MyString::operator>= (const MyString& is_string) const {
    for (int i = 0; i < len; i++) {
        if (i > is_string.length() || my_string[i] > is_string.get()[i]) {
            return false;
        } else if (my_string[i] < is_string.get()[i]) {
            return true;
        }
    }
    return true;
}

char& MyString::operator[](unsigned int index) const {
    return my_string[index];
}
int MyString::operator()(const char* is_string) const {
    for (int i = 0; i < len; ++i) {
        bool flag = true;
        int iterator_for_my_string = i;
        for (int j = 0; j < FindLen(is_string)-1; ++j) {
            if (iterator_for_my_string > len ||
                my_string[iterator_for_my_string++] != is_string[j]) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            return i;
        }
    }
    return -1;
}
bool MyString::operator != (const char* char_is_string) const {
    return MyString(char_is_string) != *this;
}
bool MyString::operator == (const char* char_is_string) const {
    return MyString(char_is_string) == *this;
}
bool MyString::operator> (const char* char_is_string) const {
    return MyString(char_is_string) > *this;
}
bool MyString::operator< (const char* char_is_string) const {
    return MyString(char_is_string) < *this;
}
bool MyString::operator<= (const char* char_is_string) const {
    return MyString(char_is_string) <= *this;
}
bool MyString::operator>= (const char* char_is_string) const {
    return MyString(char_is_string) >= *this;
}



std::ostream& operator<<(std::ostream& os, const MyString& is_string) {
    for (int i = 0; i < is_string.length(); ++i) {
        os << is_string.get()[i];
    }
    return os;
}
std::istream& operator>>(std::istream& is, MyString& is_string) {
    char buf[1024];

    is.get(buf, 1024);
    is_string = MyString(buf);
    return is;
}

int MyString::FindLen(const char* CharString) const {
    int i = 0;
    if (CharString == nullptr) return 0;
    while (CharString[i] != '\0') {
        ++i;
    }
    return ++i;
}
