
main()

{

  printf("Hi mom! \n");

  /*
  printf('Hi mom! \n');
  PRINTF("Hi mom! \n");
  */
}



  /*
raus:--> gcc -c c0.c    (oggetto: c0.o)
raus:--> gcc -o c0 c0.o (link: c0)
raus:--> ./c0           (esecuzione) 
Ciao mamma!
raus:-->  
[ora inserisco prima solo la seconda, 
 poi solo la terza]
raus:--> gcc -o c0 c0.c
c0.c:11:10: warning: character constant too 
long for its type
c0.c: In function `main':
c0.c:11: warning: passing arg 1 of `printf' 
makes pointer from integer without a cast
raus:--> ./c0
Ciao mamma!
Segmentation fault
raus:--> gcc -o c0 c0.c
In function 'main':
: undefined reference to `PRINTF'
collect2: ld returned 1 exit status
raus:-->  nm  c0.o
00000000 T main
         U printf
  */

         
         
  /*
          Note sul primo programma:
- main(...): inizio programma
- \n: manda a capo (nuova linea)
- C: e' sensibile al maiuscolo <-> minuscolo
- { ....}: delimita un blocco di istruzioni
- commento con /* ...
- printf: funzione per lo standard output
- ; : terminatore di istruzione
  */


