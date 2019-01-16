La seguente funzione, data una lista di interi e due valori n e m, restituisce true se tutte le occorrenze di n precedono
quelle di m, false altrimenti. Non usare ricorsione esplicita.

#let checknm l n m=
  let f x (ok,b)= if b then if x<>m then (ok,b)
                            else (false,b)
                  else if x=n then (ok,true)
                       else (ok,b)
in let (a,b)= foldr f (true,false) l in a;;                       
                               
