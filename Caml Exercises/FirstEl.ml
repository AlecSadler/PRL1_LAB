Data una lista di liste, restituisce il primo elemento di tutte le liste non vuote,senza usare ricorsione esplicita

#let noempty l= l<> [];;

#let firstel l= map hd (filter noempty l);;



