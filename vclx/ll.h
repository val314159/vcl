#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#define DIE(fmt,...) fprintf(stderr,fmt"\n",##__VA_ARGS__),exit(1)

#define nil (0L)
#define T   (1L)

#define ift(x) if((x)!=nil)
#define ifn(x) if((x)==nil)

#define create(typ,...) memcpy(malloc(sizeof(typ)),           \
                                 &(typ){__VA_ARGS__}, sizeof(typ))

#define PTR(x) (x&0x0000FFFFFFFFFFFFL)

#define SEQ_T  0x10L
#define VEC_T  0x20L
#define ARR_T  0x40L
#define CONS_T 0x11L
#define SYM_T  0x02L
#define BCHR_T 0x03L
#define BIT_T  0x04L
#define SBS_T  0x73L
#define GVEC_T 0x71L
#define BVEC_T 0x74L
#define NEG_T  0xFFL
#define POS_T  0x00L

