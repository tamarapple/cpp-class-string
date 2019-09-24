
/* Created by tamarapple on 9/15/19 */


#ifndef MYSTRING_C___MY_STRING_H
#define MYSTRING_C___MY_STRING_H

#include <iostream>
#include <cstring>

using namespace std;

class MyString {

public:

    MyString(const char *myString = NULL);

    MyString(const MyString &myString);

    ~MyString();

    const char *c_str() const;

    size_t length();

    char &operator[](size_t index);

    MyString &operator=(const MyString &myString);

    MyString &operator+=(const MyString &myString);

    friend ostream &operator<<(ostream &, const MyString &myString);

private:
    size_t m_size;
    char *m_buffer;


};

inline const char *MyString::c_str() const {
    return m_buffer;
}

inline bool operator==(const MyString &myString_1, const MyString &myString_2) {
    return (!(strcmp(myString_1.c_str(), myString_2.c_str())));
}

inline bool operator!=(const MyString &myString_1, const MyString &myString_2) {
    return (!(myString_1==myString_2));
}

inline bool operator<=(const MyString &myString_1, const MyString &myString_2) {
    int strcmp_ans;
    strcmp_ans = strcmp(myString_1.c_str(), myString_2.c_str());
    if (strcmp_ans < 1)
        return true;
    else
        return false;
}


inline bool operator<(const MyString &myString_1, const MyString &myString_2) {
    int strcmp_ans;
    strcmp_ans = strcmp(myString_1.c_str(), myString_2.c_str());
    if (strcmp_ans < 0)
        return true;
    else
        return false;
}

inline bool operator>(const MyString &myString_1, const MyString &myString_2) {
    return !(myString_1<= myString_2);

}

inline bool operator>=(const MyString &myString_1, const MyString &myString_2) {
    return !(myString_1< myString_2);
}


inline bool operator==(const char *string_1, const MyString &myString_2) {
    return MyString(string_1) == myString_2;
}

inline bool operator!=(const char *string_1, const MyString &myString_2) {
    return MyString(string_1) != myString_2;
}

inline bool operator<=(const char *string_1, const MyString &myString_2) {
    return MyString(string_1) <= myString_2;
}

inline bool operator<(const char *string_1, const MyString &myString_2) {
    return MyString(string_1) < myString_2;
}

inline bool operator>(const char *string_1, const MyString &myString_2) {
    return MyString(string_1) > myString_2;
}

inline bool operator>=(const char *string_1, const MyString &myString_2) {
    return MyString(string_1)>=myString_2;
}

#endif /* MYSTRING_C___MY_STRING_H */
