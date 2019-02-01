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
 	let f x (s,l,b)=
		if not b then (x,l,true)
		else if x<s then (x,s::l,b)
			else (x,l,b)
	in match l with
	[]->[]
        |x::xs-> let (a,b,c) = foldr f (x,[],false) l in b;;
    
