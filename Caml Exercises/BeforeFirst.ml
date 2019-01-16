La funzione, data una lista e un intero, restituisce la lista degli elementi che precedono la prima occorrenza di n, se n
non è in lista ritorna [], usare ricorsione esplicita

Mi servo della funzione d'appoggio member che verifica se il numero fa parte della lista

#let rec member l n= match l with
  []-> false
  |x::xs-> if x=n then true
           else member xs n;;

#let beforefirst l n= 
  let rec aux l n (l1,check)= match l with
    []-> (l1,check)
    |x::xs-> if not member l n then (l1,check)
             else if not check && x<>n then aux xs n (l1@[x],check)
                  else if not check && x=n then (l1,true)
                       else (l1,check)
  in let (a,b)= aux l n ([],false) in a;;                     
