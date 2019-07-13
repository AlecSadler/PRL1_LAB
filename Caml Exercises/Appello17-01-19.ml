La seguente funzione data una lista, ritorna una lista contenente tutti gli elementi preceduti da un elemento minore

CON RICORSIONE ESPLICITA

#let prec l =
	let rec aux l l1= match l with
	  []-> l1
	  |x::[]-> l1
	  |x::y::ys-> if x<y then aux (y::ys) (y::l1)
              else aux (y::ys) l1
         in aux l [];;  
  
SENZA RICORSIONE ESPLICITA

 
#let precmin l=
  let f x (l1,l2)= match l2 with
        []-> (l1,x::l2)
        |y::ys-> if x < y then (y::l1,x::l2)
                      else (l1,x::l2)
  in let (a,b)= foldr f ([],[]) l in a;;
