
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
        //+1 for \0
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
    delete[] m_buffer;
    m_buffer = NULL;
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


ostream &operator<<(ostream &os, const MyString &myString) {
    os<<myString.c_str();
    return os;
}