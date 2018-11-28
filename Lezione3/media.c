//
//  main.c
//  media
//
//  Created by Salvo Firera on 03/10/18.
//  Copyright © 2018 Salvo Firera. All rights reserved.
//

#include <stdio.h>

int main()
{
    float a;
    float b;
    float c;
    float media;
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    media= (a+b+c)/3;
    printf("%.3f",media);
    return 0;
}

