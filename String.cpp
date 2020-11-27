#ifndef __STRING__CPP
#define __STRING__CPP

#include "String.hpp"

using namespace std;

String::String()
{
length=0;
contains=NULL;
}

String::String(const String &e)
{
int index;
length=e.length;
contains=new char[length+1];
for(index=0;index<length && index<e.length;index++) contains[index]=e.contains[index];
contains[index]='\0';
}

String::String(const char *e)
{
int index,arglength;
const char *m;
for(m=e,arglength=0;*m!='\0';m++,arglength++);
length=arglength-1;
contains=new char[length+1];
for(index=0;index<arglength;index++) contains[index]=e[index];
contains[index]='\0';
}

String::~String()
{
delete [] contains;
}

String& String::operator=(const char* e)
{
int index;
const char* x;
x=e;
for(length=0;*e!='\0';e++,length++);
contains=new char[length];
for(index=0;index<length;index++) contains[index]=x[index];
contains[index]='\0';
return *this;
}

String& String::operator=(const String &e)
{
int index;
length=e.length;
delete [] contains;
contains=new char[length+1];
for(index=0;index<length;index++) contains[index]=e.contains[index];
contains[index]='\0';
return *this;
}

String String::operator+(const String &s2)
{
int index,index2;
char *temp;
temp=new char[length+s2.length+1];
for(index=0;index<length;index++) temp[index]=contains[index];
for(index2=0;index2<s2.length;index++,index2++) temp[index]=s2.contains[index2];
temp[index]='\0';
String newString(temp);
delete [] temp;
return newString;
}

bool String::operator==(String &s)
{
int index;
if(this->length!=s.length) return false;
else
{
for(index=0;index<length;)
{
if(this->contains[index]==s.contains[index]) index++;
else return false;
}
return true;
}
}

bool String::operator!=(String &s)
{
int index;
if(this->length!=s.length) return true;
else
{
for(index=0;index<length && index<s.length;)
{
if(this->contains[index]==s.contains[index]) 
{
index++;
}
else 
{
return true;
}
}
if(contains[index]==s.contains[index])
{ 
return false;
}
else return true;
}
}


int String::operator<(String &s)
{
int index;
index=0;
while(index<s.length && index<length)
{
if(contains[index]<s.contains[index]) return 1;
else 
{
if(contains[index]==s.contains[index]) index++;
else return 0;
}
}
if(index==length) return 1;
if(index==s.length) return 0;
}

int String::operator>(String &s)
{
int index;
index=0;
while(index<s.length && index<length)
{
if(contains[index]>s.contains[index]) return 1;
else 
{
if(contains[index]==s.contains[index]) index++;
else return 0;
}
}
if(index==length) return 0;
if(index==s.length) return 1;
}

char String::front()
{
return contains[0];
}

char String::back()
{
return contains[length-1];
}

char String::at(int e)
{
return contains[e];
}

int String::empty()
{
if(length==0) return 1;
else return 0;
}

int String::Length()
{
return length;
}

int String::size()
{
return length;
}

void String::pop_back()
{
int index;
length--;
index=length;
contains[index]='\0';
}

void String::swap(const String& e)
{
int index;
length=e.length;
contains=new char[length];
for(index=0;index<length;index++) contains[index]=e.contains[index];
contains[index]='\0';
}

String& String::erase()
{
length=0;
contains=NULL;
return *this;
}

String& String::erase(int e)
{
for(;e+1<length;e++) contains[e]=contains[e+1];
contains[e]='\0';
length--;
return *this;
}

String& String::erase(int e,int count)
{
for(int f=e+count;e+1<length;e++,f++) contains[e]=contains[f];
contains[e]='\0';
length-=count;
return *this;
}

void String::push_back(char e)
{
int index;
char *temp=new char[length];
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
length++;
contains=new char[length];
for(index=0;index<length-1;index++) contains[index]=temp[index];
contains[index]=e;
index++;
contains[index]='\0';
}

void String::assign(int count,char e)
{
int index;
contains=new char[count+1];
length=count;
for(index=0;index<length;index++)
{
contains[index]=e;
}
contains[index]='\0';
}

