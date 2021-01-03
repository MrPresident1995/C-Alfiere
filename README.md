Si fornisce in input una possibile configurazione di una scacchiera quadrata NxN con riportati dei valori numerici per ogni cella.
Tale configurazione è caratterizzata da alcune celle a cui è associato valore nullo: tali posizioni sono attualmente libere, in attesa che un singolo alfiere venga posizionato.
Si scriva un programma che scelga in quale delle posizioni libere piazzare l'alfiere, così che la somma dei valori lungo le sue possibili direzioni di movimento sia massima.
Si ricorda che un alfiere muove solamente in diagonale rispetto alla posizione di partenza, sia in avanti sia in indietro.
Si consideri a titolo di esempio la seguente configurazione per una scacchiera 4x4:

    4 1 2 0 9
    3 2 0 4 3
    2 5 1 4 6
    1 6 1 0 7
      a b c d
  
La posizione migliore per l'alfiere è la cella b3, a cui si associa una somma complessiva pari a 17.
