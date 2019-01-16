La segente funzione, data una lista, la divide in due, di cui la seconda contiene la lista più lunga possibile in ordine
crescente partendo da destra, i restanti elementi andranno nell'altra lista.

#let splitascr l=
  let f x (l1,l2,check)= if not check then
                            if l2=[] then (l1,x::l2,check)
                            else if x< hd l2 then (l1,x::l2,check)
                                 else (x::l1,l2,true)
                         else (x::l1,l2,check)   
in let (a,b,c)= foldr f ([],[],false) l in (a,b);;                                
