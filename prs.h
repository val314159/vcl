Rws();
Rnum2();
Rid2();
Rid();
Rstr2();
Ratum();
Rxpr();
Rxprlst();
Rpxprlst();
Rprogram();
#define ws      if n(_=Rws())      break;
#define num2    if n(_=Rnum2())    break;
#define id2     if n(_=Rid2())     break;
#define id      if n(_=Rid())      break;
#define str2    if n(_=Rstr2())    break;
#define atum    if n(_=Ratum())    break;
#define xpr     if n(_=Rxpr())     break;
#define xprlst  if n(_=Rxprlst())  break;
#define pxprlst if n(_=Rpxprlst()) break;
#define program if n(_=Rprogram()) break;
Rws(){
  RULE { X(isspace(NEXT)) ws }
  ELSE { $$(token_reset())   }
  REND}
Rnum2(){
  RULE { IN("012345679") num2 }
  ELSE { }
  REND}
Rid2(){
  RULE { X(isalnum(NEXT)) id2 }
  ELSE { }
  REND}
Rid(){
  RULE { X(isalpha(NEXT)) id2 $$(token_reset()) }
  REND}
Rstr2(){
  RULE { IS('"')  }
  ELSE { IS('\\') ANY str2 }
  ELSE {          ANY str2 }
  REND}
Ratum(){
  RULE { IS('\"')                 str2  $$(token_reset()) }
  ELSE { IS('-')  IN("012345679") num2  $$(token_reset()) }
  ELSE {          IN("012345679") num2  $$(token_reset()) }
  ELSE { IS('\'') IS('\\') ANY IS('\'') $$(token_reset()) }
  ELSE { IS('\'')          ANY IS('\'') $$(token_reset()) }
  ELSE {  id __1 }
  REND}
Rxprlst(){
  RULE { xpr __1 xprlst __2 $$(cons(_1,_2)) }
  ELSE { }
  REND}
Rpxprlst(){
  RULE { IS('(') xprlst __1 ws IS(')') }
  REND}
Rxpr(){
  RULE { ws id      __1 pxprlst $$(cons(_1,_)) }
  ELSE { ws atum    __1 }
  ELSE { ws pxprlst __1 }
  REND}
Rprogram(){
  RULE { ws      xprlst __2 ws eof $$(_2) }
  REND}
