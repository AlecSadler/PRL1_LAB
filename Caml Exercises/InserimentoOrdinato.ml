Sapendo che l è una lista ordinata,restituire la lista con il valore n al posto giusto

let insord l n=
  let f x (l1,b)= if x>n then (x::l1,b)
                  else if not b then (x::n::l1,true)
                       else (x::l1,b)
  in let (a,b)= foldr f ([],false) l in a;;
  
  
