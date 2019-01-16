La procedura,data una lista di interi,restituisce una lista conntenente le somme degli elementi tra due occorrenze di 0,non
viene usata ricorsione esplicita

#let sumlist l=
  let f x (l1,sum,c)= if x<>0 then if c=0 then (l1,sum,c)
                                 else (l1,sum+x,c)
                      else if c=0 then (l1,sum,c+1)
                         else (sum::l1,0,c+1)
in let (a,b,c)=foldr f ([],0,0) l in a;;                         
