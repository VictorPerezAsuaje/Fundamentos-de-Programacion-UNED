/*
Se trata de realizar un programa que muestre por pantalla la hoja de calendario de cualquier mes y año comprendido entre los años 1601 y 3000. 
La hoja debe quedar ajustada a la izquierda de la pantalla y se deben emplear los caracteres ‘=’, ‘|’, ‘.’ y debe haber una línea en blanco 
antes de escribir la hoja del calendario.

El programa no deberá imprimir nada para los años fuera del rango de 1601 al 3000.
El programa debe pedir el mes y el año sólo una vez para cada ejecución.
*/


#include <stdio.h>

int main () {

  int lado;                         /* numero caracteres en cada lado del rombo */
  int lineas;                       /* numero de vueltas que ha dado el for principal */
  int caracteres;                   /* numero de caracteres por linea impresa */
  int espacios;                     /* numero de espacios al principio de la linea */

  printf("¿Lado del rombo? ");
  scanf("%d", &lado);

  if(lado >= 1 && lado <= 20){

      /*---- Triangulo superior ----*/
      for(int lineas = 1; lineas <= lado; lineas++){

        /*---- Triang. sup. izq. ----*/

        for(int espacios = 1; espacios <= lado-lineas; espacios++){
          printf (" ");
        }

        for(int caracteres = 1; caracteres <= lineas; caracteres++){
            if(caracteres % 4 == 3){
              printf ("o");
            }
            else if(caracteres % 4 == 2 || caracteres % 4 == 0){
              printf (".");
            }
            else{
              printf ("@");
            }
        }


        /*---- Triang. sup. der. ----*/

        for(int caracteres = lineas; caracteres >= 2; caracteres--){
            if(caracteres % 4 == 2){
              printf ("@");
            }
            else if(caracteres % 4 == 1 || caracteres % 4 == 3){
              printf (".");
            }
            else{
              printf ("o");
            }
        }

        printf ("\n");
      }

      /*--- Triangulo inferior ---*/

      for(int lineas = 1; lineas <= lado-1; lineas++){

        /*--- Triang. inf. izq. ---*/

        for(int espacios = 1;  espacios <= lineas; espacios++){
          printf (" ");
        }

        for(int caracteres = 1; caracteres <= lado-lineas; caracteres++){
          if(caracteres % 4 == 3){
              printf ("o");
            }
            else if(caracteres % 4 == 0 || caracteres % 4 == 2){
              printf (".");
            }
            else{
              printf ("@");
            }
        }

        /*--- Triang. inf. der. ---*/

        for(int caracteres= lado-lineas; caracteres >= 2; caracteres--) {
          if(caracteres % 4 == 2){
              printf ("@");
            }
            else if(caracteres % 4 == 1 || caracteres % 4 == 3){
              printf (".");
            }
            else{
              printf ("o");
            }
          }
        printf ("\n");
      }
  }
  else{
    printf("Lo sentimos, pero el numero ha de estar entre 1 y 20, ambos inclusives.");    
  }
}
