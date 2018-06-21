#include"vcp.h"
#include"prs.h"

typedef struct { int h,t; } cell;
const int MemSz = 102400;
cell Mem[MemSz];
MemLen = 0;

void*memcpy(void*,const void*,unsigned long);
alarm(int);

cell*_newcell(){return Mem + MemLen++;}
#define cons(h,t)  _cons((int)(h),(int)(t))
#define  consp(x) _consp((int)(x))
#define    car(x)   _car((int)(x))
#define    cdr(x)   _cdr((int)(x))
_cons(h,t){_ = (int)memcpy(_newcell(),&(cell){h,t},sizeof(cell)); return _;}
_consp(c){
  if(!c)return 0;
  if(c<(int)Mem      ) return -2;
  if(c>(int)Mem+MemSz) return -1;
  return 1;}
_car(c){
  switch(consp(c)){
  case -2:
  case -1: printf("CAR ERR\n"),exit(1);
  default: _ = ((cell*)c)->h; return _;
  case 0:  _ = 0;}
  return _;}
_cdr(c){
  switch(consp(c)){
  case -2:
  case -1: printf("CDR ERR\n"),exit(1);
  default: _ = ((cell*)c)->t; return _;
  case 0:  _ = 0;}
  return _;}

Rws();
Rnum2();
Rid2();
Rstr2();
Ratum();
Rxpr();
Rxprlst();

#define ws      if n(_=Rws())     break;
#define num2    if n(_=Rnum2())   break;
#define id2     if n(_=Rid2())    break;
#define str2    if n(_=Rstr2())   break;
#define atum    if n(_=Ratum())   break;
#define xpr     if n(_=Rxpr())    break;
#define xprlst  if n(_=Rxprlst()) break;

Rws(){
  RULE; { X(isspace(NEXT)) ws }
  ELSE; { {token_reset();} }
  REND;}
Rnum2(){
  RULE; { IN("012345679") num2 }
  ELSE; { }
  REND;}
Rid2(){
  RULE; { X(isalnum(NEXT)) id2 }
  ELSE; { }
  REND;}
Rstr2(){
  RULE; { IS('"')  }
  ELSE; { IS('\\') ANY str2 }
  ELSE; {          ANY str2 }
  REND;}
Ratum(){
  RULE; { IS('\"') str2                  {_1 = token_reset();} }
  ELSE; { IS('-')  IN("012345679") num2  {_1 = token_reset();} }
  ELSE; {          IN("012345679") num2  {_1 = token_reset();} }
  ELSE; { IS('\'') IS('\\') ANY IS('\'') {_1 = token_reset();} }
  ELSE; { IS('\'')          ANY IS('\'') {_1 = token_reset();} }
  ELSE; { X(isalpha(NEXT)) id2           {_1 = token_reset();} }
  REND;}
Rxprlst(){
  RULE; { xpr xprlst {_2=_;} {_1=cons(_1,_2);} }
  ELSE; { }
  REND;}
Rxpr(){
  RULE; { ws         atum   {_1=_;} }
  ELSE; { ws IS('(') xprlst {_1=_;} ws IS(')') }
  REND;}

var _, c;
char token[1024] = {0};
vars xlist[1024] = {0}, T=0, X=0;

pr(x){
  if(!x) printf("[NULL]");
  else if(abs(x) < 1024){
    printf("{%d}", x);
  }else{
    printf("(");
    pr(car(x));
    x = cdr(x);
    if(x){
      printf(" . ");
      pr(x);
    }
    printf(")");
  }
  return x;}

main(){
  alarm(1);
  printf("====================\n");
  int isatty(int);
  if(isatty(0)) return LOG("tty error\n"),exit(1),0;
  //LOG(",,,,,,,,,p %lld", tell());
  //LOG("ws  = %s", (char*)Rws());
  LOG(",,,,,,,,,p %lld", tell());
  int r = Rxpr();
  LOG("num = %d", r);
  LOG(",,,,,,,,,p %lld", tell());

  pr(0);
  pr(1);
  pr(-1);
  pr(cons(11,22));
  pr(cons(11,0));
}
