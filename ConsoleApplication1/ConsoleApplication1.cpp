#include <iostream>
#include <stdio.h>

int Cant_dias_disponible(int lanchas[][31], int, int);
int Dia_mas_pasajeros(int lanchas[][31], int, int);
int hubo_servicio(int lanchas[][31], int, int);
void Mostrar_Pasajeros(int lanchas[][31], int, int, int);
void promedioempresa(int lanchas[][31], int);



int main() {
    int c, cl;
    int lanchas[6][31];

    //Ejercicio A
    FILE* fp; // abro el archivo y guardo los datos en mi matriz "lancha"

    fp = fopen("LanchasMarzo2020.dat", "rb");

    if (fp == NULL)
    {
        perror("Error al abrir el archivo");
        return(-1);
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            c = fread(&lanchas[i][j], sizeof(lanchas[i][j]), 1, fp);
            if (c != 1)
            {
                perror("Error al leer el archivo");
                return (-2);
            }
        }

    }
    cl = fclose(fp);
    if (cl != 0)
    {
        perror("Error al cerrar el archivo");
        return(-3);
    }

    //quiero ver que el array lanchas[6][31] quedo bien guardado
    /*
        for (int j=0;j<31;j++)
        {
        printf("%d,", lanchas[0][j]);
        }
        printf("\n");
       for (int j=0;j<31;j++)
        {
        printf("%d,", lanchas[1][j]);
        }
        printf("\n");
       for (int j=0;j<31;j++)
        {
        printf("%d,", lanchas[2][j]);
        }
        printf("\n");
       for (int j=0;j<31;j++)
        {
        printf("%d,", lanchas[3][j]);
        }

        printf("\n");

        for (int j=0;j<31;j++)
        {
        printf("%d,", lanchas[4][j]);
        }

        printf("\n");

        for (int j=0;j<31;j++)
        {
        printf("%d,", lanchas[5][j]);
        }
    */
    //chequeo que la mayoría de valores esta bien (hay algunos que son dif que son muy pocos => asumo que la matriz esta correctamente leida) => los valores estan bien

    //---------------------------------------------------------
    //Ejercicio B
    printf("\n");

    int opcion, dia_inicio, dia_fin, dia, empresa, desde, hasta, Empresa, empresaa;
    int resultado1 = 0, resultado2 = 0, servicio = 0;
    while (opcion != 6)//menu interactivo que se reinicia sin necesidad de correr nuevamente el codigo
    {
        printf("\n1-Cantidad de días que hubo servicio durante un rango de días\n");
        printf("2-Día con más pasajeros\n");
        printf("3-Hubo Servicio\n");
        printf("4-Mostrar Pasajeros de empresa\n");
        printf("5-Promedio de pasajeros diarios por una empresa\n");
        printf("6-Salir \n ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1: //dias que hubo servicio en un rango de dias

            printf("Ingresar el dia de Inicio:\n");
            scanf("%d", &dia_inicio);
            if (dia_inicio < 0 || dia_inicio>31)
            {
                printf("Dia erroneo, Ingrese otro dia");
                printf("Ingresar el dia de Inicio:\n");
                scanf("%d", &dia_inicio);
            }

            printf("Ingresar el dia de Fin:\n");
            scanf("%d", &dia_fin);

            if (dia_fin < 0 || dia_fin>31)
            {
                printf("Dia erroneo, Ingrese otro dia");
                printf("Ingresar el dia de Fin:\n");
                scanf("%d", &dia_fin);
            }

            resultado1 = Cant_dias_disponible(lanchas, dia_inicio, dia_fin);
            printf("La cantidad de viajes (todas las empresas) realizados en ese rango es %d\n", resultado1);

            break;

        case 2:
            printf("Ingresar el dia de Inicio:\n");
            scanf("%d", &dia_inicio);
            if (dia_inicio < 0 || dia_inicio>31)
            {
                printf("Dia erroneo, Ingrese otro dia");
                printf("Ingresar el dia de Inicio:\n");
                scanf("%d", &dia_inicio);
            }

            printf("Ingresar el dia de Fin:\n");
            scanf("%d", &dia_fin);

            if (dia_fin < 0 || dia_fin>31)
            {
                printf("Dia erroneo, Ingrese otro dia");
                printf("Ingresar el dia de Fin:\n");
                scanf("%d", &dia_fin);
            }

            resultado2 = Dia_mas_pasajeros(lanchas, dia_inicio, dia_fin); //valor del maximo 
            break;

        case 3: //hubo servicio
            printf("Ingresar el dia:\n");
            scanf("%d", &dia);


            printf("Seleccione una empresa:\n");
            scanf("%d", &empresa);

            servicio = hubo_servicio(lanchas, dia, empresa);

            break;

        case 4: //mostrar pasajeros de empresa
            printf("Ingresar el dia de Inicio:\n");
            scanf("%d", &desde);
            if (desde < 0 || desde>31)
            {
                printf("Dia erroneo, Ingrese otro dia");
                printf("Ingresar el dia de Inicio:\n");
                scanf("%d", &desde);
            }

            printf("Ingresar el dia de Fin:\n");
            scanf("%d", &hasta);

            if (hasta < 0 || hasta>31)
            {
                printf("Dia erroneo, Ingrese otro dia");
                printf("Ingresar el dia de Fin:\n");
                scanf("%d", &hasta);
            }

            printf("Seleccione una empresa:\n");
            scanf("%d", &Empresa);

            Mostrar_Pasajeros(lanchas, desde, hasta, Empresa);

            break;

        case 5://promedio de pasajeros diarios por empresa

            promedioempresa(lanchas, empresaa);
            break;

        case 6://Salir
            break;

        }
    }

    return 0;
}


