
main()

/* inizio blocco principale */ 
{

  /* dichiarazione di tre interi */
  int a,b,c;

  /* assegnazione ai primi due di un 
     valore, al terzo della somma */
  a=2;
  b =3;
  c = a+b;

  /* stampiamo i loro valori */
  printf("addendi, a:%2d, b:%5d;",a,b);
  printf(" loro somma:%2d \n",c);

}
/* fine blocco principale e programma */

/* ------------------------------
Compilazione ed esecuzione
raus:--> gcc -o c1 c1.c
raus:--> ./c1
addendi, a: 2, b: 3; loro somma: 5
raus:--> 
*/




/*
raus:--> gcc -S c1.c (genera l'assembly)
raus:--> ls
c1  c1.c  c1.s
raus:--> more c1.s
        .file   "more c1.s
        .file   "c1.c"
        .section        .rodata
.LC0:
        .string "addendi, a:%2d, b:%2d;"
.LC1:
        .string " loro somma:%2d \n"
        .text
.globl main
        .type   main, @function
main:
        pushl   %ebp
        movl    %esp, %ebp
        subl    $24, %esp
        andl    $-16, %esp
        movl    $0, %eax
        subl    %eax, %esp
        movl    $2, -4(%ebp)
        movl    $3, -8(%ebp)
        movl    -8(%ebp), %eax
        addl    -4(%ebp), %eax
        movl    %eax, -12(%ebp)
        subl    $4, %esp
        pushl   -8(%ebp)
        pushl   -4(%ebp)
        pushl   $.LC0
        call    printf
        addl    $16, %esp
        subl    $8, %esp
        pushl   -12(%ebp)
        pushl   $.LC1
        call    printf
        addl    $16, %esp
        leave
        ret
        .size   main, .-main
        .ident "GCC: (GNU) 3.3 (SuSE Linux)"
raus:-->

Note sull'assembly generato: 
%eax, %ebp, %esp: sono i nomi di registri
push, mov: istruzioni di trasferimento dati
call, ret: istruzioni di controllo
sub, add, and: istruzioni aritmetico-logiche

Note:
- int a : dichiarazione della variabile a
- = : operatore di assegnazione 
*/
