# Atividade Algoritmos de Ordenação - Bubble e Quick

Este projeto contém implementações dos algoritmos de ordenação Bubble Sort e Quick Sort. A seguir, apresentamos uma comparação entre esses métodos, uma breve explicação sobre a escolha de pivôs na função do Quick Sort e detalhes sobre o tempo de execução de cada algoritmo.

## Comparação dos Métodos de Ordenação

### Bubble Sort
O Bubble Sort é um algoritmo de ordenação simples que compara pares de elementos adjacentes e os troca se estiverem na ordem errada. Este processo é repetido até que a lista esteja ordenada. Embora seja fácil de entender e implementar, o Bubble Sort é ineficiente para grandes conjuntos de dados devido à sua complexidade de tempo O(n^2).

### Quick Sort
O Quick Sort é um algoritmo de ordenação eficiente que utiliza a técnica de divisão e conquista. Ele seleciona um elemento como pivô e particiona a lista em duas sublistas: uma com elementos menores que o pivô e outra com elementos maiores. O processo é então recursivamente aplicado às sublistas. O Quick Sort tem uma complexidade de tempo média de O(n log n), tornando-o muito mais rápido que o Bubble Sort para grandes conjuntos de dados.

## Escolha dos Pivôs para a Função de QuickSort

Na minha implementação do QuickSort, optei por escolher o último elemento como pivô. Essa decisão é prática e direta, pois evita a necessidade de escolher o pivô de forma mais complexa, o que **simplifica** a lógica do algoritmo.

O último elemento geralmente proporciona uma divisão razoavelmente equilibrada dos dados, o que contribui para a eficiência do algoritmo. Além disso, é uma escolha consistente que funciona bem em muitos casos, sem precisar de cálculos adicionais para determinar o pivô.

## Tempo de Execução
Durante os testes, observamos os seguintes tempos de execução para os algoritmos:
- **Bubble Sort**: 10 horas e 30 minutos;
- **Quick Sort**: 4 segundos.

Esses resultados demonstram a superioridade do Quick Sort em termos de eficiência, especialmente para grandes conjuntos de dados.

## Função `print_dataset_100`
A função `print_dataset_100` é utilizada para imprimir apenas os 100 primeiros elementos ordenados do conjunto de dados. Isso facilita a visualização e verificação dos resultados sem a necessidade de exibir todo o conjunto de dados.

```cpp
        void print_dataset_100(const std::vector<DishRecord>& dishes) {
            for (int i = 0; i < 100; ++i) {
                const DishRecord& dish = dishes[i];
                std::cout << dish.priority << std::setw(10) << dish.time << std::setw(22) << dish.name << std::endl;
            }
        }
```

## Considerações finais

Neste trabalho, gostaria de informar que os commits no repositório do GitHub estão no nome do meu irmão, Guilherme Marchioli. Isso ocorreu porque ambos utilizamos o VSCode, e houve um conflito entre contas do programa durante a execução da atividade.

Também ressalto que o Bubble Sort teve uma péssima performance no meu computador, devido à inferioridade do hardware. Meu laptop, que já tem alguns anos de uso, não é adequado para executar algoritmos que demandam alto desempenho. Portanto, os resultados obtidos podem não refletir a eficiência real do Bubble Sort em máquinas mais modernas e potentes.