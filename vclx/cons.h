// CONSES DICTIONARY

typedef struct { long h,t; } ConsT;

long CONS(long h, long t){ return (long)create(ConsT,h,t)|(CONS_T<<48);}
long CONSP(long x){ return ((x>>48)==CONS_T) ? T : nil;}

long*GETF_CAR(long x){
  ifn(CONSP(x)) DIE("NO!""\n");
  return &((ConsT*)(x & 0xffffffffffL))->h;}
long*GETF_CDR(long x){
  ifn(CONSP(x)) DIE("NO!""\n");
  return &((ConsT*)(x & 0xffffffffffL))->t;}

long CAR(long x){ifn(CONSP(x)) return nil; return *GETF_CAR(x); }
long CDR(long x){ifn(CONSP(x)) return nil; return *GETF_CDR(x); }

long SETF_CAR(long x, long v){ return *GETF_CAR(x) = v;}
long SETF_CDR(long x, long v){ return *GETF_CDR(x) = v;}
