// SYMBOLS DICTIONARY

typedef struct { long name, value, function, package, plist; } SymbolT;

long MAKE_SYMBOL(long name){
  return (long)create(SymbolT,name,0,0,0,0)|(SYM_T<<48);}
long SYMBOLP(long x){ return ((x>>48)==SYM_T) ? T : nil;}

long*GETF_SYMBOL_NAME(long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n");
  return &((SymbolT*)(x & 0xffffffffffL))->name;}
long*GETF_SYMBOL_VALUE(long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n");
  return &((SymbolT*)(x & 0xffffffffffL))->value;}
long*GETF_SYMBOL_FUNCTION(long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n");
  return &((SymbolT*)(x & 0xffffffffffL))->function;}
long*GETF_SYMBOL_PACKAGE(long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n");
  return &((SymbolT*)(x & 0xffffffffffL))->package;}
long*GETF_SYMBOL_PLIST(long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n");
  return &((SymbolT*)(x & 0xffffffffffL))->plist;}

long SYMBOL_NAME(    long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n"); 
  return *GETF_SYMBOL_NAME(x); }
long SYMBOL_VALUE(   long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n"); 
  return *GETF_SYMBOL_VALUE(x); }
long SYMBOL_FUNCTION(long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n"); 
  return *GETF_SYMBOL_FUNCTION(x); }
long SYMBOL_PACKAGE( long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n"); 
  return *GETF_SYMBOL_PACKAGE(x); }
long SYMBOL_PLIST(   long x){
  ifn(SYMBOLP(x)) DIE("NO!""\n"); 
  return *GETF_SYMBOL_PLIST(x); }

long SETF_SYMBOL_NAME(    long x, long v){ return *GETF_SYMBOL_NAME(x)    =v;}
long SETF_SYMBOL_VALUE(   long x, long v){ return *GETF_SYMBOL_VALUE(x)   =v;}
long SETF_SYMBOL_FUNCTION(long x, long v){ return *GETF_SYMBOL_FUNCTION(x)=v;}
long SETF_SYMBOL_PACKAGE( long x, long v){ return *GETF_SYMBOL_PACKAGE(x) =v;}
long SETF_SYMBOL_PLIST(   long x, long v){ return *GETF_SYMBOL_PLIST(x)   =v;}
