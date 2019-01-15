/* La funzione restituisce la lunghezza del massimo suffisso di una lista di interi strettamente minore di un intero n
dato come input, senza usare risorsione esplicita */

// mi servo di una funzione ausiliaria che calcola la lnghezza di una lista

#let lenght l=
  let f x (len)= len+1
 in foldr f 0 l;; 

#let suffixlen n l=
  let f x (l1,sum,len)= if sum+x < n then (x::l1,sum+x,lenght l1)
                    else (l1,sum+x,lenght l1)
in let (a,b,c)= foldr f ([],0,0) l in c;; 
