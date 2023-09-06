#include<stdio.h>
#include<string.h>
int main()
{
  //unsigned char flag[]="moectf{HAHA_C_1s_easy!}";
  unsigned char enc_data[]="mng`pc}OIAKTOR?|Ots`m4k",flag[23];
  int i;
  for( i=0;i<strlen(enc_data);i++)
  {
    flag[i]=enc_data[i]^i;
  }
  puts(flag);
  return 0;
}