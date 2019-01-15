/* La funzione restituisce il massimo suffisso di una lista di interi strettamente minore di un intero n
dato come input, senza usare risorsione esplicita */

#let suffix n l=
  let f x (l1,sum)= if sum+x < n then (x::l1,sum+x)
                    else (l1,sum+x)
in let (a,b)= foldr f ([],0) l in a;;                    
