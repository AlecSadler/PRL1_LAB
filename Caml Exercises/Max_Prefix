/* La funzione restituisce il massimo prefisso di una lista strettamente minore di un numero n dato in input */

let start n l=
  let rec aux n l (l1,sum)= match l with
    []-> ([],0)
    |[x]-> if x<n then (l1 @ [x],sum+x)
          else (l1,sum)
    |x::xs -> if sum<n then aux n xs (l1 @ [x],sum+x)
              else (l1,sum)
  in let (a,b)= aux n l ([],hd l) in a;;            
           
