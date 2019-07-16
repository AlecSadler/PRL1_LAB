Data una lista di interi, restituire una lista di coppie in cui il primo numero è il valore della lista e il secondo rappresenta 
le sue occorrenze nella lista, ogni elemento va inserito una volta sola

let contaocc l n=
  let rec aux l n c= match l with
    []->c
    |x::[]-> if x==n then c+1
             else c
    |x::xs-> if x==n then aux xs n c+1
             else aux xs n c
  in aux l n 0;;

let rec member l (a,b)= match l with
  []-> false
  |(x,y)::[]-> if x=a then true
               else false
  |(x,y)::zs-> if x=a then true
               else member zs (a,b);;
               
let multiset l=
  let f x (l1)= if not member l1 (x,contaocc l x) then ( (x,contaocc l x)::l1 )
                else l1
  in foldr f ([]) l;;
  
  