void String::assign(const char *e)
{
int index;
const char* x;
x=e;
for(length=0;*e!='\0';e++,length++);
contains=new char[length];
for(index=0;index<length;index++) contains[index]=x[index];
contains[index]='\0';
}

void String::assign(const char *e,int count)
{
int index;
const char* x;
x=e;
for(length=0;*x!='\0';x++,length++);
contains=new char[count+1];
length=count;
for(index=0;index<length;index++)
{
contains[index]=e[index];
}
contains[index]='\0';
}

void String::assign(const char *e,int from,int count)
{
int index,index2;
const char* x;
x=e;
for(length=0;*x!='\0';x++,length++);
contains=new char[count+1];
length=count;
for(index2=from,index=0;index<count;index++,index2++)
{
contains[index]=e[index2];
}
contains[index]='\0';
}

void String::assign(const String &e)
{
int index;
length=e.length;
contains=new char[length];
for(index=0;index<length;index++) contains[index]=e.contains[index];
contains[index]='\0';
}

void String::assign(const String &e,int count)
{
int index;
length=count;
contains=new char[length];
for(index=0;index<length;index++)
{
contains[index]=e.contains[index];
}
contains[index]='\0';
}


void String::assign(const String &e,int from, int count)
{
int index,index2;
length=count;
contains=new char[length];
for(index=0,index2=from;index<length && index2<e.length;index++,index2++)
{
contains[index]=e.contains[index2];
}
contains[index]='\0';
}


void String::append(int count,char e) 
{
int index,num;
char *temp;
temp=new char[length];
for(index=0;index<length;index++)
{
temp[index]=contains[index];
}
temp[index]='\0';
contains=new char[length+count];
for(index=0;index<length;index++)
{
contains[index]=temp[index];
}
length+=count;
for(num=0;index<length && num<count;num++,index++)
{
contains[index]=e;
}
contains[index]='\0';
delete [] temp;
}

void String::append(const char *e)
{
int l,index;
const char *m;
m=e;
for(l=0;*e!='\0';e++,l++);
char *temp=new char[length];
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
length+=l;
contains=new char[length];
for(index=0;*temp!='\0' && index<length-l;index++) contains[index]=temp[index];
for(l=0;*m!='\0' && index<length;l++,index++) contains[index]=m[l];
contains[index]='\0';
delete [] temp;
}


void String::append(const char *e,int count)
{
char *temp;
int index,index2;
temp=new char[length];
for(index=0;index<length;index++)
{
temp[index]=contains[index];
}
temp[index]='\0';
contains=new char[length+count];
for(index=0;index<length;index++)
{
contains[index]=temp[index];
}
length+=count;
for(index2=0;index<length && index2<count;index++,index2++)
{
contains[index]=e[index2];
}
contains[index]='\0';
delete [] temp;
}

void String::append(const String &e)
{
int index,index2;
char *temp=new char[length];
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
contains=new char[e.length];
for(index=0;index<length;index++) contains[index]=temp[index];
length+=e.length;
for(index2=0;index<length && index2<e.length;index++,index2++) contains[index]=e.contains[index2];
contains[index]='\0';
delete [] temp;
}

void String::append(const String &e,int count)
{
int index,index2;
char *temp;
temp=new char[length];
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
contains=new char[length + count];
for(index=0;index<length;index++)
{
contains[index]=temp[index];
}
length+=count;
for(index2=0;index2<count && index<length;index++,index2++)
{
contains[index]=e.contains[index2];
}
contains[index]='\0';
}


void String::append(const String &e,int from,int count)
{
int index,index2,num;
char *temp;
temp=new char[length];
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
contains=new char[length + count];
for(index=0;index<length;index++)
{
contains[index]=temp[index];
}
length+=count;
for(index2=from,num=0;num<count && index<length;index++,index2++,num++)
{
contains[index]=e.contains[index2];
}
contains[index]='\0';
}

void String::insert(int at,int count,char e) 
{
char *temp;
int index,index2,num;
temp=new char[length];
for(index=0;index<length;index++)
{
temp[index]=contains[index];
}
temp[index]='\0';
contains=new char[count+length];
for(index=0;index<at;index++)
{
contains[index]=temp[index];
}
index2=index;
length+=count;
for(num=0;index<length && num<count;index++,num++)
{
contains[index]=e;
}
for(;index<length;index++,index2++)
{
contains[index]=temp[index2];
}
contains[index]='\0';
delete [] temp;
}


