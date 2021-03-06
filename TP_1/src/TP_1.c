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
#include <windows.h>
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

	//VARIABLE PARA GUARDAR OPCION---
	int opcionIngresada;
	//VARIABLE PARA GUARDAR VUELO INGRESADO---
	int vueloIngresado;

	//VARIABLE PARA GUARDAR KILOMETROS---
	float x;
	//VARIABLE PARA GUARDAR PRECIO AEROLINEA---
	float y;
	//VARIABLE PARA GUARDAR PRECIO LATAM---
	float z;

	//BANDERA PARA VERIFICAR SI LOS DATOS HAN SIDO CARGADOS---
	int banderaDatosCargados;

	//VARIABLES PARA GUARDAR DATOS DE AEROLINEAS-----
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;

	//VARIABLES PARA GUARDAR DATOS DE LATAM------
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;

	//VARIABLE PARA GUARDAR DIFERENCIA DE PRECIOS-----
	float precioDiferencia;

	x = 0;
	y = 0;
	z = 0;

	banderaDatosCargados = 0;

	precioDebitoAerolineas = 0;
	precioCreditoAerolineas = 0;
	precioBitcoinAerolineas = 0;
	precioUnitarioAerolineas = 0;

	precioDebitoLatam = 0;
	precioCreditoLatam = 0;
	precioBitcoinLatam = 0;
	precioUnitarioLatam = 0;

	precioDiferencia = 0;

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

				y = ValidarNumero("Ingrese el precio de AEROLINEAS: ", 1000, 100000);
				SystemPause("\n|---------- DATOS CARGADOS ----------|\n");
			break;
			case 2:
				OpcionElegida(vueloIngresado);
				fflush(stdin);
				z = ValidarNumero("Ingrese el precio de LATAM: ", 500, 50000);
				SystemPause("\n|---------- DATOS CARGADOS ----------|\n");
			break;
			default:
				Error("option", "INGRESE UNA OPCION VALIDA");
				Separador();
				printf("\nIngrese opcion:");
				fflush(stdin);
				scanf("%d", &vueloIngresado);
			break;
			}
		break;

		case 3:
			if (x == 0 || y == 0 || z == 0)
			{
				Error("option", "FALTAN CARGAR DATOS");
				SystemPause("\n|----------> COMPLETE LOS DATOS <----------|\n");
			}
			else
			{
				//CALCULAR AEROLINEAS---------
				precioDebitoAerolineas = CalcularPrecioDebito(y);
				precioCreditoAerolineas = CalcularPrecioCredito(y);
				precioBitcoinAerolineas = CalcularPrecioBitcoin(y);
				precioUnitarioAerolineas = CalcularPrecioUnitario(x, y);

				//CALCULAR LATAM---------------
				precioDebitoLatam = CalcularPrecioDebito(z);
				precioCreditoLatam = CalcularPrecioCredito(z);
				precioBitcoinLatam = CalcularPrecioBitcoin(z);
				precioUnitarioLatam = CalcularPrecioUnitario(x, z);

				//DIFERENCIA DE PRECIOS----------
				precioDiferencia = CalcularDiferenciaPrecio(y, z);

				//BANDERA DE DATOS CARGADOS-----------
				banderaDatosCargados = 1;

				//MENSAJE DE CONFIRMACION---------
				Clear();
				SystemPause("\n|---------- DATOS CALCULADOS ----------|\n");
			}
		break;

		case 4:
			if (banderaDatosCargados == 0)
			{
				Clear();
				Error("option","FALTA CARGAR DATOS");
				SystemPause("\n|----------> COMPLETE LOS DATOS <----------|\n");
			}
			else
			{
				InformarDatos(1, x, z, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, y, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, precioDiferencia);
			}
		break;

		case 5:
			InformarDatos(0, x, z, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, y, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, precioDiferencia);
		break;

		case 6:
			Clear();
			printf("|---- CERRANDO SISTEMA ----|");
			Sleep(500);
		break;
		default:
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
		break;
		}

	}while(opcionIngresada != 6);

	Clear();
	AnimacionApagado();
	Clear();
	printf("\n|---- SISTEMA APAGADO ----|");
}
