#ifndef __STRING__HPP
#define __STRING__HPP

#include<iostream>
using namespace std;

class String
{
    
char *contains;
int length;
unsigned int String::nposition=2147483647;

String();
String(const String &);
String(const char*);

~String();

String& operator=(const char*);
String& operator=(const String&);

String operator+(const String&);

bool operator==(String &);
bool operator!=(String &);

int operator<(String &);
int operator>(String &);

char front();
char back();
char at(int);

int empty();

int Length();

int size();

void pop_back();

void swap(const String&);

String& erase();
String& erase(int);
String& erase(int,int);

void push_back(char);

void assign(int,char);
void assign(const char*);
void assign(const char*,int);
void assign(const char*,int,int);
void assign(const String &);
void assign(const String &,int);
void assign(const String &,int,int);

void append(int,char); 
void append(const char*);
void append(const char*,int);
void append(const String&);
void append(const String &,int count);
void append(const String &e,int from,int count);

void insert(int at,int count,char e);
void insert(int at,const char *e);
void insert(int at,const char *e,int count);
void insert(int at,String &e);
void insert(int at,const String &e,int count);

int compare(const char *e);
int compare(String &s);

unsigned int find(const char *e,int pos=0);
unsigned int find(const String &e,int pos=0);

unsigned int find_first_of(const char *e,int pos=0);
unsigned int find_first_of(const String &e,int pos=0);

unsigned int find_last_of(const char *e,int pos=0);
unsigned int find_last_of(const String &e,int pos=0);

unsigned int find_first_not_of(const char *e,int pos=0);
unsigned int find_first_not_of(const String &e,int pos=0);

unsigned int find_last_not_of(const char *e,int pos=0);
unsigned int find_last_not_of(const String &e,int pos=0);

void replace(int at,int repcount,int count,const char e);
void replace(int at,int repcount,const char *e);
void replace(int at,int repcount,int count,const char *e);
void replace(int at,int repcount,const String &e);
void replace(int at,int repcount,int count,const String &e);

String substr(int from,int to);

String& upperCase();
String& upperCase(int from,int to);

String& lowerCase();
String& lowerCase(int from,int to);

String& toggleCase();
String& toggleCase(int from,int to);

bool endsWith(const char *e);

String& reverse();

friend ostream& operator<<(ostream &cout,String &object);
};

ostream& operator<<(ostream &cout,String &object)
{
cout<<object.contains;
return cout;
}

#endif
