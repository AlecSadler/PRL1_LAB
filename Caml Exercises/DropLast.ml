Data una lista e un numero n, cancella gli ultimi n elementi

#let drop l n=
  let rec aux l n (count,l1)= match l with
    []-> (count,l1)
    |x::[]-> if n=0 then (count,l1)
             else (count+1,[])
    |x::xs-> if n=0 then (count,l1)
             else if count<=n then aux xs n (count+1,l1@[x])
                  else (count+1,l1)
  in let (a,b)=aux l n (0,[]) in b;;                
