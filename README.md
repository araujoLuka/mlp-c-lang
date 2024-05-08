# Neural Network Library in C

Este é um projeto em C para a implementação de uma biblioteca de redes neurais simples. Atualmente, o projeto inclui a implementação básica de um neurônio, que pode ser usado como parte de uma rede neural mais complexa.

## Estrutura do Projeto

O projeto é estruturado da seguinte forma:

- `neuron.h`: O arquivo de cabeçalho contendo a definição da estrutura de neurônio e as funções para criar, calcular a saída e destruir um neurônio.
- `neuron.c`: A implementação das funções definidas em `neuron.h`.
- `functions.h`: O arquivo de cabeçalho contendo definições de funções de ativação para uso em neurônios (como ReLU, sigmoid, etc.).
- `functions.c`: A implementação das funções de ativação definidas em `functions.h`.

## Bibliotecas

### Neuron

Para essa biblioteca foi desenvolvido as alocações da estrutura do neurônio, bem como o cálculo da saída do neurônio usando o ponteiro para a função de ativação com o produto interno da entrada com os pesos do neurônio.

## Estruturas de Dados

### Neuron

A estrutura de dados `neuron_t` representa um neurônio em uma rede neural. Ela contém as seguintes informações:
- `n_inputs`: o número de entradas do neurônio.
- `weights`: um array de floats representando os pesos associados a cada entrada do neurônio.
- `bias`: o valor do viés (bias) do neurônio.
- `delta`: o valor do delta associado ao neurônio para uso em algoritmos de aprendizado de máquina.

## Uso

Para usar a biblioteca, basta incluir o arquivo de cabeçalho `neuron.h` em seu código fonte e linkar com o arquivo objeto `neuron.o` gerado pela compilação de `neuron.c`.

Aqui está um exemplo básico de como criar, calcular a saída e destruir um neurônio:

```c
#include <stdio.h>
#include "neuron.h"

int main() {
    // Criar um neurônio com 3 inputs
    neuron_t* neuron = neuron_create(3);

    // Definir inputs
    float inputs[] = {0.5, 0.3, 0.2};

    // Calcular a saída do neurônio usando a função de ativação ReLU
    float output = neuron_output(neuron, inputs, ReLU);

    // Exibir a saída calculada
    printf("Output: %f\n", output);

    // Destruir o neurônio para liberar memória
    neuron_destroy(neuron);

    return 0;
}
```

## Contribuição

Contribuições não são aceitas neste projeto, pois é um trabalho de conclusão de curso. No entanto, sugestões e feedback são sempre bem-vindos!

## Contexto do Projeto

Este projeto é uma implementação de uma MLP (Multilayer Perceptron) desenvolvida como parte do trabalho de conclusão de curso do curso de Bacharelado em Ciência da Computação. O projeto é orientado pelo professor e doutor Paulo Ricardo Lisboa de Almeida. O objetivo do trabalho é medir a performance e o desempenho entre a arquitetura dos processadores x86 e dos processadores RISC-V usando esta implementação de MLP.

## Licença

Este projeto é licenciado sob a [MIT License](LICENSE).

