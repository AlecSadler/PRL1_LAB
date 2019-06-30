La funzione restituisce la massima sottolista finale che NON contiene 1

#let subnot1 l=
  let rec aux l (l1)= match l with
    []-> l1
    | x::xs-> if x=1 then aux xs ([])
              else aux xs (l1@[x])
  in aux l ([]);;


La funzione restituisce la massima sottolista iniziale che NON contiene 1
SENZA usare ricorsione esplicita

#let init l=
  let f x (l1)= if x=1 then ([])
                else x::l1
  in foldr f ([]) l;;
