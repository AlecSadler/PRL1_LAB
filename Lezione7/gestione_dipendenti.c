#include <stdio.h>

struct dipendente{
    int id;
    float stip;
    int m_ass;
    int y_ass;};

void increase (struct dipendente a[], float rate,int dim){
    int i;
    float inc;
    for (i=0;i<dim;i++){
        if (a[i].y_ass<2000 || (a[i].y_ass==2000 && a[i].m_ass<5)){
            inc=a[i].stip*(rate/100);
            a[i].stip=a[i].stip+inc;}}
}

int main(){
    struct dipendente azienda[2];
    int i;
    float inc_rate;
    for (i=0;i<2;i++){
        scanf("%d%d%d%f",&azienda[i].id,&azienda[i].m_ass,&azienda[i].y_ass,&azienda[i].stip);}
    scanf("%f",&inc_rate);
    increase(azienda,inc_rate,2);
    for (i=0;i<2;i++)
        if (azienda[i].stip>1200)
            printf("%d %.0f\n",azienda[i].id,azienda[i].stip);
    return 0;
}
            

    



    
    
    
        
        
        
    








        




