//
//  main.c
//  temperaure
//
//  Created by Salvo Firera on 03/10/18.
//  Copyright © 2018 Salvo Firera. All rights reserved.
//

#include <stdio.h>

int main()
{
    float t;
    float conv;
    scanf("%f",&t);
    conv = (t*1.8)+32;
    printf("%.2f",conv);
    return 0;
}

