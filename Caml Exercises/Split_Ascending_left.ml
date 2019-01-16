/* La seguente funzione, data una lista in input, la divide in due sottoliste, di cui la prima è la più lunga possibile in
ordine crescente, il resto va nella seconda */

#let splitasc l =
  let rec aux l (l1,l2,check) = match l with
    []-> (l1,l2,check)
    |x::[]-> if not check then (l1 @ [x],l2,check)
             else (l1,l2 @ [x],check)
    |x::y::ys-> if x<y && not check then aux (y::ys) (l1 @ [x],l2,check)
                else if x>y && not check then aux (y::ys) (l1 @ [x],l2,true)
                     else aux (y::ys) (l1,l2 @ [x],check)
  in let (a,b,c) = aux l ([],[],false) in (a,b);;             
