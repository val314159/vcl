#define __1 {_1=_;}
#define __2 {_2=_;}
#define __3 {_3=_;}
#define SI static inline
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
extern char null, token[];
extern vars _, MT, c, xlist[], T, X;
SI token_reset(){
  char*  strdup(const char*);
  var t = (var)strdup(token);
  token[T=0] = 0;
  return t;}
SI _readchar(){ return n( read(0,&c,1))?0 : c; }
SI eof(){ return _readchar()>0 ? (lseek(0,-1,1),0) : 1; }
SI readchar(){
  int ret = read(0,&c,1);
  if(c>0) (token[T++] = c), (token[T] = 0);
  return n(ret) ? 0 : c;}
#define  X(xpr) if n(xpr) break;
#define NX(xpr) if n(xpr) break;
#define   NEXT readchar()
#define    ANY X(NEXT)
#define  IN(x) X(ins(x))
#define  IS(c) X((c)==NEXT)
SI show(char*s, var x){return printf("[%s is %d]\n", s, x), x;}
#define eof        X(eof())
#define $$(x) {_1=(x);}
