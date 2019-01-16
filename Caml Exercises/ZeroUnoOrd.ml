La funzione ritorna TRUE se contiene solo 0 e 1 ed è ordinata in modo non decrescente, FALSE altrimenti, senza usaere
ricorsione esplicita

#let zerounoord l=
  let f x (ok,found)= if x<>0 && x<>1 then (false,found)
                      else if not found then if x=1 then (ok,found)
                                             else (ok,true)
                           else if x=1 then (false,found)
                                else (ok,found)
in let (a,b)= foldr f (true,false) l in a;;                                
                           
                                        
