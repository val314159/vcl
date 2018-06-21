#include"vcp.h"
#include"prstools.h"
#include"cons.h"
#include"prs.h"

var MT=(var)"()";
char null = 0;
var _, c;
char token[1024] = {0};
vars xlist[1024] = {0}, T=0, X=0;

#include "pr.h"
main(){
  alarm(2);
  int isatty(int);
  if(isatty(0)) return LOG("tty error\n"),exit(1),0;
  int r = Rprogram();
  printf("r = %d\n", r);
  (!NEXT)?prn(r):printf("parse error\n"), exit(0);
}
