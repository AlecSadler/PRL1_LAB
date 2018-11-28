#include <stdio.h>

struct gatto{
    int id;
    int age;
    float wgt;
    int food;        /* 0=crocchette 1=scatolette 2=tonno */
};

int main(){
    struct gatto gattile[4];
    int i;
    float sum_wgt=0;
    float av_wgt;
    for (i=0;i<4;i++){
        scanf("%d",&gattile[i].id);
        scanf("%d",&gattile[i].age);
        scanf("%f",&gattile[i].wgt);
        scanf("%d",&gattile[i].food);
        sum_wgt=sum_wgt+gattile[i].wgt;}
    av_wgt=sum_wgt/4;
    for (i=0;i<4;i++){
        if (gattile[i].wgt>av_wgt && gattile[i].age<4)
            switch (gattile[i].food){
                case 0: printf("%d crocchette",gattile[i].id);
                    break;
                case 1: printf("%d scatolette",gattile[i].id);
                    break;
                case 2: printf("%d tonno in scatola",gattile[i].id);
                    break;
            }}
    return 0;
    }

        

    
    
    
        
        
        
    








        




