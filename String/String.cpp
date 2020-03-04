#include "String.h"
using namespace std;

#define MAX_SIZE 1<<16

String::String(){
    size = 1;
    try{
        p = new char[size];
    }
    catch(bad_alloc xa){
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(p, "");
}

String::String(char *str){
    size = strlen(str) + 1;
    try{
        p = new char[size];
    } catch(bad_alloc xa){
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(p, str);
}

String::String(const String &o){
    size = o.size;
    try{
        p = new char[size];
    } catch(bad_alloc xa){
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(p, o.p);
}

ostream &operator<<(ostream &stream, String &o){
    stream << o.p;
    return stream;
}

istream &operator>>(istream &stream, String &o){
    char t[MAX_SIZE];
    int len;

    stream.getline(t, MAX_SIZE);
    len = strlen(t) + 1;

    if(len > o.size){
        delete [] o.p;
        try{
            o.p = new char[len];
        } catch(bad_alloc xa){
            cout << "Allocation error\n";
            exit(1);
        }
        o.size = len;
    }
    strcpy(o.p, t);
    return stream;
}

String String::operator=(String &o){
    String temp(o.p);

    if(o.size > size){
        delete [] p;
        try{
            p = new char[o.size];
        } catch(bad_alloc xa){
            cout << "Allocation error\n";
            exit(1);
        }
        size = o.size;
    }

    strcpy(p, o.p);
    strcpy(temp.p, o.p);
    return temp;
}

String String::operator=(char *s){
    int len = strlen(s) + 1;

    if(size < len){
        delete [] p;
        try{
            p = new char[len];
        } catch(bad_alloc xa){
            cout << "Allocation error\n";
            exit(1);
        }
        size = len;
    }

    strcpy(p, s);
    return *this;
}


String String::operator+(String &o){
    int len;
    String temp;
    delete temp.p;

    len = strlen(o.p) + strlen(p) + 1;
    temp.size = len;

    try{
        temp.p = new char[len];
    } catch(bad_alloc xa){
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(temp.p, p);
    strcat(temp.p, o.p);
    return temp;
}

String String::operator+(char *s){
    int len;
    String temp;
    delete [] temp.p;

    len = strlen(s) + strlen(p) + 1;
    temp.size = len;

    try{
        temp.p = new char[len];
    } catch(bad_alloc xa){
        cout << "Allocation error\n";
        exit(1);
    }

    strcpy(temp.p, p);
    strcat(temp.p, s);
    return temp;
}

String operator+(char *s, String &o){
    int len;
    String temp;
    delete [] temp.p;

    len = strlen(s) + strlen(o.p) + 1;
    temp.size = len;
    try{
        temp.p = new char[len];
    } catch(bad_alloc xa){
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(temp.p, s);
    strcat(temp.p, o.p);
    return temp;
}

String String::operator-(String &substr){
    String temp(p);
    char *s1;
    int i, j;
    s1 = p;
    for(i = 0; *s1; i++){
        if(*s1 != *substr.p){
            temp.p[i] = *s1;
            s1++;
        }
        else{
            for(j = 0; substr.p[j] == s1[j] && substr.p[j]; j++);
            if(!substr.p[j]){
                s1 += j;
                i--;
            }
            else{
                temp.p[i] = *s1;
                s1++;
            }
        }
    }
    temp.p[i] = '\0';
    return temp;
}

String String::operator-(char *substr){
    String temp(p);
    char *s1;
    int i, j;

    s1 = p;
    for(i = 0; *s1; i++){
        if(*s1 != *substr){
            temp.p[i] = *s1;
            s1++;
        }
        else{
            for(j = 0; substr[j] == s1[j] && substr[j]; j++);
            if(!substr[j]){
                s1 += j;
                i--;
            }
            else{
                temp.p[i] = *s1;
                s1++;
            }
        }
    }
    temp.p[i] = '\0';
    return temp;
}

