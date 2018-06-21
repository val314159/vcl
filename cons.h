typedef struct { int h,t; } cell;
const int MemSz = 102400;
cell Mem[MemSz];
MemLen = 0;

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
