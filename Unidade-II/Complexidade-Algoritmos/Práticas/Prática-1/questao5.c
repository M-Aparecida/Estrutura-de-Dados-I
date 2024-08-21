//Considere o algoritmo de ordenacao por selecao:
 void selection_sort(int arr[], int n) {
 int i, j, min_idx; //c1
 for (i = 0; i < n-1; i++) { //c2n-1
 min_idx = i; //c3
 for (j = i+1; j < n; j++) { //n-1^2c4
 if (arr[j] < arr[min_idx]) { //n-1^2c5
 min_idx = j; //c6
 }
 }
 int temp = arr[min_idx]; 
 arr[min_idx] = arr[i]; //c7
 arr[i] = temp; //c8
 }
 }
/*Pergunta: Qual e a complexidade de tempo desse algoritmo? Existem algoritmos de ordenacao mais eficientes? Se sim, cite um exemplo.*/

/*Resposta:
c1 + c2(n−1) + c3 + (n−1)2c4 + (n−1)2c5 + c6 + c7 + c8
n−12(c4 + c5) + nc2 + c1 + c3 + c6 + c7 + c8
(n−1)2a + nb + c
(n−1)2a + nb
n2−2n + 1
n2a−2na + a + nb
O(n^2)

Sim, o Quick Sort.
*/