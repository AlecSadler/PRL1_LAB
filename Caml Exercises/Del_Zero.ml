/* La seguente funzione cancella da una lista, gli elementi che seguono l'ultima occorrenza del valore 0,senza usare
ricorsione esplicita,se la lista non contiene 0, viene cancellata totalmente */

#let delzero l=
    let f x (l1,found)= if x=0 then 
                            if not found then (x::l1,true)
                            else (x::l1,found)
                        else if not found then (l1,found)
                             else (x::l1,found)
    in let (a,b) = foldr f ([],false) l in a ;;                         

