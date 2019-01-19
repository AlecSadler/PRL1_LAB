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

 #let precfold l=
    let f x (l1,y)= if x<y then (y::l1,x)
                    else (l1,x)
    in let (a,b)= foldr f ([],0) l in a;;                
