# Problema [1531 - Fibonacci de novo!]()

A famosa sequência de Fibonacci pode ser definida da seguinte maneira:

  Fib( 1 ) = Fib( 2 ) = 1
  Fib( N ) = Fib( N-1 ) + Fib( N-2 ), para N > 2
  
Sua tarefa é simples, calcular o valor do resto de Fib( Fib( N ) ) por M.

## Entrada
A entrada é composta por vários casos de teste e termina com EOF. Cada caso de teste consiste de uma linha com dois inteiros N e M (1 ≤ N ≤ 10^9, 2 ≤ M ≤ 10^6).

## Saída
Para cada caso de teste, imprima uma linha contendo um inteiro igual ao resto de Fib( Fib( N ) ) por M.

<details>
  <summary>Solução 1:</summary>
  
  Essa questão envolve otimização com relação ao cálculo de fibonacci (deve ser utilizado o algoritmo baseado em potenciacao de matriz) e período de Pisano.
  Toda a sequência de Fibonacci mod m é periódica. O período de Pisano é o cálculo do tamanho desse período. 
  
  Considere que o período de pisano é representado por p(n).
  
  A chave para essa questão é utilizar a seguinte propriedade: fib(n) mod m = fib(n mod p(m)) mod m
  

- [Fernando Pozze](https://github.com/fernandoPozzer)

</details>
