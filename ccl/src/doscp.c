/*
 * doscp.c
 *
 * copy files from DOS
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
  char c;
  int i;
  
  if (args<=1)
    printf("Copy files from DOS\n");
  for (i=1;i<args;i++)
    if ((f1=fopen(arg[i],"rb"))!=NULL)
     {
      printf("%s\n",fname=name(arg[i]));
      if ((f2=fopen(fname,"wb"))!=NULL)
       {
        while(fread(&c,1,1,f1)==1)
          if (c!='\n')
           {
            if (c=='\r')
              c='\n';
            fwrite(&c,1,1,f2);
           }
        fclose(f2);
       }
      fclose(f1);
     }
  return 0;
 }

