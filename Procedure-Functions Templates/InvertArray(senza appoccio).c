
void revArray (int a[],int dim){
  for (i=0;i<dim/2;i++){
      tmp=a[i];
      a[i]=a[dim-i-1];
      a[dim-i-1]=tmp;}
}      
