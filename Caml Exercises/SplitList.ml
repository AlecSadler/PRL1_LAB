divide una lista alernando i valori nelle due liste risultanti

#let split l =
  let rec aux l (l1,l2)= match l with
    []-> (l1,l2)
    |x::[]-> (l1@[x],l2)
    |x::y::ys-> aux ys (x::l1,y::l2)
  in aux l ([],[]);;  
