 Data una lista di coppie, restituisce la lista di booleani nella quale il valoretrue compare in posizione i
 se e solo se nella stessa posizione della lista originaria compare una coppia di elementi uguali 
 
 let subst l =
  let f (x,y) (l1)= if x=y then (true::l1)
                    else (false::l1)
  in foldr f ([]) l ;;
