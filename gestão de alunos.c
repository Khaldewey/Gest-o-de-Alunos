#include <stdio.h>
#define aulas 36
#define qtd 4
#include <string.h>
#include <stdlib.h>
int main(void)
{
  int i, x, y, mat, nMat, cont = 0, faltas, indice;
  int v[qtd], f[qtd];
  float n1[qtd], n2[qtd], m[qtd], percFaltas, frequencia, fr[qtd];
  int check, check1;

  for (x = 0; x < qtd; x++)
  { // Estrutura para resetar todas as variáveis dos vetores antes do funcionamento do programa para evitar bugs //
    v[x] = 0;
    m[x] = 0;
    fr[x] = 0;
    n1[x] = 0;
    n2[x] = 0;
  }

  // Começo do programa com um conjunto de opções o qual se repete até que seja escolhida a opção "8" //
inicio: // referência de retorno do comando goto usado para que o programa reinicie após a utilização de uma funcionalidade //
  do
  {
    printf("Escolha uma opcao\n");
    printf(" (1) Cadastrar aluno no vetor\n");
    printf(" (2) Remover um aluno do vetor\n");
    printf(" (3) Atualizar dados de um aluno do vetor\n");
    printf(" (4) Listar alunos cadastrados no vetor\n");
    printf(" (5) Listar alunos aprovados\n");
    printf(" (6) Listar alunos reprovados por media\n");
    printf(" (7) Listar alunos reprovados por faltas\n");
    printf(" (8) Sair\n");
    scanf("%d", &i);
    mat = 0;
    nMat = 0;
    check = 0;
    check1 = 0;

    if (i < 1 || i > 8)
    { // condição para que o alerta de erro seja imprimido //
      printf("Erro 00: Opcao inexistente\n");
    }
    switch (i)
    {

    case 1:
      for (x = 0; x < qtd; x++)
      { // estrutura de repetição para vasculhar se os vetores estão preenchidos //
        if (v[x] != 0)
        {
          cont++;
        }
      }
      if (cont == qtd)
      {
        printf("Erro fatal: Nao e permitido fazer cadastro com matriculas ja cadastradas. \n");
        break;
      }
      // se for constatado que já estão preenchidos o programa é finalizado para evitar fraudes nas matriculas//

      for (x = 0; x < qtd; x++)
      {
        printf("Digite o numero inteiro da matricula para a posicao %i\n", x);
        scanf("%d", &v[x]); // estrutura de repetição para preencher os vetores //
      }
      for (x = 0; x < qtd; x++)
      { // estruturas para verificar se existem matrículas iguais //
        for (y = x + 1; y < qtd; y++)
        {
          if (v[x] == v[y])
          {
            printf("Erro 01: Matriculas iguais\n"); // alerta de erro a ser imprimido se for encontrado valores iguais //
            for (x = 0; x < qtd; x++)
            {
              v[x] = 0;
            }
          }
        }
      }

      goto inicio;

    case 2:
      for (x = 0; x < qtd; x++)
      { // estrutura para verificar se os vetores estão vazios //
        if (v[x] == 0)
        {
          cont++;
        }
      }
      if (cont == qtd)
      {
        printf("ERRO 03: Vetores vazios\n"); // alerta de erro a ser imprimido se for confirmado //
        break;
      }
      printf("Digite a matricula\n"); // comandos que constituem a opção (2) //
      scanf("%d", &mat);
      for (x = 0; x < qtd; x++)
      {
        if (v[x] == mat)
        {
          check = 1;
        }
      }
      if (check == 1)
      {
        for (x = 0; x < qtd; x++)
        {
          if (mat == v[x])
          {
            v[x] = 0;
            n1[x] = 0;
            n2[x] = 0;
            m[x] = 0;
            fr[x] = 0;
          volte:
            printf("Informe nova matricula para substituir\n");
            scanf("%d", &nMat);
            v[x] = nMat;
            for (x = 0; x < qtd; x++)
            {
              for (y = x + 1; y < qtd; y++)
              {
                if (v[x] == v[y])
                {
                  printf("Erro 01: Matriculas iguais\n");
                  goto volte;
                }
              }
            }
          }
        }
      }
      else
      {
        printf("Erro 02: Matricula nao encontrada\n");
        goto inicio;
      }
      goto inicio;

    case 3: // comandos que constituem a opção (3) //
      for (x = 0; x < qtd; x++)
      {
        if (v[x] == 0)
        {
          cont++;
        }
      }
      if (cont == qtd)
      {
        printf("ERRO 03: Vetores vazios\n");
        break;
      }
      printf("Digite a matricula do Aluno\n");
      scanf("%d", &mat);
      for (x = 0; x < qtd; x++)
      {
        if (v[x] == mat)
        {
          check1 = 1;
          indice = x;
        }
      }
      if (check1 == 1)
      {
      aquii:
        printf("Digite a primeira nota do aluno da posicao %d com matricula %d\n", indice, v[indice]);
        scanf("%f", &n1[indice]);
        if (n1[indice] < 0 || n1[indice] > 10)
        {
          printf("ERRO 04 - Informação invalida: 0 < nota < 10\n");
          goto aquii;
        }
      aquiii:
        printf("Digite a segunda nota do aluno da posicao %d com matricula %d\n", indice, v[indice]);
        scanf("%f", &n2[indice]);
        if (n2[indice] < 0 || n2[indice] > 10)
        {
          printf("ERRO 04 - Informação invalida: 0 < nota < 10\n");
          goto aquiii;
        }
      aqui:
        printf("Digite a quantidade de faltas do aluno da posicao %d com matricula %d\n", indice, v[indice]);
        scanf("%d", &f[indice]);
        if (f[indice] > 36 || f[indice] < 0)
        {
          printf("ERRO 04 - Informação invalida: 0 < faltas < 36\n");
          goto aqui;
        }
        m[indice] = (n1[indice] + n2[indice]) / 2.0;
        percFaltas = f[indice] * 100 / aulas;
        frequencia = 100.0 - percFaltas;
        fr[indice] = frequencia;
      }
      else
      {
        printf("Erro 02: Matricula nao encontrada\n");
        goto inicio;
      }
      goto inicio;

    case 4: // comandos que constituem a opção (4) //
      for (x = 0; x < qtd; x++)
      {
        if (v[x] == 0)
        {
          cont++;
        }
      }
      if (cont == qtd)
      {
        printf("ERRO 03: VETORES VAZIOS\n");
        break;
      }
      else
      {
        printf("Matriculas cadastradas\n");
        for (x = 0; x < qtd; x++)
        {
          printf("%d\n", v[x]);
        }
      }
      goto inicio;

    case 5: // comandos que constituem a opção (5) //
      for (x = 0; x < qtd; x++)
      {
        if (v[x] == 0)
        {
          cont++;
        }
      }
      if (cont == qtd)
      {
        printf("ERRO 03: Vetores vazios\n");
        break;
      }
      for (x = 0; x < qtd; x++)
      {
        if (m[x] >= 7.0 && fr[x] > 60.0)
        {
          printf("O aluno de matricula %d foi aprovado com media %0.2f e frequencia de %0.0f por cento\n", v[x], m[x], fr[x]);
          check = 1;
        }
      }
      if (check != 1)
      {
        printf("Nenhum aluno aprovado\n");
      }

      goto inicio;

    case 6: // comandos que constituem a opção (6) //
      for (x = 0; x < qtd; x++)
      {
        if (v[x] == 0)
        {
          cont++;
        }
      }
      if (cont == qtd)
      {
        printf("ERRO 03: Vetores vazios\n");
        break;
      }
      for (x = 0; x < qtd; x++)
      {
        if (m[x] < 7.0)
        {
          printf("O aluno de matricula %d foi reprovado com media %0.2f \n", v[x], m[x]);
        }
      }
      goto inicio;

    case 7: // comandos que constituem a opção (7) //
      for (x = 0; x < qtd; x++)
      {
        if (v[x] == 0)
        {
          cont++;
        }
      }
      if (cont == qtd)
      {
        printf("ERRO 03: Vetores vazios\n");
        break;
      }
      for (x = 0; x < qtd; x++)
      {
        if (fr[x] < 60.0)
        {
          printf("O aluno de matricula %d foi reprovado por ter %0.0f por cento de frequência \n", v[x], fr[x]);
          check = 1;
        }
      }
      if (check != 1)
      {
        printf("Nada encontrado\n");
      }
      goto inicio;

    case 8: // Fim //
      break;
    }
  } while (i < 1 || i > 8);
  return 0;
}