La seguente funzione restituisce la lunghezza del massimo suffisso, la cui somma degli elementi è strettamente minore di un
intero n,senza usare ricorsione esplicita

#let lenght l=
  let f x len= len+1
in foldr f 0 l ;;

#let sumsuffix n l=
  let f x (l1,len,sum)= if sum+x<n then (x::l1,lenght l1,sum+x)
                        else (l1,lenght l1,sum+x)
in let (a,b,c)= foldr f ([],0,0) l in b;;                        

