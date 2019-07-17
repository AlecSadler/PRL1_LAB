La funzione restituisce TRUE se ogni elemento della lista è minore della somma dei suoi successivi


SENZA RICORSIONE ESPLICITA:

let less l=
  let f x (b,sum,bstart) = if not bstart then (b,sum+x,true)
                           else if x<sum then (b,sum+x,bstart)
                                else (false,sum,bstart)
  in let (a,b,c)= foldr f (true,0,false) l in a;;



CON RICORSIONE ESPLICITA:

Utilizzo una funzione ausiliaria che somma gli elementi di una lista
let rec sumlist l= match l with
  []->0
  |x::[]-> x
  |x::xs-> x + sumlist xs;;

let lessrec l=
  let rec aux l (b)= match l with
    []-> (b)
    |x::[]-> (b)
    |x::xs-> if x < sumlist xs then aux xs (b)
             else false
  in aux l (true);;
