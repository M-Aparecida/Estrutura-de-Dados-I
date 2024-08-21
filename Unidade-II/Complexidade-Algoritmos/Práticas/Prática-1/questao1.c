//Analise de Complexidade de um Algoritmo Simples
//Considere o seguinte algoritmo:
 int soma_numeros(int n) {
 int soma = 0; //c1
 for (int i = 1; i <= n; i++) { //c2n
 soma += i; //c3n
 }
 return soma; //c4
 }
//Pergunta: Qual e a complexidade de tempo desse algoritmo? Justifique sua resposta.

/*Resposta: 
c1 + c2n + c3n + c4
n(c2+c3) +c1 + c4
na + b
O(n)
*/ 