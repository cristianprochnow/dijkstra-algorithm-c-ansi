#include <stdio.h>
#include <stdlib.h>

void main()
{
  int valor[10][10],
      distancia[10],
      caminho[10][10],
      quantidade_nos,
      no_para_visitar,
      qtd_caminhos_validos,
      linha,
      col,
      min,
      index = 1,
      x,
      y;

  /*
  Aqui é inserido o número total de nós do grafo inteiro, ou seja, para a matriz
  resultante, será o número de colunas e de linhas contidas (já que matriz
  sempre possui a quantidade de colunas igual à de linhas).
  */
  printf("Coloque o numero de nos: \n");
  scanf("%d", &quantidade_nos);

  /*
  Esse daqui é o trecho em que os pesos vão ser inseridos na matriz conforme
  a conexão de cada um dos nós. Sendo assim, leva em conta a matriz de pesos,
  demonstrada no README.

  Então, cada umn dos valores das arestas vão contar, pegando diretamente os
  valores da tabela matriz de base.
  */
  printf("Coloque os valores da matriz: \n");
  /* Percorrendo cada linha da matriz. */
  for (x = 1; x <= quantidade_nos; x++)
  {
    /* Percorrendo cada coluna da linha. */
    for (y = 1; y <= quantidade_nos; y++)
    {
      /* Pegando o valor da célula da coordenada da matriz. */
      scanf("%d", &valor[x][y]);
    }
  }

  /* O identificador do nó em si que o usuário quer visitar. */
  printf("Coloque o no que vc quer visitar: \n");
  scanf("%d", &no_para_visitar);

  /*
  Levando em conta a exemplificação da seção de "Caminhos", presente no README,
  o usuário vai inserir a quantidade de caminhos válidos que foi elencada (quantidade
  de linhas daquela tabela).
  */
  printf("Coloque a quantidade de caminhos para o no selecionado: \n");
  scanf("%d", &qtd_caminhos_validos);

  /*
  Essa é a etapa que vamos inserir o valor de cada um dos nós que iremos percorrer
  em cada uma das possibilidades, para então conseguir elencar o valor do peso
  total de cada uma das poissibilidades.

  Então, levando em conta aquela mesma tabela da seção de "Caminhos", o valor
  colocado aqui vai seguir a ordem de valores daquela tabela (onde está vazio,
  pode colocar 0).
  */
  printf("Coloque os valores da matriz de caminhos: \n");
  /* Percorrendo a quantidade de possibilidades elencadas. */
  for (x = 1; x <= qtd_caminhos_validos; x++)
  {
    /* Pegando os valores de cada um dos passos que têm que ser dada de nó em nó. */
    for (y = 1; y <= quantidade_nos; y++)
    {
      scanf("%d", &caminho[x][y]);
    }
  }

  /*
  Agora é o momento de calcular a distancia minima e o menor caminho para chegar no lugar desejado
  ele percorre cada caminho informado anteriormente e calcula essa distancia somando elas ao longo do caminho.

  Esse cálculo contabiliza os passos dados nas etapas juntamente com o valor
  de pesos que foi inserido no início do processo na matriz original que foi dada.
  */
  for (x = 1; x <= qtd_caminhos_validos; x++)
  {
    /* Equivalente total de pesos de cada uma das possibilidaes elencadas. */
    distancia[x] = 0;
    linha = 1;
    /* Percorrer cada uma das colunas das possibilidades. */
    for (y = 1; y < quantidade_nos; y++)
    {
      /*
      Verificação para somar os valores apenas até o nó destino, evitando assim
      com que a contabilização pegue nós desnecessários.
      */
      if (linha != no_para_visitar)
      {
        /*
        Pegar o valor identificador do nó que está sendo percorrido na rodada.

        Motivos do `y + 1`:

        1.  y começa com 1,  e vai o loop até ser menor que a quantidade de nós,
            então se a quantidade for 5, o loop só iria até a coluna 4, então
            o +1 compensa para pegar o último índice.
        2.  Na matriz de caminhos possíveis, a primeira posição vai ser sempre o
            item que iniciamos o caminho. Com isso, o valor dele não importa,
            já que consideramos sempre o peso dele até o próximo, então a raiz
            que já está presente pode ser descartada, pois o que importa é o valor
            da aresta, e não do vértice.
        */
        col = caminho[x][y + 1];
        /*
        Pega o peso equivalente daquela coordenada que bate certinho o nó
        que está sendo percorrida na rodada atual, com a próxima coluna que vai
        ser atingida.
        */
        distancia[x] = distancia[x] + valor[linha][col];
      }
      /*
      Para a verificação se o nó desejado foi atingido ou não bater com o
      próximo nó que vai ser verificado no passo seguinte do caminho, na verificação
      que vai reiniciar assim que essa rodada agora acabar.
      */
      linha = col;
    }
  }

  /*
  Então, aqui nessa etapa ele verifica qual foi a linha de caminhos elencados
  que possui o menor valor, e ao achar essa linha que é a menor de todas (ou seja,
  o trajeto mais curto), guarda também o índice do caminho, para ter tanto
  o valor total de peso daquela rota mais curta, como também os passos que terão
  de ser feitos, equivalentes a esse total de peso.
  */
  min = distancia[1];
  for (x = 1; x <= qtd_caminhos_validos; x++)
  {
    /* Elencando qual dos totais de peso é o menor, e guardando a posição do caminho equivalente. */
    if (distancia[x] <= min)
    {
      min = distancia[x];
      index = x;
    }
  }

  /*
  Aqui o programa percorre e caminho correspondente ao caminho minimo a se percorrer
  o valor 0 indica o final do caminho.
  */
  printf("minima distancia eh %d\n", min);
  printf("menor caminho e \n");
  for (x = 1; x <= quantidade_nos; x++)
  {
    if (caminho[index][x] != 0)
    {
      printf("-->%d", caminho[index][x]);
    }
  }
}
