/*
 ============================================================================
 Name        : TP_1.c
 Author      : Perez Cardenal Patricio
 Version     :
 Copyright   : TTT
 Description : TP_1 GITHUB
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h" //Incluir la bibloteca creada con ("")

void MenuPrincipal();

int main(void)
{
	setbuf(stdout, NULL);


	MenuPrincipal();

	return EXIT_SUCCESS;
}

void MenuPrincipal()
{
	setbuf(stdout, NULL);

	int opcionIngresada;
	float x;
	int vueloIngresado;
	float y;
	float z;

	do
	{
		printf("|----- > Seleccione una opcion < -----|\n\n");
		printf("\n1-| Ingresar KM |->");
		printf("\n2-| Ingresar precio de vuelvos |->");
		printf("\n3-| Calcular costos |->");
		printf("\n4-| Informar resultados |->");
		printf("\n5-| Carga forzada de datos |->");
		printf("\n6-| SALIR |->\n");

		Separador();

		printf("\nIngrese opcion:");
		fflush(stdin);
		scanf("%d", &opcionIngresada);

		while(opcionIngresada < 1 || opcionIngresada > 6)
		{
			Clear();
			Error("option", "INGRESE UNA OPCION VALIDA");

			printf("|----- > Seleccione una opcion < -----|\n\n");
			printf("\n1-| Ingresar KM |->");
			printf("\n2-| Ingresar precio de vuelvos |->");
			printf("\n3-| Calcular costos |->");
			printf("\n4-| Informar resultados |->");
			printf("\n5-| Carga forzada de datos |->");
			printf("\n6-| SALIR |->\n");

			Separador();

			printf("\nIngrese opcion:");
			fflush(stdin);
			scanf("%d", &opcionIngresada);
		}

		switch(opcionIngresada)
		{
		case 1:
			Clear();
			OpcionElegida(opcionIngresada);
			x = ValidarNumero("Ingrese los KM del viaje: ", 3, 21602);
			SystemPause("\n|---------- DATOS CARGADOS ----------|\n");
		break;

		case 2:
			Clear();
			OpcionElegida(opcionIngresada);
			printf("Seleccione un VUELO: \n 1 - Precio vuelo AEROLINEAS\n 2 - Precio vuelo LATAM\n");
			Separador();
			printf("\nIngrese opcion:");
			fflush(stdin);
			scanf("%d", &vueloIngresado);

			while(vueloIngresado < 1 || vueloIngresado > 2)
			{
				Clear();
				Error("option", "INGRESE UNA OPCION VALIDA");
				OpcionElegida(opcionIngresada);
				printf("Seleccione un VUELO: \n 1 - Precio vuelo AEROLINEAS\n 2 - Precio vuelo LATAM\n");
				Separador();
				printf("\nIngrese opcion:");
				fflush(stdin);
				scanf("%d", &vueloIngresado);
			}

			switch(vueloIngresado)
			{
			case 1:
				OpcionElegida(vueloIngresado);
				x = ValidarNumero("Ingrese el precio de AEROLINEAS: ", 1000, 100000);
				SystemPause("\n|---------- DATOS CARGADOS ----------|\n");
			break;
			case 2:
				OpcionElegida(vueloIngresado);
				z = ValidarNumero("Ingrese el precio de LATAM: ", 500, 50000);
				SystemPause("\n|---------- DATOS CARGADOS ----------|\n");
			break;
			default:
				Error("option", "INGRESE UNA OPCION VALIDA");
				Separador();
				printf("\nIngrese opcion:");
				scanf("%d", &vueloIngresado);
			break;
			}
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
		break;
		case 6:
		break;
		default:
		break;
		}

	}while(opcionIngresada != 6);
}
