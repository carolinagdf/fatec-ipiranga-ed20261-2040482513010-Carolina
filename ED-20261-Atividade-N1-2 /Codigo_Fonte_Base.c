/*----------------------------------------------------------------------------------*/
/*FATEC-Ipiranga                                                                    */        
/*ADS - Estrutura de Dados                                                          */
/*Id da Atividade: N1-2                                                             */
/*Objetivo: Estado de memória                                                       */
/*                                                                                  */
/*Autor: Carolina Gusmão de França                                                           */
/*Data:04/04/2026                                                                   */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
// Versão iterativa que imprime os dígitos na ordem inversa
void inverterNumero(int n){
    if (n == 0) {
        printf("0");
        return;    
    }
    while (n > 0){
        printf("%d", n % 10); // Imprime o último dígito
        n = n / 10; // Remove o último dígito do número
    }
}
int main(){
    int valor = 12345;
    printf("Invertendo o numero %d: ", valor);
    inverterNumero(valor);
    printf("\n");
    return 0;
}
