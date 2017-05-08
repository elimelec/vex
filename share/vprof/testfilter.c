int a[100] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
main()
{
    foo();
}

CMPLT(int i)
{
    printf("hello-1 %d %d\n",i,a[i]);
}

CMPLTU(int i)
{
    printf("hello-2 %d\n", i);
}

foo()
{
   int i;
   int j;
   for (i = 0; i < 100; ++i) {
       if (i < 10) {
	 j = i*i;
           CMPLT(i);
       }
       else {
           CMPLTU(i);
       }
   }
}
