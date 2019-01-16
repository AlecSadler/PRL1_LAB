La funzione ritorna TRUE se in una lista sono presenti solo 0 e 1 e il numero di 0 è uguale al numero di 1, FALSE altrimenti

#let only01 l=
  let rec aux l ok = match l with
    []-> ok
    |x::[]-> if x<>0 && x<>1 then false
             else ok
    |x::xs-> if x<>0 && x<>1 then false
             else aux xs ok
  in aux l true;;         
           
#let countel l n=
 let rec aux l n count= match l with
  []-> 0
  |x::[]-> if x=n then 1+count
           else count
  |x::xs-> if x=n then aux xs n count+1
           else aux xs n count
 in aux l n 0;;
 
#let zerouno l = if only01 l && countel l 0 = countel l 1 then true
                else false;;
