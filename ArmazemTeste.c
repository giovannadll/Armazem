#include <stdio.h>

int main() 
{
    /** preço de 10 produtos armazenados em um vetor */

    float produtos[10] = {10,22,33,44,55,66,77,88,99,100};

    /** código de 5 armazéns */

    int arm[5] = {43,53,2132,32,111};
    
    /** quantidade estocada em cada um desses produtos em cinco armazéns diferentes */

    int mat[5][10] = {
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,14},
        {-10,22,300,43,552,336,721,83,91,10},
        {-10,22,300,2001,5123,2001,73,84,92,10},
        {1,2,3,4,5,6,7,8,9,10}
    };

    /** lista de custos dos armazéns **/
    float listaCustoArm[5]; 

    /** soma dos produtos */
    float somaP = 0;

    /** produto com maior quantidade no estoque **/
    int produtoMaiorEstoque = 0;

    /** maior quantidade no estoque */
    int maiorE = 0;

    /** menor estoque armazenado **/
    int menorE = 999999;
    
    /** codigo do armazem com menor estoque **/
    int armMenorE = 0;

    /** vetor dos codigos de armazem com menor estoque **/
    int vetCodMenorE[5];

    /** vetor para a soma dos produtos de cada armazem **/ 
    int vetSomaProd[5];

    /** recebendo a quantidade estocada */
    for(int i=0;i<5;i++)
    {
        int somaProdutoE = 0;

        for(int j=0;j<10;j++)
        {
            /** B) somando */
            somaP += mat[i][j];

            //D
            somaProdutoE += mat[i][j];
            listaCustoArm[i] += produtos[j] * mat[i][j];

            /** C) maior estoque */
            if(maiorE < mat[i][j])
            {
                maiorE = mat[i][j];
                produtoMaiorEstoque = j;
            }
        }

        if(menorE > somaProdutoE)
        {
            menorE = somaProdutoE;
        }

        vetSomaProd[i] = somaProdutoE;
    }

    printf("\n\n ***************\n");
    printf(" ** QUESTÃO A **\n");
    printf(" ***************");

    printf("\n");

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("\nQuantidade do produto %i no armazém %i: %i ", j, i, mat[i][j]);
        }
    }

    printf("\n\n ***************\n");
    printf(" ** QUESTÃO B **\n");
    printf(" ***************");

    printf("\n\n ** A quantidade de cada produto estocado em cada um dos armazéns: %.2f ", somaP);

    printf("\n\n ***************\n");
    printf(" ** QUESTÃO C **\n");
    printf(" ***************");

    printf("\n\n ** O preco do produto com maior estoque é: %.2f", produtos[produtoMaiorEstoque]);

    printf("\n\n ***************\n");
    printf(" ** QUESTÃO D **\n");
    printf(" ***************");

    printf("\n\n ** O menor estoque armazenado é: %i", menorE);
    printf("\n\n ** Os Codigos dos Armazéns com menor estoque são: ");

    for(int i=0; i<5; i++)
    {
        if(vetSomaProd[i] == menorE)
        {
            printf("\n\nCódigo do Armazém: %i", arm[i]);
            printf("\nSoma de Produtos: %i", vetSomaProd[i]);
        }
    }

    printf("\n\n ***************\n");
    printf(" ** QUESTÃO E **\n");
    printf(" ***************");

    printf("\n\n ** Os Custos dos Armazéns são: ");

    for(int i=0; i<5; i++)
    {
        printf("\n\nCódigo do Armazém: %i", arm[i]);
        printf("\nCusto do Armazém: R$ %.2f", listaCustoArm[i]);
    }

    printf("\n\n ***************\n");
    printf(" ** QUESTÃO F **\n");
    printf(" ***************\n\n");

    int codigoArmazem = -1;
    int indiceArmazem = -1;

    while (1) {
        /** lê código do armazém */
        printf("\nDigite o código do armazém:");
        scanf("%d", &codigoArmazem);

        /** verifica se código do armazém existe */
        for (int i = 0; i < 5; i++)
        {
            if (arm[i] == codigoArmazem)
            {
                /** atribui o indice do armazem para a variavel indiceArmazem*/
                indiceArmazem = i;
            }
        }

        /** se indiceArmazem for diferente de -1, o valor padrão, quer dizer que encontrou um código válido */
        if (indiceArmazem != -1)
        {
            printf("\n\n ***************\n");
            printf(" ** O Armazém de código %i existe. **\n", codigoArmazem);
            printf(" ** Contando quantidade de produtos com preço médio com quantidade maior que 2000.. **\n");
            printf(" ***************\n\n");

            /** soma quantidade de produtos com preço entre 50 e 100 reais */
            int quantidadeProdutosPrecoMedio = 0;

            for (int i = 0; i < 10; i++) {
                int valorProduto = produtos[i];
                if (valorProduto > 50.00 && valorProduto <= 100.00)
                {
                    int quantidadeProduto = mat[indiceArmazem][i];
                    if (quantidadeProduto > 2000) {
                        quantidadeProdutosPrecoMedio += quantidadeProduto;
                    }
                }
            }

            printf("\n\n ***************\n");
            printf(" ** Quantidade de Produtos no Armazem de Código %i: %i **\n", codigoArmazem, quantidadeProdutosPrecoMedio);
            printf(" ***************\n\n");
        }
        
        /** se indiceArmazem for -1, o valor padrão, quer dizer que não encontrou nada */
        if (indiceArmazem == -1)
        {
            printf("\n\n ***************\n");
            printf(" ** Armazém de código %i não existe. Tente novamente. ** \n", codigoArmazem);
            printf(" ***************\n\n");
        }

        /** limpa o código e indice do armazem */
        codigoArmazem = 0;
        indiceArmazem = -1;
    }
}