void String::insert(int at,const char *e) 
{
const char *m;
char *temp;
int index,arglength,index2,index3;
m=e;
for(arglength=0;*m!='\0';m++,arglength++);
temp=new char[length];
for(index=0;index<length;index++)
{
temp[index]=contains[index];
}
temp[index]='\0';
contains=new char[arglength+length];
for(index=0;index<at;index++)
{
contains[index]=temp[index];
}
index2=index;
length+=arglength;
for(index3=0;index<length && index3<arglength;index++,index3++)
{
contains[index]=e[index3];
}
for(;index<length;index++,index2++)
{
contains[index]=temp[index2];
}
contains[index]='\0';
delete [] temp;
}


void String::insert(int at,const char *e,int count) 
{
const char *m;
char *temp;
int index,arglength,index2,index3;
m=e;
for(arglength=0;*m!='\0';m++,arglength++);
temp=new char[length];
for(index=0;index<length;index++)
{
temp[index]=contains[index];
}
temp[index]='\0';
contains=new char[count+length];
for(index=0;index<at;index++)
{
contains[index]=temp[index];
}
index2=index;
length+=arglength;
for(index3=0;index<length && index3<count;index++,index3++)
{
contains[index]=e[index3];
}
for(;index<length;index++,index2++)
{
contains[index]=temp[index2];
}
contains[index]='\0';
delete [] temp;
}

void String::insert(int at,String &e)
{
int index,index2,index3;
char *temp;
temp=new char[length];
for(index=0;index<length;index++)
{
temp[index]=contains[index];
}
temp[index]='\0';
contains=new char[e.length+length];
for(index=0;index<at;index++)
{
contains[index]=temp[index];
}
index2=index;
length+=e.length;
for(index3=0;index<length && index3<e.length;index++,index3++)
{
contains[index]=e.contains[index3];
}
for(;index<length;index++,index2++)
{
contains[index]=temp[index2];
}
contains[index]='\0';
delete [] temp;
}

void String::insert(int at,const String &e,int count)
{
int index,index2,index3;
char *temp;
temp=new char[length];
for(index=0;index<length;index++)
{
temp[index]=contains[index];
}
temp[index]='\0';
contains=new char[count+length];
for(index=0;index<at;index++)
{
contains[index]=temp[index];
}
index2=index;
length+=count;
for(index3=0;index<length && index3<count;index++,index3++)
{
contains[index]=e.contains[index3];
}
for(;index<length;index++,index2++)
{
contains[index]=temp[index2];
}
contains[index]='\0';
delete [] temp;
}

int String::compare(const char *e)
{
int result,index,arglength;
const char *m;
for(m=e,arglength=0;*m!='\0';m++,arglength++);
index=0;
while(index<arglength && index<this->length && contains[index]==e[index])
{
index++;
}
result=(contains[index]-e[index]);
if(result==0) return 0;
if(result<0) return -1;
if(result>0) return 1;
}

int String::compare(String &s)
{
int result,index;
index=0;
while(index<s.length && index<this->length && contains[index]==s.contains[index])
{
index++;
}
result=(contains[index]-s.contains[index]);
if(result==0) return 0;
if(result<0) return -1;
if(result>0) return 1;
}

unsigned int String::find(const char *e,int pos=0)
{
unsigned int index,index2,i,arglength;
const char *m;
index2=0;
for(m=e,arglength=0;*m!='\0';m++,arglength++);
for(index=pos;index<length;index++)
{
if(contains[index]==e[0])
{
i=index;
index2=0;
for(;index2<arglength && i<length;i++,index2++)
{
if(contains[i]!=e[index2]) break;
}
if(arglength==index2) return index;
}
}
return nposition;
}

unsigned int String::find(const String &e,int pos=0)
{
unsigned int index,index2,i;
index2=0;
for(index=pos;index<length;index++)
{
if(contains[index]==e.contains[0])
{
i=index;
index2=0;
for(;index2<e.length && i<length;i++,index2++)
{
if(contains[i]!=e.contains[index2]) break;
}
if(e.length==index2) return index;
}
}
return nposition;
}

