Data una lista l restituire una lista che comprende tutte le sottoliste NON DECRESCENTI che è possibile estrarre da l

let rec len l = match l with
  []->0
  |x::[]-> 1
  |x::xs-> 1+len xs;;

let splitcresc l=
  let f x (l1,l2,b,c)= if not b then (l1,x::l2,true,c+1)
                       else if x <= hd l2 then
                              if c==(len l-1) then ((x::l2)::l1,l2,b,c)
                              else (l1,x::l2,b,c+1)
                            else (l2::l1,x::[],b,c+1)
  in let (a,b,c,d)= foldr f ([],[],false,0) l in a;;


