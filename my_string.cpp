
/* Created by tamarapple on 9/15/19 */


#include "my_string.h"
#include <cstring>
#include <assert.h>

MyString::MyString(const char *myString) {

    if (myString) {
        //if (m_buffer) {
        //  delete[] m_buffer;
        //m_buffer = NULL;
        //}
        m_size = strlen(myString);
        size_t len = strlen(myString) + 1;
        m_buffer = new char[len];
        strncpy(m_buffer, myString, len);
    } else {
        m_buffer = NULL;
        m_size = 0;
    }

}

MyString::MyString(const MyString &myString) {

    //if (m_buffer) {
    //  delete[] m_buffer;
    //m_buffer = NULL;
    //}
    m_size = myString.m_size;

    m_buffer = new char[m_size];
    strncpy(m_buffer, myString.m_buffer, m_size);


}


MyString::~MyString() {
    if (m_buffer)
        delete[] m_buffer;
    m_buffer = NULL;
}

const char *MyString::c_str() {
    return m_buffer;
}



size_t MyString::length() {
    if (!m_buffer) {
        return 0;
    } else {
        return strlen(m_buffer);
    }
}


char &MyString::operator[](size_t index) {
    if (index < this->m_size) {
        return m_buffer[index];
    } else
        throw "invalid index";
}


MyString &MyString::operator=(const MyString &myString) {

    if (this != &myString && myString.m_buffer) {
        if (this->m_buffer)
            delete[] m_buffer;

        m_size = myString.m_size;

        m_buffer = new char[m_size];
        strncpy(m_buffer, myString.m_buffer, m_size);
    }
    return *this;
}



MyString &MyString::operator+=(const MyString &myString) {
    if (myString.m_buffer) {
        strcat(m_buffer, myString.m_buffer);
        m_size = m_size + myString.m_size;
    }
    return *this;
}


bool operator==(const MyString &myString_1, const MyString &myString_2) {
    return (!(strcmp(myString_1.m_buffer, myString_2.m_buffer)));
}

bool operator<=(const MyString &myString_1, const MyString &myString_2) {
    int strcmp_ans;
    strcmp_ans = strcmp(myString_1.m_buffer, myString_2.m_buffer);
    if (strcmp_ans <= 1)
        return true;
    else
        return false;
}

bool operator<(const MyString &myString_1, const MyString &myString_2) {
    int strcmp_ans;
    strcmp_ans = strcmp(myString_1.m_buffer, myString_2.m_buffer);
    if (strcmp_ans < 0)
        return true;
    else
        return false;

}

bool operator>(const MyString &myString_1, const MyString &myString_2) {
    return !operator<=(myString_1, myString_2);
}

bool operator>=(const MyString &myString_1, const MyString &myString_2) {
    return !operator<(myString_1, myString_2);
}

ostream &operator<<(ostream &os, const MyString &myString) {
    for (size_t i = 0; i < myString.m_size; i++) {
        os << myString.m_buffer[i];
    }
    return os;
}