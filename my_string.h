
/* Created by tamarapple on 9/15/19 */


#ifndef MYSTRING_C___MY_STRING_H
#define MYSTRING_C___MY_STRING_H

#include <iostream>

using namespace std;

class MyString {

public:

    MyString(const char *myString = NULL);

    MyString(const MyString &myString);

    ~MyString();

    const char* c_str();

    size_t length();

    char &operator[](size_t index);

    MyString&  operator=(const MyString &myString);

    MyString & operator+=(const MyString &myString);


    friend bool operator==(const MyString &, const MyString &myString);

    friend bool operator<=(const MyString &, const MyString &myString);

    friend bool operator<(const MyString &, const MyString &myString);

    friend bool operator>(const MyString &, const MyString &myString);

    friend bool operator>=(const MyString &, const MyString &myString);


    friend ostream &operator<<(ostream &, const MyString &myString);

private:
    size_t m_size;
    char *m_buffer;


};

#endif /* MYSTRING_C___MY_STRING_H */
