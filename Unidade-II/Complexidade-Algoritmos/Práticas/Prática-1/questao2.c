//Considere dois algoritmos que resolvem o mesmo problema:
//Algoritmo A:
 void algoritmo_a(int n) {
 for (int i = 0; i < n; i++) { //c1n
 for (int j = 0; j < n; j++) { //n^2c2
 printf("%d, %d\n", i, j);
 }
 }
 }

//Algoritmo B:
 void algoritmo_b(int n) {
 for (int i = 0; i < n; i++) { //c1n
 printf("%d\n", i);
 }
 for (int j = 0; j < n; j++) { //c2n
 printf("%d\n", j);
 }
 }
/*Pergunta: Determine a complexidade de tempo de cada algoritmo e identifique qual e o mais eficiente em termos de complexidade. Justifique sua resposta*/

/*Resposta:
Algoritmo A:
C1n + n^2c2
O(n^)

Algoritmo B:
c1n + c2n
n (c1 + c2)
an
0(n)

Algoritmo B é mais eficiente.
*/