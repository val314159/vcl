#include "char_names.h"

// CHARACTERS DICTIONARY

const long CHAR_CODE_LIMIT = 0xFF;

long CHARACTERP(long c){  return ((c>>48)==BCHR_T) ? T : nil;}
long CODE_CHAR(long c){return(c<0||c>CHAR_CODE_LIMIT)?nil:c|(BCHR_T<<48);}
long CHAR_CODE(long c){ifn(CHARACTERP(c)) DIE("NO!"); return PTR(c);}
long CHAR_INT( long c){ return CHAR_CODE(c); }

long CHAR_EQUAL(       long c, long d){ return (c==d) ? T : nil;}
long CHAR_NOT_EQUAL(   long c, long d){ return (c!=d) ? T : nil;}
long CHAR_LESSP(       long c, long d){ return (c <d) ? T : nil;}
long CHAR_GREATERP(    long c, long d){ return (c >d) ? T : nil;}
long CHAR_NOT_GREATERP(long c, long d){ return (c<=d) ? T : nil;}
long CHAR_NOT_LESSP(   long c, long d){ return (c>=d) ? T : nil;}

long CHARACTER(long c){printf("not done\n");exit(1);}

long ALPHA_CHAR_P(  long c){ return (isalpha(PTR(c))) ? T : nil;}
long ALPHANUMERICP( long c){ return (isalnum(PTR(c))) ? T : nil;}
long DIGIT_CHAR_P(  long c){ return (isdigit(PTR(c))) ? T : nil;}
long GRAPHIC_CHAR_P(long c){ return (isgraph(PTR(c))) ? T : nil;}

long STANDARD_CHARACTER_P(long c){return(c<127&&(c>=32||c==10))?T:nil;}

long DIGIT_CHAR  (long weight, long radix){
  if(radix>36||radix<2) { printf("RADIX ERROR\n"), exit(1); }
  if(weight >= radix) { return nil; }
  return CODE_CHAR((weight<10) ? '0'+weight : 'A'+weight-10);}
long CHAR_UPCASE  (long c){ return toupper(PTR(c)); }
long CHAR_DOWNCASE(long c){ return tolower(PTR(c)); }

long UPPER_CASE_CHAR_P(long c){ return (isupper(PTR(c))) ? T : nil;}
long LOWER_CASE_CHAR_P(long c){ return (islower(PTR(c))) ? T : nil;}
long  BOTH_CASE_CHAR_P(long c){ return (isalpha(PTR(c))) ? T : nil;}

long NAME_CHAR(long x){  return _name_to_character(x);}
long CHAR_NAME(long x){  return _character_to_name(PTR(x));}
