//
//  main.c
//  lezione4
//
//  Created by Salvo Firera on 09/10/18.
//  Copyright © 2018 Salvo Firera. All rights reserved.
//

#include <stdio.h>

int main()
{
    int seq[10];
    int n;
    int i;
    for(i=0;i<10;i++)
      {scanf("%d",&n);
       seq[i]=n;
      }
    for(i=0;i<9;i++)
     {if (seq[i]>=0 && (int)seq[i]%2==0)
          printf("%d\n",seq[i]);
      else
          if(seq[i]<0 && seq[i+1]>=0)
          printf("%d\n",seq[i]);
     }
    if (seq[9]>=0 && seq[9]%2==0)
        printf("%d",seq[i]);
    return 0;
}

