// 8-bit simple strings
//
typedef char* SimpleBaseStringT;
long SIMPLE_STRING_P(long arr){return ((arr>>48)==SBS_T) ? T : nil;}
long SIMPLE_VECTOR_P(long arr){return ((arr>>48)==GVEC_T)? T : nil;}
long VECTOR_P(long arr){return ((arr>>48)&VEC_T) ? T : nil;}

long FILL_POINTER(long arr){
  ifn(VECTOR_P(arr)) DIE("NO1a");
  return((long*)PTR(arr))[-2];}
long SETF_FILL_POINTER(long arr, long n){
  ifn(VECTOR_P(arr)) DIE("NO1b");
  if(n>1024*1024) DIE("NO3");
  return((long*)PTR(arr))[-2]=n;}

long _mk_sbs(long size){
  const int sz = size+2*sizeof(long);
  long*arr = malloc(sz);
  *(arr++) = 0;
  *(arr++) = size;
  return(long)arr;}
long _mk_gvec(long size){
  return _mk_sbs(size*sizeof(long));}

long MAKE_SIMPLE_VECTOR(long size, long fill){
  long bv = _mk_sbs(size*sizeof(long));
  return(long)bzero((void*)bv,size)|(GVEC_T<<48);}
long MAKE_SIMPLE_BASE_STRING(long size, long fill){
  long bv = (long)bzero((void*)_mk_sbs(size),size)|(SBS_T<<48);
  SETF_FILL_POINTER(bv, fill);
  return bv;}
long MAKE_STRING(long size){
  return MAKE_SIMPLE_BASE_STRING(size,size);}

long CHAR(     long arr, long n        ){
  ifn(SIMPLE_STRING_P(arr)) DIE("NO1r");
  return (long)(((char*)PTR(arr))[n]  );}
long SETF_CHAR(long arr, long n, long v){
  ifn(SIMPLE_STRING_P(arr)) DIE("NO1t");
  ifn(CHARACTERP(v)) DIE("NO2");
  return (long)(((char*)PTR(arr))[n]=v);}
long SCHAR(     long arr, long n        ){
  ifn(SIMPLE_STRING_P(arr)) DIE("NO1r");
  if(n>FILL_POINTER(arr)) DIE("NO0");
  return (long)(((char*)PTR(arr))[n]  );}
long SETF_SCHAR(long arr, long n, long v){
  ifn(SIMPLE_STRING_P(arr)) DIE("NO1t");
  if(n>FILL_POINTER(arr)) DIE("NO0");
  ifn(CHARACTERP(v)) DIE("NO2");
  return (long)(((char*)PTR(arr))[n]=v);}

long GVEC_ELT(     long arr, long n        ){
  ifn(SIMPLE_VECTOR_P(arr)) DIE("NO1x");
  if(n>FILL_POINTER(arr)) DIE("NO0");
  return (long)(((long*)PTR(arr))[n]  );}
long SETF_GVEC_ELT(long arr, long n, long v){
  ifn(SIMPLE_VECTOR_P(arr)) DIE("NO1y");
  if(n>FILL_POINTER(arr)) DIE("NO0");
  return (long)(((long*)PTR(arr))[n]=v);}
long GVEC_AREF(     long arr, long n        ){
  ifn(SIMPLE_VECTOR_P(arr)) DIE("NO1z");
  return (long)(((long*)PTR(arr))[n]  );}
long SETF_GVEC_AREF(long arr, long n, long v){
  ifn(SIMPLE_VECTOR_P(arr)) DIE("NO1w");
  return (long)(((long*)PTR(arr))[n]=v);}

long STR(char*s){
  long len = strlen(s)+1;
  long bv = ((long)strcpy((char*)_mk_sbs(len),s))|(SBS_T<<48);
  SETF_FILL_POINTER(bv, len);
  return bv;}
