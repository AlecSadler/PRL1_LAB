// il seguente codice calcola le soluzioni di un'equazione di secondo grado

#include <stdio.h>
#include <math.h>

struct Resol {
    float x1;
    float x2;};

typedef struct Resol Resol;


float delta (float a,float b,float c){
    float d;
    d= pow(b,2)-4*a*c;
    return d;
}

Resol resolution (float a,float b,float c,float delta){
    Resol sol;
    if (b==0){
        sol.x1=-sqrt(-c/a);
        sol.x2=sqrt(-c/a);}
    else if (c==0){
        sol.x1=0;
        sol.x2=-b/a;}
    else{
        if (delta>0){
            sol.x1= -b+sqrt(delta)/2*a;
            sol.x2= -b-sqrt(delta)/2*a;}
        else if (delta==0){
            sol.x1= -b/(2*a);
            sol.x2= -b/(2*a);}}
    return sol;
}

void main(){
    float a,b,c;
    Resol solutions;
    printf ("Inserisci i coefficienti a,b,c dell'equazione ax^2+bx+c\n");
    scanf("%f%f%f",&a,&b,&c);
    printf("L'equazione inserita è %.2fx^2 + %.2f x + %.2f\n",a,b,c);
    if (delta(a,b,c) < 0)
        printf ("L'equazione non ammette soluzioni reali in quanto discriminante < 0.\n");
    else{
        solutions.x1=resolution(a,b,c,delta(a,b,c)).x1;
        solutions.x2=resolution(a,b,c,delta(a,b,c)).x2;
        printf("Soluzione X1 = %f\n",solutions.x1);
        printf("Soluzione X2 = %f\n",solutions.x2);}
}

