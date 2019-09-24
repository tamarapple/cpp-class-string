
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

inline MyString::MyString(const char *myString) {
    if (myString) {
        m_size = strlen(myString);
        //+1 for \0
        size_t len = strlen(myString) + 1;
        m_buffer = new char[len];
        strncpy(m_buffer, myString, len);
    } else {
        m_buffer = NULL;
        m_size = 0;
    }
}

inline MyString::MyString(const MyString &myString) {
    m_size = myString.m_size;
    m_buffer = new char[m_size+1];
    strncpy(m_buffer, myString.m_buffer, m_size+1);
}

inline MyString::~MyString() {
    delete[] m_buffer;
    m_buffer = NULL;
}

inline size_t MyString::length() {
    if (!m_buffer) {
        return 0;
    } else {
        return m_size;
    }
}

inline const char *MyString::c_str() const {
    return m_buffer;
}

inline char &MyString::operator[](size_t index) {
    if (index < this->m_size) {
        return m_buffer[index];
    } else
        throw "invalid index";
}


inline MyString &MyString::operator=(const MyString &myString) {

    if (this != &myString && myString.m_buffer) {
        if (this->m_buffer)
            delete[] m_buffer;

        m_size = myString.m_size;

        m_buffer = new char[m_size];
        strncpy(m_buffer, myString.m_buffer, m_size);
    }
    return *this;
}



inline MyString &MyString::operator+=(const MyString &myString) {
    if (myString.m_buffer && m_buffer) {
        strcat(m_buffer, myString.m_buffer);
        m_size = m_size + myString.m_size;
    }
    return *this;
}


inline ostream &operator<<(ostream &os, const MyString &myString) {
    if(myString.m_buffer) {
        os << myString.m_buffer;
    }
    return os;
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
