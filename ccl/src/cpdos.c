/*
 * cpdos.c
 *
 * copy files to DOS
 */
#include <stdio.h>
#include <string.h>

char *
 name(char *s)
  {
   int i;
   
   for (i=strlen(s);i>0;i--)
     if ((s[i-1]=='/')||(s[i-1]=='\\')||(s[i-1]==':'))
       return &s[i];
   return s;
  }
  
int
 main(int args,char **arg)
 {
  FILE *f1,*f2;
  char *fname;
  char c,r;
  int i;
  
  r='\r';
  if (args<=1)
    printf("Copy files to DOS\n");
  for (i=1;i<args;i++)
    if ((f1=fopen(arg[i],"rb"))!=NULL)
     {
      printf("%s\n",fname=name(arg[i]));
      if ((f2=fopen(fname,"wb"))!=NULL)
       {
        while(fread(&c,1,1,f1)==1)
         {
          if (c=='\n')
            fwrite(&r,1,1,f2);
          fwrite(&c,1,1,f2);
         }
        fclose(f2);
       }
      fclose(f1);
     }
  return 0;
 }
 
