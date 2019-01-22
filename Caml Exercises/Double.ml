Definire una funzione doppio che riceve una lista come argomento e restituisce true se
ogni elemento della lista (eccetto il primo) è pari al doppio dell’elemento che lo precede. Restituisce
false altrimenti.
doppio
[2;4;8;16;32]
=
true

Mi servo della funzione di appoggio last che mi ritorna l'ultimo elemento di una lista

#let last l=
  let rec aux l el= match l with 
    []-> el
    |x::[]-> x
    |x::xs-> aux xs x
  in aux l (hd l) ;;  

#let double l =
  let f x (ok,y)= if ok then
                     if x=y/2 then (ok,x)
                     else (false,x)
                  else (ok,x)
  in let (a,b)= foldr f (true,(last l)*2) l in a;;                 
                  
