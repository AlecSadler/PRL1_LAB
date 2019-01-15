La seguente funzione data una lista separa in due liste gli elementi positivi da quelli negativi

CON RICORSIONE ESPLICITA

#let split list=
	let rec aux list (l1,l2)= match list with
	    [] -> ([l1],[l2])
	   |x::xs -> if x>=0 then aux xs (x::l1,l2)
		     else aux xs (l1,x::l2)
  in aux list ([],[]);;
  
CON FOLDR
 
#let split list=
   let f x (l1,l2)= if x>=0 then (x::l1,l2)
                    else (l1,x::l2)
 in foldr f ([],[]) list;;                   