unsigned int String::find_first_of(const char *e,int pos=0)
{
const char *m;
unsigned int index,index2,l;
for(m=e,l=0;*m!='\0';m++,l++);
for(index=pos;index<length;index++)
{
for(index2=0;index2<l;index2++)
{
if(contains[index]==e[index2]) return index;
}
}
return nposition;
}

unsigned int String::find_first_of(const String &e,int pos=0)
{
unsigned int index,index2,l;
for(index=pos;index<length;index++)
{
for(index2=0;index2<l;index2++)
{
if(contains[index]==e.contains[index2]) return index;
}
}
return nposition;
}

unsigned int String::find_last_of(const char *e,int pos=0)
{
const char *m;
unsigned int index,index2,l;
for(m=e,l=0;*m!='\0';m++,l++);
for(index=length-1;index>=pos;index--)
{
for(index2=0;index2<l;index2++)
{
if(contains[index]==e[index2]) return index;
}
}
return nposition;
}

unsigned int String::find_last_of(const String &e,int pos=0)
{
unsigned int index,index2,l;
for(index=length-1;index>=pos;index--)
{
for(index2=0;index2<e.length;index2++)
{
if(contains[index]==e.contains[index2]) return index;
}
}
return nposition;
}


unsigned int String::find_first_not_of(const char *e,int pos=0)
{
const char *m;
unsigned int index,index2,l,i;
for(m=e,l=0;*m;m++,l++);
for(index=pos;index<length;index++)
{
for(i=index,index2=0;index2<l;)
{
if(contains[index]!=e[index2]) index2++;
else break;
}
if(index2==l) return i;
}
return nposition;
}


unsigned int String::find_first_not_of(const String &e,int pos=0)
{
unsigned int index,index2,l,i;
for(index=pos;index<length;index++)
{
for(i=index,index2=0;index2<e.length;)
{
if(contains[index]!=e.contains[index2]) index2++;
else break;
}
if(index2==e.length) return i;
}
return nposition;
}

unsigned int String::find_last_not_of(const char *e,int pos=0)
{
const char *m;
unsigned int index,index2,l,i;
for(m=e,l=0;*m!='\0';m++,l++);
for(index=length-1;index>=pos;index--)
{
for(i=index,index2=0;index2<l;)
{
if(contains[index]!=e[index2]) index2++;
else break;
}
if(index2==l) return i;
}
return nposition;
}

unsigned int String::find_last_not_of(const String &e,int pos=0)
{
unsigned int index,index2,l,i;
for(index=length-1;index>=pos;index--)
{
for(i=index,index2=0;index2<e.length;)
{
if(contains[index]!=e.contains[index2]) index2++;
else break;
}
if(index2==e.length) return i;
}
return nposition;
}


void String::replace(int at,int repcount,int count,const char e)
{
int index,index2,ilength;
char *temp;
temp=new char[length];
ilength=length;
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
contains=new char[length-repcount+count];
length=length-repcount+count;
for(index=0;index<at;index++) contains[index]=temp[index];
index2=index;
for(int num=0;num<repcount;num++,index2++);
for(int num=0;num<count && index<length;index++,num++) contains[index]=e;
for(;index<length && index2<ilength;index++,index2++) contains[index]=temp[index2];
contains[index]='\0';
delete [] temp;
}

void String::replace(int at,int repcount,const char *e) 
{
int index,index2,ilength,arglength,index3;
char *temp;
const char *temp2;
temp2=e;
temp=new char[length];
ilength=length;
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
for(arglength=0;*temp2!='\0';temp2++,arglength++);
contains=new char[length-repcount+arglength];
length=length-repcount+arglength;
for(index=0;index<at;index++) contains[index]=temp[index];
index2=index;
for(index3=0;index3<arglength && index<length;index++,index3++) contains[index]=e[index3];
for(index3=0;index3<repcount;index3++,index2++);
for(;index<length && index2<ilength;index++,index2++) contains[index]=temp[index2];
contains[index]='\0';
delete [] temp;
delete [] temp2;
}


