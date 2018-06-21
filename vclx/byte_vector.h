
// byte vectors

typedef char* ByteVectorT;

long byte_vector_p(long arr){return ((arr>>48)==0x44) ? T : nil;}

long _make_byte_vector(long size){
  const int sz = size+sizeof(long);
  long*arr = malloc(sz);
  *(arr++) = size;
  return(long)arr;}
long make_byte_vector(long size){
  long bv = _make_byte_vector(size);
  return(long)bzero((void*)bv,size)|(0x44L<<48);}
long bv_cstr(char*s){
  long bv = _make_byte_vector(strlen(s)+1);
  return((long)strcpy((char*)bv, s))|(0x44L<<48);}
long bv_size(long arr){
  ifn(byte_vector_p(arr)) DIE("NO1");
  return((long*)PTR(arr))[-1];}
long bv_nth(     long arr, long n        ){
  ifn(byte_vector_p(arr)) DIE("NO1");
  return (long)(((char*)PTR(arr))[n]  );}
long setf_bv_nth(long arr, long n, long v){
  ifn(byte_vector_p(arr)) DIE("NO1");
  ifn(CHARACTERP(v)) DIE("NO2");
  return (long)(((char*)PTR(arr))[n]=v);}
