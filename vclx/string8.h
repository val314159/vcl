
// 8-bit simple strings

typedef char* SimpleBaseStringT;

long SIMPLE_BASE_STRING_P(long arr){return ((arr>>48)==0x44) ? T : nil;}
long SIMPLE_STRING_P(long arr){return ((arr>>48)==0x44) ? T : nil;}

long _mk_sbs(long size){
  const int sz = size+2*sizeof(long);
  long*arr = malloc(sz);
  *(arr++) = 0;
  *(arr++) = size;
  return(long)arr;}
/*
long make_byte_vector(long size){
  long bv = _mk_sbs(size);
  return(long)bzero((void*)bv,size)|(0x44L<<48);}
long bv_cstr(char*s){
  long bv = _mk_sbs(strlen(s)+1);
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
*/