int Cant_dias_disponible(int lanchas[][31], int dia_inicio, int dia_fin)
{
    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0, disponibles1 = 0, disponibles2 = 0; //los contadores son los dias disponibles por empresa en ese rango de dias

    for (int j = (dia_inicio - 1); j < (dia_fin - 1); j++)
    {
        if (lanchas[0][j] != (-1))
        {
            cont1++;//el cont1 te da todos los dias disponibles en la empresa 1 en ese rango
        }
    }

    for (int j = (dia_inicio - 1); j < (dia_fin - 1); j++)
    {
        if (lanchas[1][j] != (-1))
        {
            cont2++;//el cont2 te da todos los dias disponibles en la empresa 2 en ese rango

        }
    }


    for (int j = (dia_inicio - 1); j < (dia_fin - 1); j++)
    {
        if (lanchas[2][j] != (-1))
        {
            cont3++;//el cont3 te da todos los dias disponibles en la empresa 3 en ese rango
        }
    }


    for (int j = (dia_inicio - 1); j < (dia_fin - 1); j++)
    {
        if (lanchas[3][j] != (-1))
        {
            cont4++;//el cont4 te da todos los dias disponibles en la empresa 4 en ese rango
        }
    }



    for (int j = (dia_inicio - 1); j < (dia_fin - 1); j++)
    {
        if (lanchas[4][j] != (-1))
        {
            cont5++;//el cont5 te da todos los dias disponibles en la empresa 5 en ese rango
        }
    }


    for (int j = (dia_inicio - 1); j < (dia_fin - 1); j++)
    {
        if (lanchas[5][j] != (-1))
        {
            cont6++;//el cont6 te da todos los dias disponibles en la empresa 6 en ese rango
        }
    }

    printf("La empresa 1 tuvo %d dias disponibles\n", cont1);
    printf("La empresa 2 tuvo %d dias disponibles\n", cont2);
    printf("La empresa 3 tuvo %d dias disponibles\n", cont3);
    printf("La empresa 4 tuvo %d dias disponibles\n", cont4);
    printf("La empresa 5 tuvo %d dias disponibles\n", cont5);
    printf("La empresa 6 tuvo %d dias disponibles\n", cont6);

    disponibles1 = cont1 + cont2 + cont3 + cont4 + cont5 + cont6;

    /* Esta es otra manera en la que lo pense
      for (int i=0;i<6;i++)
      {
          for (int j=(dia_inicio-1);j<(dia_fin-1);j++)
          {
            if (lanchas[i][j] != (-1))
            {
              disponibles2++;
            }
          }
      }
      printf("Disponibles2=%d", disponibles2);
      */
    return disponibles1;
}


int Dia_mas_pasajeros(int lanchas[][31], int dia_inicio, int dia_fin)
{
    int aux1 = 0, max = 0, dia = 0, empresa = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = (dia_inicio - 1); j < (dia_fin - 1); j++)
        {
            aux1 = lanchas[i][j];
            if (aux1 > max)
            {
                max = aux1;
                dia = j + 1;
                empresa = i + 1;
            }
        }
    }

    printf("El dia %d se registro un max de %d personas viajando en la empresa %d\n", dia, max, empresa);

    return max;
}

int hubo_servicio(int lanchas[][31], int dia, int empresa)
{
    int viajes;

    if (lanchas[empresa - 1][dia - 1] != (-1))
    {
        viajes = lanchas[empresa - 1][dia - 1];
        printf("El dia %d hubo servicio en la empresa %d y se registraron %d viajes", dia, empresa, viajes);
    }
    else
    {
        viajes = 0;
        printf("El dia %d no hubo servicio en la empresa %d", dia, empresa);
    }

    return viajes;
}

void Mostrar_Pasajeros(int lanchas[][31], int desde, int hasta, int Empresa)
{

    for (int j = (desde - 1); j < (hasta - 1); j++)
    {
        if (lanchas[Empresa - 1][j] != (-1))
        {
            printf("Cantidad de pasajeros %d, dia %d\n", lanchas[Empresa - 1][j], j + 1);
        }
        else
            printf("No hubo servicio el dia %d y la cantidad de pasajeros fue 0\n", j + 1);

    }

}



void promedioempresa(int lanchas[][31], int empresaa) //si es el promedio diario es un valor
{
    int cont1 = 0, cont2 = 0, prom = 0;

    for (int j = 0; j < 31; j++)
    {
        if (lanchas[empresaa - 1][j] != (-1))
        {
            cont1 = cont1 + lanchas[empresaa - 1][j];
            cont2++;
        }
    }

    prom = (cont1 / cont2);

    char empresa_str[10];
    char archivo[30] = "promedioEmpresa";
    sprintf(empresa_str, "%d", empresaa);
    //strcat(archivo,empresa_str); 
    //strcat(archivo,".dat");
    printf("\n %s \n", archivo);
} //no llegue con el tiempo a completar el punto 5

