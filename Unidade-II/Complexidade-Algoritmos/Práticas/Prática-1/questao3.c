//Considere o algoritmo a seguir:
 int soma(int arr[], int n) { 
 int soma = 0; 
 for (int i = 0; i < n; i++) { 
 soma += arr[i]; 
 }
 return soma;
 }
//Pergunta: Qual e a complexidade espacial desse algoritmo? Justifique sua resposta.

/*Resposta:
c + c + n
b + n
O(n)
*/