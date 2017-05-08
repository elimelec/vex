#pragma lmb
typedef int lmb_int;

lmb_int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
main()
{
    foo();
}

foo()
{
   int i;
   for (i = 0; i < 10; ++i) {
       printf("hello %d %d\n",i,a[i]);
       sim_ta_mark(i);
   }
}
