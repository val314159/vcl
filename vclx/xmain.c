#include "ll.h"
#include "cons.h"
#include "symbol.h"
#include "characters.h"
#include "simple_base_string.h"

int main(){
  setbuf(stdout,0);
  printf("x1\n");
  long x = 100;
  printf("x12\n");
  long bv1 = STR("hello");
  printf("x13\n");
  //long bv2 = make_byte_vector(10);
  printf("x14\n");
  printf("qq %lx\n", bv1);
  printf("qq    %lx\n", PTR(bv1));
  printf("qq    %lx\n", PTR(bv1));
  printf("[%s]\n", (char*)PTR(bv1));
  printf("[%ld]\n", FILL_POINTER(bv1));
  //printf("[%ld]\n", bv_size(bv2));
  //printf("x %lx\n", x=CODE_CHAR(-1));
  //printf("  %lx\n", CHAR_CODE(x));
  printf("x %lx\n", x=CODE_CHAR(0));
  printf("  %lx\n", CHAR_CODE(x));
  printf("x %lx\n", x=CODE_CHAR(1));
  printf("  %lx\n", CHAR_CODE(x));
  printf("x %lx\n", x=CODE_CHAR(255));
  printf("  %lx\n", CHAR_CODE(x));
  //printf("x %lx\n", x=CODE_CHAR(256));
  //printf("  %lx\n", CHAR_CODE(x));
}
