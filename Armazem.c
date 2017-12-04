#include <stdio.h>

int main() 
{

    /** preço de 10 produtos armazenados em um vetor */

    /**
    * TODO: Descomentar antes de entregar
    */ 
    // float produtos[10];
    float produtos[10] = {1,2,3,4,5,6,7,8,9,10};

    /** código de 5 armazéns */

    /**
    * TODO: Descomentar antes de entregar
    */ 
    // int arm[5];
    int arm[5] = {43,53,2132,32,111};
    
    /** quantidade estocada em cada um desses produtos em cinco armazéns diferentes */

    /**
    * TODO: Descomentar antes de entregar
    */ 
    // int mat[5][10];
    int mat[5][10] = {
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,14},
        {-10,2,3,4,5,6,7,8,9,10},
        {-10,2,3,4,5,6,7,8,9,10},
        {1,2,3,4,5,6,7,8,9,10}
    };

    //E) 
    int listaCustoArm[5]; 

    /** soma dos produtos */
    float somaP = 0;

    int produtoMaiorEstoque = 0;

    /** maior estoque */
    int maiorE = 0;

    //menor estoque armazenado
    int menorE = 999999;
    
    //codigo do armazem com menor estoque
    int armMenorE = 0;

    //vetor dos codigos de armazem com menor estoque
    int vetCodMenorE[5];

    //vetor para a soma dos produtos de cada armazem
    int vetSomaProd[5];

    /** recebendo os valores dos produtos */
    for(int i=0;i<10;i++)
    {
        /**
        * TODO: Descomentar antes de entregar
        */ 
        // printf("Informe o valor do produto %i: ", i);
        // scanf("%f", &produtos[i]);
    }
    
    printf("\n\n\n");
    
    /** recebendo os valores dos armazéns */
    for(int i=0;i<5;i++)
    {
        /**
        * TODO: Descomentar antes de entregar
        */ 
        // printf("Informe o código do armazém %i: ", i);
        // scanf("%d", &arm[i]);
    }

    printf("\n\n\n");
    
    /** recebendo a quantidade estocada */
    for(int i=0;i<5;i++)
    {
        int somaProdutoE = 0;

        for(int j=0;j<10;j++)
        {
            /**
             * TODO: Descomentar antes de entregar
             */ 
            // printf("Informe a quantidade do produto %i no armazem %i: ", j, i);
            // scanf("%d", &mat[i][j]);

            /** B) somando */
            somaP += mat[i][j];

            //D
            somaProdutoE += mat[i][j];
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

    
    printf("\n\n\n");
    
    /** A) A quantidade de produtos estocados em cada armazém */
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("\nQuantidade do produto %i no armazem %i: %i ", j, i, mat[i][j]);
        }
    }

    /** B) Print da soma */
    printf("\n\nA quantidade de cada produto estocado em cada um dos armazens: %.2f ", somaP);

    /** C) */

    printf("\n\nO preco do produto com maior estoque e: %.2f", produtos[produtoMaiorEstoque]);

    // D)
    printf("\n\nO menor estoque armazenado e: %i", menorE);
    printf("\n\nOs codigos dos armazens com menor estoque sao: ");
    for(int i=0; i<5; i++)
    {
        if(vetSomaProd[i] == menorE)
        {
            printf("\nCódigo do Armazem: %i", arm[i]);
            printf("\nSoma de Produtos: %i", listaCustoArm[i]);
        }
    }

    // D)
    for(int i=0; i<5; i++)
    {
        printf("\n\nCódigo do Armazem: %i", arm[i]);
        printf("\nCusto do armazem: %i", listaCustoArm[i]);
    }

    return 0;
}