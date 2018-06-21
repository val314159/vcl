long MT=(long)"n/a";
char null = 0;
#define tell() lseek(0,0,1)
#define LOG(fmt,...) printf("LOG: "fmt"\n",##__VA_ARGS__)
#define ins(s) *(index((s),NEXT)?:&null)

#include"vcp.h"
#define do do{ (_1=MT),(token[T=t]=0),(X=x),lseek(0,p,0),0;
#define returnx } return
#define return(n) returnx(n)
#define RET return 0;
#define CAPTURE vars p=tell(),_1=MT,_2,_3,_4,_5,_6,_7,_8,_9,t=T,x=X

#define RULE CAPTURE; do{
#define ELSE return(_1);}while(0);do{ 
#define REND return(_1);}while(0);RET

#define BIF(x) if((x)<1) break;
#define n(x) ((x)<1)

extern var c, _;
extern char token[];
extern vars xlist[], T, X;

token_reset(){
  char*  strdup(const char*);
  long t = (long)strdup(token);
  token[T=0] = 0;
  return t;}

_readchar(){ return n(read(0,&c,1)) ? 0 : c; }
readchar(){
  int oldpos = tell();
  int ret = read(0,&c,1);
  //printf("readchar(oldpos = %d ret = %d\n", oldpos, ret);
  //read %d %c => n %d\n", ret, (char)c, n(ret));
  if(c>0) (token[T++] = c), (token[T] = 0);
  return n(ret) ? 0 : c;
}
#define  X(xpr) if n(xpr) break;
#define NX(xpr) if n(xpr) break;

#define   NEXT readchar()
#define    ANY X(NEXT)
#define  IN(x) X(ins(x))
#define  IS(c) X((c)==NEXT)

long show(char*s, long x){
  printf("[%s is %ld]\n", s, x);
  return x;}
