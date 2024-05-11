# Biblioteca de Redes Neurais em C

Este é um projeto em C para a implementação de uma biblioteca de redes neurais simples. Atualmente, o projeto inclui a implementação básica de um neurônio, bem como as estruturas de camada (layer) e rede neural (network).

## Estrutura do Projeto

O projeto é estruturado da seguinte forma:

- `neuron.h`: O arquivo de cabeçalho contendo a definição da estrutura de neurônio e as funções para criar, calcular a saída e destruir um neurônio.
- `neuron.c`: A implementação das funções definidas em `neuron.h`.
- `layer.h`: O arquivo de cabeçalho contendo a definição da estrutura de camada e as funções para criar, calcular a saída e destruir uma camada.
- `layer.c`: A implementação das funções definidas em `layer.h`.
- `network.h`: O arquivo de cabeçalho contendo a definição da estrutura de rede neural e as funções para criar, adicionar camadas e propagar entradas pela rede.
- `network.c`: A implementação das funções definidas em `network.h`.
- `functions.h`: O arquivo de cabeçalho contendo definições de funções de ativação para uso em neurônios.
- `functions.c`: A implementação das funções de ativação definidas em `functions.h`.

## Bibliotecas

### Neuron

Para essa biblioteca, foram desenvolvidas as alocações da estrutura do neurônio, bem como o cálculo da saída do neurônio usando o ponteiro para a função de ativação com o produto interno da entrada com os pesos do neurônio.

### Layer

Nesta biblioteca, foram implementadas as estruturas e funções relacionadas às camadas da rede neural. Isso inclui a criação, computação da saída e destruição de camadas, bem como a alocação de memória para armazenar as saídas das camadas.

### Network

A biblioteca de rede neural inclui funcionalidades para criar uma rede neural a partir de camadas, adicionar camadas à rede e propagar entradas pela rede neural. Isso permite a construção e uso de redes neurais multicamadas.

## Uso

Para usar a biblioteca, basta incluir os arquivos de cabeçalho necessários em seu código fonte e linkar com os arquivos objetos gerados pela compilação dos respectivos arquivos de código-fonte.

## Contribuição

Contribuições não são aceitas neste projeto, pois é um trabalho de conclusão de curso. No entanto, sugestões e feedback são sempre bem-vindos!

## Contexto do Projeto

Este projeto é uma implementação de uma MLP (Multilayer Perceptron) desenvolvida como parte do trabalho de conclusão de curso do curso de Bacharelado em Ciência da Computação. O projeto é orientado pelo professor e doutor Paulo Ricardo Lisboa de Almeida. O objetivo do trabalho é medir a performance e o desempenho entre a arquitetura dos processadores x86 e dos processadores RISC-V usando esta implementação de MLP.

## Licença

Este projeto é licenciado sob a [MIT License](LICENSE).
