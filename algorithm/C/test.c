__int64 __fastcall func48887(char *a1)
{
  int i; // [rsp+1Ch] [rbp-4h]

  for ( i = 0; i <= 39; ++i )
  {
    if ( ((key[i] + 19) ^ a1[i]) != ans[i] )
    {
      puts("something wrong, check!");
      exit(0);
    }
  }
  puts("Congratulations! You have got the right flag!");
  return func48888(a1);
}