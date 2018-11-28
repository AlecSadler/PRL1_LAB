#include <stdio.h>

int main()
{
    int l;
    int h;
    int i;
    int j;
    scanf("%d%d",&h,&l);
    if (h==1 && l==1)
        printf("*");
    else
      {for(i=0;i<l;i++)
         {printf("*");}
       printf("\n");
      for(i=0;i<h-2;i++)
         {printf("*");
          for(j=0;j<=l-3;j++)
            {printf(" ");}
          printf("*");
          printf("\n");}
      for(i=0;i<l;i++)
          printf("*");
      }
    return 0;
    }
