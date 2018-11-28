//
//  main.c
//  max
//
//  Created by Salvo Firera on 03/10/18.
//  Copyright © 2018 Salvo Firera. All rights reserved.
//

#include <stdio.h>

int main()
{
    int time;
    int h=0;
    int m=0;
    int s=0;
    scanf("%d",&time);
    if(time<=59)
        s=s+time;
    else{
        while(time>59)
         { time=time-60;
          m++;
          if(m>59)
           {m=0;
           h++;
           }
        s=time;
         }
       }
    printf("%d h %d min %d s",h,m,s);
    return 0;
}

