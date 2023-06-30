# Algoritmo de Dijkstra

Esse algoritmo tem que objetivo achar o ponto mais curto entre dois nós que forem identificados em meio a uim grafo. Com isso, independentemente de quantos nós existam e quais sejam suas localizações, esse algoritmo fica responsável por resolver esse problema.

# Nomenclatura

## Nós/Vértices

Que são cada um dos pontos de localização do grafo. Usando um mapa como base, podemos então dizer que cada nó é um local, que possui várias rotas para chegar ou para ir, isto é, possui ligações com outros "locais".

Esses itens são cada um dos constituintes de um grafo. Sendo assim, podem possuir entre si apenas ligações ou então ligações com valores distintos, que possam ser identificados conforme uma matriz;

## Arestas

São os caminhos em si entre cada nó. Ou seja, são os identificadores que guardam o valor entre cada nó, ou então o identificador se simplesmente há uma ligação ou não.

# Transformação em Matriz

Como dito anteriormente, os valores entre cada arestas podem ser usados apenas como identificador ou então como peso em si. Para isso, podemos usar matriz que simbolizam isso.

![diagram]

Usando como exemplo o diagrama acima, podemos então traduzir para os dois tipos de matrizes, sendo o com valor e o que define relação.

## Pesos

|       | **1** | **2** | **3** | **4** | **5** |
|-------|-------|-------|-------|-------|-------|
| **1** |   0   |   4   |   0   |   8   |   0   |
| **2** |   4   |   0   |   3   |   0   |   0   |
| **3** |   0   |   3   |   0   |   4   |   0   |
| **4** |   8   |   0   |   4   |   0   |   7   |
| **5** |   0   |   0   |   0   |   7   |   0   |

## Ligação

|       | **1** | **2** | **3** | **4** | **5** |
|-------|-------|-------|-------|-------|-------|
| **1** |   0   |   1   |   0   |   8   |   0   |
| **2** |   1   |   0   |   1   |   0   |   0   |
| **3** |   0   |   1   |   0   |   1   |   0   |
| **4** |   1   |   0   |   1   |   0   |   1   |
| **5** |   0   |   0   |   0   |   1   |   0   |

## Caminhos

Escolhendo então algum caminho de um nó ao outro, podemos definir também a matriz de caminho, isto é, quais os caminhos válidos para serem percorridos do nó de início ao nó de fim.

> Considerando do 1 ao 5, temos 2 caminhos...

Nesse caso, o eixo X podem ser considerados o **número de passos** do maior caminho possível, o eixo Y significa o **número de possibilidades** e o valor de cada célula é o nó que será acessado

Ou seja, para sair do nó 1 e chegar ao 5, temos duas possibilidades, que a primeira é percorrer os nós 1, 2, 3, 4, 5. E, junto a isso, temos a segunda possibilidade, que é ir 1, 4, 5.

Sendo assim, passando para o gráfico...

|       | **1** | **2** | **3** | **4** | **5** |
|-------|-------|-------|-------|-------|-------|
| **1** |   1   |   2   |   3   |   4   |   5   |
| **2** |   1   |   4   |   5   |       |       |

# Referência de código

🔗 [Repositório com o código base do algoritmo][gu-repo]

[gu-repo]: https://github.com/gustapine/dijkstra-algorithm/
[diagram]: ./.github/diagram.png