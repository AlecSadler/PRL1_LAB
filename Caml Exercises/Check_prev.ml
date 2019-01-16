La seguente funzione, data una lista di interi e due valori n e m, restituisce true se tutte le occorrenze di n precedono
quelle di m, false altrimenti. Non usare ricorsione esplicita.

#let checknm l n m=
  let f x (ok,b)= if b then if x<>m then (ok,b)
                            else (false,b)
                  else if x=n then (ok,true)
                       else (ok,b)
in let (a,b)= foldr f (true,false) l in a;;  

CON RICORSIONE ESPLICITA

let checknm l n m=
  let rec aux l n m (ok,b)= match l with
    []-> (ok,b)
    |x::[]-> (ok,b)
    |x::xs-> if b then if x<>n then aux xs n m (ok,b)
                      else (false,b)
            else if x=m then aux xs n m (ok,true)
                 else aux xs n m (ok,b)
  in let (a,b)= aux l n m (true,false) in a;;               
                      
                               
