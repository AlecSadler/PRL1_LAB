La funzione restituisce gli ULTIMI n numeri positivi di una lista, se n è maggiore del numero dei positivi, li restituisce tutti.

let fine l n=
  let rec aux l n l1= match l with
    []->l1
    |x::[]->if n>0 then
            if x>=0 then x::l1
            else l1
          else l1
    |x::xs-> if n>0 then
              if x>=0 then aux xs (n-1) (x::l1)
              else aux xs n l1
           else aux xs n l1
  in aux (rev l) n [];;

SENZA RICORSIONE ESPLICITA

let finefold  l n =
  let f x (c,l1)= if c>0 then
                    if x>=0 then (c-1,x::l1)
                    else (c,l1)
                  else (c,l1)
  in let (a,b)= foldr f (n,[]) l in b;;
