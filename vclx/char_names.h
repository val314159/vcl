static inline
long _name_to_character(long x){
  if(!strcmp((char*)x,"Nul"))      return'\0';
  if(!strcmp((char*)x,"Null"))     return'\0';
  if(!strcmp((char*)x,"Soh"))      return   1;
  if(!strcmp((char*)x,"Stx"))      return   2;
  if(!strcmp((char*)x,"Etx"))      return   3;
  if(!strcmp((char*)x,"Eot"))      return   4;
  if(!strcmp((char*)x,"Enq"))      return   5;
  if(!strcmp((char*)x,"Ack"))      return   6;
  if(!strcmp((char*)x,"Bel"))      return'\a';
  if(!strcmp((char*)x,"Bell"))     return'\a';
  if(!strcmp((char*)x,"Bs"))       return'\b';
  if(!strcmp((char*)x,"Backspace"))return'\b';
  if(!strcmp((char*)x,"Tab"))      return'\t';
  if(!strcmp((char*)x,"Newline"))  return'\n';
  if(!strcmp((char*)x,"Vt"))       return'\v';
  if(!strcmp((char*)x,"Page"))     return'\f';
  if(!strcmp((char*)x,"Return"))   return'\r';
  if(!strcmp((char*)x,"So"))       return 14;
  if(!strcmp((char*)x,"Si"))       return 15;
  if(!strcmp((char*)x,"Dle"))      return 16;
  if(!strcmp((char*)x,"Dc1"))      return 17;
  if(!strcmp((char*)x,"Dc2"))      return 18;
  if(!strcmp((char*)x,"Dc3"))      return 19;
  if(!strcmp((char*)x,"Dc4"))      return 20;
  if(!strcmp((char*)x,"Nak"))      return 21;
  if(!strcmp((char*)x,"Syn"))      return 22;
  if(!strcmp((char*)x,"Etb"))      return 23;
  if(!strcmp((char*)x,"Can"))      return 24;
  if(!strcmp((char*)x,"Em"))       return 25;
  if(!strcmp((char*)x,"Sub"))      return 26;
  if(!strcmp((char*)x,"Esc"))      return'\e';
  if(!strcmp((char*)x,"Escape"))   return'\e';
  if(!strcmp((char*)x,"Space"))    return ' ';
  if(!strcmp((char*)x,"Rubout"))   return 127;
  return nil;}

static inline
long _character_to_name(long x){
  switch(x){
  case   0: return (long)"Nul";
  case   1: return (long)"Soh";
  case   2: return (long)"Stx";
  case   3: return (long)"Etx";
  case   4: return (long)"Eot";
  case   5: return (long)"Enq";
  case   6: return (long)"Ack";
  case   7: return (long)"Bell";
  case   8: return (long)"Backspace";
  case   9: return (long)"Tab";
  case  10: return (long)"Newline";
  case  11: return (long)"Vt";
  case  12: return (long)"Page";
  case  13: return (long)"Return";
  case  14: return (long)"So";
  case  15: return (long)"Si";
  case  16: return (long)"Dle";
  case  17: return (long)"Dc1";
  case  18: return (long)"Dc2";
  case  19: return (long)"Dc3";
  case  20: return (long)"Dc4";
  case  21: return (long)"Nak";
  case  22: return (long)"Syn";
  case  23: return (long)"Etb";
  case  24: return (long)"Can";
  case  25: return (long)"Em";
  case  26: return (long)"Sub";
  case  27: return (long)"Escape";
  case  28: return (long)"Fs";
  case  29: return (long)"Gs";
  case  30: return (long)"Rs";
  case  31: return (long)"Us";
  case  32: return (long)"Space";
  case 127: return (long)"Rubout";
  default : return nil;}}
