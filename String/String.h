#ifndef __STRING_H_
#define __STRING_H_

#include<iostream>
#include<string.h>
using namespace std;

class String{
    char *p;
    int size;
    public:
        String();
        String(char *str);
        String(const String &o);
        ~String() { delete [] p; }

         friend ostream &operator<<(ostream &stream, String &o);
         friend istream &operator>>(istream &stream, String &o);

        String operator=(String &o);
        String operator=(char *s);

        String operator+(String &o);
        String operator+(char *s);
        friend String operator+(char *s, String &o);

        String operator-(String &o);
        String operator-(char *s);

        int operator==(String &o) { return !strcmp(p, o.p); }
        int operator!=(String &o) { return strcmp(p, o.p); }
        int operator<(String &o) { return strcmp(p, o.p) < 0; }
        int operator>(String &o) { return strcmp(p, o.p) > 0; }
        int operator<=(String &o) { return strcmp(p, o.p) <= 0; }
        int operator>=(String &o) { return strcmp(p, o.p) >= 0; }

        int operator==(char *s){ return !strcmp(p, s); }
        int operator!=(char *s) { return strcmp(p, s); }
        int operator<(char *s) { return strcmp(p, s) < 0; }
        int operator>(char *s) { return strcmp(p, s) > 0; }
        int operator<=(char *s) { return strcmp(p, s) <= 0; }
        int operator>=(char *s) { return strcmp(p, s) >= 0; }

        int length() { return strlen(p); }
        void c_string(char *s) { strcpy(s,p); }

        /*
        Recall that a conversion function is automatically executed when an object is involved
        in an expression for which the conversion is defined. In this case, because the prototype
        for the strcpy( ) function tells the compiler that its second argument is of type char *,
        the conversion from StrType to char * is automatically performed, causing a pointer
        to the string contained within x to be returned.
        */
        operator char *() { return p; }
};

#endif // __STRING_H_
