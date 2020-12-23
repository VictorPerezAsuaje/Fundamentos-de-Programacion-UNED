/*

Se trata de realizar un programa que muestre por pantalla la hoja de calendario de cualquier mes y año comprendido entre los años 1601 y 3000. 
La hoja debe quedar ajustada a la izquierda de la pantalla y se deben emplear los caracteres ‘=’, ‘|’, ‘.’ y debe haber una línea en blanco 
antes de escribir la hoja del calendario.

El programa no deberá imprimir nada para los años fuera del rango de 1601 al 3000.
El programa debe pedir el mes y el año sólo una vez para cada ejecución.

*/

#include <stdio.h>

int DiaInicio(int valor_dia, int mes, int anno){

    /* ALGORITMO DE ZELLER MODIFICADO PARA ISO 8601 */

    int a = (14-mes)/12;
    int y = anno - a;
    int m = mes + 12*a - 2;

    int dia = (valor_dia + y + y/4 - y/100 + y/400 + (31*m)/12)%7; /* 0 = Domingo */

    dia = ((dia + 5)%7) + 1; /* 0 = Lunes */

    return dia;
}

bool EsBisiesto(int anno){

  bool bisiesto;

  if (anno%4 == 0 && (anno%100 != 0 || anno%400 == 0)){
        printf("Bisiesto \n");
        bisiesto = true;
  }
  else{
        printf("Normal \n");
        bisiesto = false;
  }

  return bisiesto;
}

int CabeceraYDiasMes(int mes, int anno, bool bisiesto){

  int dias_mes;


  switch(mes){
    case 1:
      printf("%s                  %d\n", "ENERO", anno);
      dias_mes = 31;
      break;
    case 2:
      printf("%s                %d\n", "FEBRERO", anno);
      if(bisiesto == true){
        dias_mes = 29;
      }
      else{
        dias_mes = 28;
      }
      break;
    case 3:
      printf("%s                  %d\n", "MARZO", anno);
      dias_mes = 31;
      break;
    case 4:
      printf("%s                  %d\n", "ABRIL", anno);
      dias_mes = 30;
      break;
    case 5:
      printf("%s                   %d\n", "MAYO", anno);
      dias_mes = 31;
      break;
    case 6:
      printf("%s                  %d\n", "JUNIO", anno);
      dias_mes = 30;
      break;
    case 7:
      printf("%s                  %d\n", "JULIO", anno);
      dias_mes = 31;
      break;
    case 8:
      printf("%s                 %d\n", "AGOSTO", anno);
      dias_mes = 31;
      break;
    case 9:
      printf("%s             %d\n", "SEPTIEMBRE", anno);
      dias_mes = 30;
      break;
    case 10:
      printf("%s                %d\n", "OCTUBRE", anno);
      dias_mes = 31;
      break;
    case 11:
      printf("%s              %d\n", "NOVIEMBRE", anno);
      dias_mes = 30;
      break;
    case 12:
      printf("%s              %d\n", "DICIEMBRE", anno);
      dias_mes = 31;
      break;
  }

  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");

  return dias_mes;
}

void PuntosPrevios(int dia){
  for(int i = 1; i < dia +1; i++){
      if(i==1){
        printf(" .");
      }
      else if(i == 5){
        printf("  .");
        printf("  |");
      }
      else if( i == 6){
        printf("  .");
      }
      else{
        printf("   .");
      }
    }
}

void ImprimirDias(int dias_mes, int dia_inicio, int mes, int anno){
    int dia;
    bool nueva_linea = false;

    for(int i = 1; i <= dias_mes + 1; i++){
            dia = (i + dia_inicio - 1)%7;

            if(i<10){                               /* Comienzan dias < 10 */
                if(dia == 1){
                    printf("   %d", i);
                }
                else if(nueva_linea == false){
                    if(dia == 4){
                        printf("   %d |", i);
                    }
                    else if(dia == 5){
                        printf("  %d", i);
                    }
                    else{
                        printf("   %d", i);
                    }
                }
                else if(nueva_linea == true){      /* nueva_linea == true */
                    printf(" %d", i);
                    nueva_linea = false;
                }
            }
            else if(i>=10 && i <= dias_mes){                                  /* Comienzan dias >= 10 */
                if(nueva_linea == false){
                    if(dia == 4){
                        printf("  %d |", i);
                    }
                    else if(dia == 5){
                        printf(" %d", i);
                    }
                    else{
                        printf("  %d", i);
                    }
                }
                else{
                    printf("%d", i);
                    nueva_linea = false;
                }
            }
            else if(DiaInicio(i, mes, anno)%7 != 0){
                dias_mes++;
                if((i + dia_inicio) %7 == 5){
                    printf("   .");
                    printf(" |");
                }
                else if((i + dia_inicio) %7 == 6){
                    printf("  .");
                }
                else{
                    printf("   .");
                }
            }


            if((i + dia_inicio) %7==0){
                printf("\n");
                nueva_linea = true;
            }
        }
}

int main () {
    /* VARIABLES */

    bool anno_bisiesto = false;
    bool error = true;
    int anno, mes, dia_inicio, dias_mes;

    /* TOMA DE DATOS */

    while(error == true){
        printf("¿Mes (1...12)? ");
        scanf("%d", &mes);

        printf("Año (1601...3000? \n");
        scanf("%d", &anno);

        if(mes>12 || mes<1){
            printf("El mes debe estar entre 1 y 12. Por favor, elija de nuevo.");
        }
        else if(anno>3000 || anno<1601){
            printf("El año elegido debe estar entre 1601 y 3000. Por favor, elija de nuevo.");
        }
        else{
            error = false;
        }

        printf("\n");
    }

    printf("Elegidos mes: %d y año: %d \n", mes, anno);

    /* ¿BISIESTO? */

   anno_bisiesto = EsBisiesto(anno);

    /* CABECERA CALENDARIO */

    dias_mes = CabeceraYDiasMes(mes, anno, anno_bisiesto);

    dia_inicio = DiaInicio(1, mes, anno);

    /* PUNTOS PREVIOS */

    PuntosPrevios(dia_inicio);

    /* IMPRIMIR DIAS */

    ImprimirDias(dias_mes, dia_inicio, mes, anno);

}
