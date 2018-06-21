pr(x){
  if(abs(x) < 1024) return printf("%d", x), x;
  if(consp(x)>0){
  printf("("), pr(car(x));
  for(x = cdr(x); consp(x)>0; x = cdr(x))
    printf( " " ), pr(car(x));
  if (x&&x!=MT) printf(" . "), pr(x);
  return printf(")"), x;}
  return printf("%s", (char*)x), x;}
prn(x){return pr(x), printf("\n"), x;}
