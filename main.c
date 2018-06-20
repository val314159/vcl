#include"vcp.h"
#include"prs.h"

void alarm(int);

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
  RULE; { xpr xprlst }
  ELSE; { }
  REND;}
Rxpr(){
  RULE; { ws         atum   {_1=_;} }
  ELSE; { ws IS('(') xprlst {_1=_;} ws IS(')') }
  REND;}

var _, c;
char token[1024] = {0};
vars xlist[1024] = {0}, T=0, X=0;

main(){
  alarm(1);
  printf("====================\n");
  int isatty(int);
  if(isatty(0)) return LOG("tty error\n"),exit(1),0;
  //LOG(",,,,,,,,,p %lld", tell());
  //LOG("ws  = %s", (char*)Rws());
  LOG(",,,,,,,,,p %lld", tell());
  LOG("num = %s", (char*)Rxpr());
  LOG(",,,,,,,,,p %lld", tell());
}