void String::replace(int at,int repcount,int count,const char *e)
{
int index,index2,ilength,arglength,index3;
char *temp;
temp=new char[length];
ilength=length;
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
contains=new char[length-repcount+count];
length=length-repcount+count;
for(index=0;index<at;index++) contains[index]=temp[index];
index2=index;
for(index3=0;index3<repcount;index3++,index2++);
for(index3=0;index3<count && index<length;index++,index3++) contains[index]=e[index3];
for(;index<length && index2<ilength;index++,index2++) contains[index]=temp[index2];
contains[index]='\0';
delete [] temp;
}

void String::replace(int at,int repcount,const String &e)
{
int index,index2,index3,ilength;
char *temp;
temp=new char[length];
ilength=length;
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
length=length-repcount+e.length;
for(index=0;index<at;index++) contains[index]=temp[index];
index3=index;
for(index2=0;index2<e.length && index<length;index2++,index++) contains[index]=e.contains[index2];
for(index2=0;index2<repcount;index2++,index3++);
for(;index<length && index3<ilength;index++,index3++) contains[index]=temp[index3];
contains[index]='\0';
delete [] temp;
}


void String::replace(int at,int repcount,int count,const String &e)
{
int index,index2,index3,ilength;
char *temp;
temp=new char[length];
ilength=length;
for(index=0;index<length;index++) temp[index]=contains[index];
temp[index]='\0';
length=length-repcount+count;
for(index=0;index<at;index++) contains[index]=temp[index];
index3=index;
for(index2=0;index2<count && index<length;index2++,index++) contains[index]=e.contains[index2];
for(index2=0;index2<repcount;index2++,index3++);
for(;index<length && index3<ilength;index++,index3++) contains[index]=temp[index3];
contains[index]='\0';
delete [] temp;
}

String String::substr(int from,int to)
{
String newString;
int index,index2;
newString.contains=new char[to+1];
newString.length=to+1;
for(index=0,index2=from;index<to && index2<length;index++,index2++) newString.contains[index]=this->contains[index2];
newString.contains[index]='\0';
return newString;
}

String& String::upperCase()
{
int index;
for(index=0;index<length;index++)
{
if(contains[index]>=97 && contains[index]<=122) contains[index]-=32;
}
return *this;
}

String& String::upperCase(int from,int to)
{
int index;
for(index=from;index<=to;index++)
{
if(contains[index]>=97 && contains[index]<=122) contains[index]-=32;
}
return *this;
}

String& String::lowerCase()
{
int index;
for(index=0;index<length;index++)
{
if(contains[index]>=65 && contains[index]<=90) contains[index]+=32;
}
return *this;
}

String& String::lowerCase(int from,int to)
{
int index;
for(index=from;index<=to;index++)
{
if(contains[index]>=65 && contains[index]<=90) contains[index]+=32;
}
return *this;
}

String& String::toggleCase()
{
int index;
for(index=0;index<length;index++)
{
if(contains[index]>=65 && contains[index]<=90) contains[index]+=32;
else
{
if(contains[index]>=97 && contains[index]<=122) contains[index]-=32;
}
}
return *this;
}

String& String::toggleCase(int from,int to)
{
int index;
for(index=from;index<=to;index++)
{
if(contains[index]>=65 && contains[index]<=90) contains[index]+=32;
else
{
if(contains[index]>=97 && contains[index]<=122) contains[index]-=32;
}
}
return *this;
}

bool String::endsWith(const char *e)
{
int index,index2,arglength;
const char *m;
m=e;
for(m=e,arglength=0;*m!='\0';m++,arglength++);
index=length-1;
index2=arglength-1;
if(contains[index]==e[index2])
{
for(;index>=0 && index2>=0 && contains[index]==e[index2];index--,index2--);
if(index2==-1 && contains[index+1]==' ') return true;
else return false;
}
else return false;
}

String& String::reverse()
{
int index1,index2;
char g;
for(index1=0,index2=length-1;index1<index2;index1++,index2--)
{
g=contains[index1];
contains[index1]=contains[index2];
contains[index2]=g;
}
return *this;
}

#endif
