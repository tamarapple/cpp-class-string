
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

    m_buffer = new char[m_size+1];
    strncpy(m_buffer, myString.m_buffer, m_size+1);


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
        return m_size;
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

bool MyString::operator==(const MyString &myString){
    return (!(strcmp(m_buffer, myString.m_buffer)));
}

bool MyString::operator!=(const MyString &myString){
    return (!this->operator==(myString));
}

bool MyString::operator<=(const MyString &myString){
    int strcmp_ans;
    strcmp_ans = strcmp(m_buffer, myString.m_buffer);
    if (strcmp_ans < 1)
        return true;
    else
        return false;
}

bool MyString::operator<(const MyString &myString){
    int strcmp_ans;
    strcmp_ans = strcmp(m_buffer, myString.m_buffer);
    if (strcmp_ans < 0)
        return true;
    else
        return false;
}

bool MyString::operator>(const MyString &myString){
    return !(this->operator<=(myString));
}

bool MyString::operator>=(const MyString &myString){
    return !(this->operator<(myString));

}

bool operator==(const char * string_1 ,const MyString &myString_2){
    return MyString(string_1).operator==(myString_2);
}

bool operator!=(const char * string_1 ,const MyString &myString_2){
    return MyString(string_1).operator!=(myString_2);
}

bool operator<=(const char * string_1 ,const MyString &myString_2){
    return MyString(string_1).operator<=(myString_2);
}

bool operator<(const char * string_1 ,const MyString &myString_2){
    return MyString(string_1).operator<(myString_2);
}

bool operator>(const char * string_1 ,const MyString &myString_2){
    return MyString(string_1).operator>(myString_2);
}

bool operator>=(const char * string_1 ,const MyString &myString_2){
    return MyString(string_1).operator>=(myString_2);
}

ostream &operator<<(ostream &os, const MyString &myString) {
    for (size_t i = 0; i < myString.m_size; i++) {
        os << myString.m_buffer[i];
    }
    return os;
}