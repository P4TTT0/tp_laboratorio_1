/*
 * funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: patri
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Separador()
{
	printf("\n|-------------------------------------|\n");
}

void Clear()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void Error(char tipoError [], char mensaje [])
{
	printf("|--- ERROR (invalid %s) %s ---|\n\n", tipoError, mensaje);
}

void OpcionElegida(int opcionIngresada)
{
	printf("|---------- OPCION >%d< ----------|\n\n", opcionIngresada);
}

float ValidarNumero(char mensaje [], float numeroMin, float numeroMax)
{
	float kilometrosIngresados;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &kilometrosIngresados);

	while(kilometrosIngresados < numeroMin || kilometrosIngresados > numeroMax)
	{
		Error("number range", "INGRESE UN RANGO NUMERICO VALIDO");
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &kilometrosIngresados);
	}

	return kilometrosIngresados;
}

void SystemPause(char mensaje [])
{
	printf("%s", mensaje);
	system("pause");
	Clear();
}

float CalcularPrecioDebito(float precioBruto)
{
	int descuento;
	float precioDescuento;
	float precioFinal;

	descuento = 10;

	precioDescuento = precioBruto * descuento / 100;

	precioFinal = precioBruto - precioDescuento;

	return precioFinal;
}

float CalcularPrecioCredito(float precioBruto)
{
	int interes;
	float precioInteres;
	float precioFinal;

	interes = 25;

	precioInteres = precioBruto * interes / 100;

	precioFinal = precioBruto + precioInteres;

	return precioFinal;
}

float CalcularPrecioBitcoin(float precioBruto)
{
	float precioFinal;

	precioFinal = precioBruto / 4606954.55;

	return precioFinal;
}

float CalcularPrecioUnitario(float kilometros, float precioBruto)
{
	float precioFinal;

	precioFinal = precioBruto / kilometros;

	return precioFinal;
}

float CalcularDiferenciaPrecio(float precioBrutoUno, float precioBrutoDos)
{
	float diferenciaPrecio;

	if (precioBrutoUno > precioBrutoDos)
	{
		diferenciaPrecio = precioBrutoUno - precioBrutoDos;
	}
	else
	{
		diferenciaPrecio = precioBrutoDos - precioBrutoUno;
	}

	return diferenciaPrecio;
}

int InformarDatos(int opcion, float kilometros, float precioLatam, float debitoLatam, float creditoLatam, float bitcoinLatam, float unitarioLatam, float precioAerolineas, float debitoAerolineas, float creditoAerolineas, float bitcoinAerolineas, float unitarioAerolineas, float diferenciaPrecio)
{
	if (opcion == 0)
	{
		kilometros = 7090;
		precioAerolineas = 162965;
		precioLatam = 159339;

		//CALCULAR AEROLINEAS---------
		debitoAerolineas = CalcularPrecioDebito(precioAerolineas);
		creditoAerolineas = CalcularPrecioCredito(precioAerolineas);
		bitcoinAerolineas = CalcularPrecioBitcoin(precioAerolineas);
		unitarioAerolineas = CalcularPrecioUnitario(kilometros, precioAerolineas);

		//CALCULAR LATAM---------------
		debitoLatam = CalcularPrecioDebito(precioLatam);
		creditoLatam = CalcularPrecioCredito(precioLatam);
		bitcoinLatam = CalcularPrecioBitcoin(precioLatam);
		unitarioLatam = CalcularPrecioUnitario(kilometros, precioLatam);

		//DIFERENCIA DE PRECIOS----------
		diferenciaPrecio = CalcularDiferenciaPrecio(precioAerolineas, precioLatam);
	}
	Clear();
	printf("|----- RESULTADOS -----|\n\n");
	printf("|<--LATAM--> $%.2f\n", precioLatam);
	Separador();
	printf("\nPrecio con tarjeta de debito: $%.2f \n", debitoLatam);
	printf("Precio con tarjeta de credito: $%.2f \n", creditoLatam);
	printf("Precio pagando con bitcoin: $%.5f \n", bitcoinLatam);
	printf("Precio unitario: $%.2f \n", unitarioLatam);
	Separador();
	printf("\n|<--AEROLINEAS--> $%.2f\n", precioAerolineas);
	Separador();
	printf("\nPrecio con tarjeta de debito: $%.2f \n", debitoAerolineas);
	printf("Precio con tarjeta de credito: $%.2f \n", creditoAerolineas);
	printf("Precio pagando con bitcoin: $%.5f\n", bitcoinAerolineas);
	printf("Precio unitario: $%.2f\n", unitarioAerolineas);
	Separador();
	printf("\nLa diferencia de precio es: $%.2f\n", diferenciaPrecio);
	SystemPause("\n|----------> DATOS INFORMADOS <----------|\n");

	return opcion;
}

void AnimacionApagado(void)
{
	int i;
	int frames;

	frames = 5;

	for(i = 0; i < frames; i++)
	{
		switch(i)
		{
		case 1:
			Clear();
			printf("|>--                  <|");
			Sleep(500);
		break;
		case 2:
			Clear();
			printf("|>-----               <|");
			Sleep(500);
		break;
		case 3:
			Clear();
			printf("|>-----------         <|");
			Sleep(500);
		break;
		case 4:
			Clear();
			printf("|>-----------------   <|");
			Sleep(500);
		break;
		case 5:
			Clear();
			printf("|>--------------------<|");
			Sleep(500);
		break;
		}
	}
}



