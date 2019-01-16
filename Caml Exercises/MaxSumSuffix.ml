La seguente funzione restituisce il massimo prefisso, la cui somma degli elementi è strettamente minore di un intero n

#let sumsuffix l n=
  let rec aux l n (l1,sum)= match l with
    []-> (l1,sum)
    |x::[]-> if x<n then (l1@[x],sum+x)
                   else (l1,sum+x)
    |x::xs-> if sum+x<n then aux xs n (l1@[x],sum+x) 
             else (l1,sum)
  in let (a,b)= aux l n ([],0) in a;;           
                   
