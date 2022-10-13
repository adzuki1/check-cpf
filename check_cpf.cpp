/*
Este programa precisa ler 11 dígitos de um cpf, calcular os validadores e checar
se o cpf é válido É necessário separar cada dígito em uma variável ou array,
pois serão realizadas operações aritméticas com cada dígito. % por 10 extrai o
último número; dividir pelo número total de casas exclui o primeiro numero.
*/

/*
Problemas a resolver:

  ter outra variável que armazene o valor inserido -> RESOLVIDO

  input deverá conter o cpf completo (n = 11) e checar se os validadores são
  válidos -> RESOLVIDO

  printar se os validadores são válidos -> RESOLVIDO

  encontrar outro método p. separar o cpf dos validadores -> RESOLVIDO

  fazer o programa ler cpfs que começam com zero -> RESOLVIDO

  fazer o tamanho da array aceitar uma variável

  quando o cpf começar em 0, o programa irá ler o número de dígitos = 8 -> RESOLVIDO

  aceitar cpfs com 9 dígitos -> RESOLVIDO
*/

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

//globals var:
long cpf, len;
              //0  1  2  3  4  5  6  7  8  9  10  [indices]
int append[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
              //9  5  7  2  4  0  4  9  0  3  1  [valores]
int valid1, valid2, val1, val2, max_dig = 11;

void split();
void valid();
bool compare();

int main(){
    cout << "Digite seu CPF: ";
    cin >> cpf; // input do número
    //store_cpf = cpf;

    len = trunc(log10(cpf)) + 1; // calcula total de dígitos

    split();
    valid();

    cout << endl << "Os digitos validadores informados sao: "
         << val1 << val2 << endl;
    
    cout << compare();

    return 0;
}

// additional functions:
void split(){
    // separa os dígitos em uma array, substituindo os validadores por zero.

    if (len == 11 ||  len == 10){ // quando todos os digitos sao informados
        for (int i = 0; i < max_dig; i++) {
        append[i] = cpf % 10;
        cpf /= 10;
        }
        
        val1 = append[1];
        val2 = append[0];
    }

    else // quando os validadores nao forem informados
        for (int i = 2; i < max_dig; i++) {
            append[i] = cpf % 10;
            cpf /= 10;
        }
        
        val1 = append[1];
        val2 = append[0];

}

void valid(){
    // calcula os validadores

    // encontra o primeiro dígito validador do cpf:
    valid1 = 0;

    for (int i = 10, j = 1; i >= 2 && j <= 9; i-- && j++) {
        valid1 += (append[i] * j);
    }

      valid1 = valid1 % 11;

      cout << endl << "1º validador: " << valid1;

      // encontra o segundo digito validador do cpf:
      append[1] = valid1;
      valid2 = 0;
  
      for (int i = 10, j = 0; i >= 0 && j <= 9; i-- && j++) {
          valid2 += (append[i] * j);
      }
      valid2 = valid2 % 11;

      cout << endl << "2º validador: " << valid2;

      append[0] = valid2;
}

bool compare(){
    // compara os validadores inseridos com os calculados
    if (val1 && val2 != 0){
      if(valid1 == val1 && valid2 == val2){
          return true;
      }
      else
        return false;
    }

    else
        return false;

  return 0;
}
