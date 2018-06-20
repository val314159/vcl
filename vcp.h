#define u unsigned
typedef long long llng;
int  isspace(int);
int  isalnum(int);
int  isalpha(int);
int  isdigit(int);
int  open(const char*,int,int);
int  close(int);
long read(int,void*,u long);
long write(int,const void*,u long);
llng lseek(int,llng,int);
int  printf(const char*,...);
int  usleep(u int);
char* index(const char*, int);
void exit(int);
int atoi(const char*);
/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>
#include<ctype.h>
*/
typedef int var ;
typedef int vars;
