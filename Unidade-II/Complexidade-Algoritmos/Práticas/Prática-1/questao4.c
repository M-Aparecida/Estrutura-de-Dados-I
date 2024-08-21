//Considere o seguinte algoritmo de busca:
 int busca_linear(int arr[], int n, int x) {
 for (int i = 0; i < n; i++) { //c1n
 if (arr[i] == x) { 
 return i; //c2
 }
 }
 return-1; //c3
 }
/*Pergunta: Qual e a complexidade de tempo desse algoritmo no pior caso? Como ela se compara com
a complexidade de tempo de uma busca binaria em um array ordenado?*/

/*Resposta:
c1n + c2 + c3
c1n + b
c1n
O(n)

A busca binária é mais rápida, especialmente para arrays grandes, devido à sua complexidade O(logn), enquanto a busca linear tem complexidade O(n).
 */