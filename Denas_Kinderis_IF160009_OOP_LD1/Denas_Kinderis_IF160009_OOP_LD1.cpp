/*--------------------------------------------------------------
|  Autorius:  Denas Kinderis,  IF160009,  1  kursas |
|  Uzduoti  gavau:  2017.01.01                      |
|  Uzduoties  algoritma  galvojau: x  valandu       |
|  Programa  rasiau: x  valandas                    |
|  Paskutines  redakcijos  data:  2009.___.___.     |
|  Versija  Nr.nn                                   |
----------------------------------------------------------------*/

//----------Bibliotekos-------------------
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include <string>
//----------------------------------------
using namespace std;
struct AUTO
{
	int nr, metai, kw, sanaudosmieste, sanaudosuzmiesty;
	string numeriai, marke, spalva, tipas, modelis;
};
//----------------------------------------
void spalva();
void pradzia();
void skaitymas();
void kaina();
void salinimas();
void papildymas();
void rykiavimas();
void eilute();
void autoeilute();
void grazusspausdinimas(AUTO a, bool);
void skyriamoji();
void meniu();
void darbopabaiga();
void meniu2(AUTO a[]);
//----------------------------------------
string name;

int masinuskaicius;
//----------------------------------------
int main()
{
	pradzia();
	meniu();
	system("pause");
	return 0;
}
void pradzia()
{
	//---------------------------------------------------------------------------------------------------
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);           //grazus pasisveikinimas
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);

	cout << "|" << setfill('=') << setw(79) << "|" << endl;
	cout << setfill(' ') << setw(45) << "Sveiki" << endl;
	cout << "\n" << setfill(' ') << setw(57) << "Darba atiliko - Denas Kinderis" << endl;
	cout << "\n" << setfill(' ') << setw(55) << "Studento numeris - if160009" << endl;
	cout << "\n|" << setfill('=') << setw(79) << "|" << endl;
	cout << "" << endl;
	SetConsoleTextAttribute(hConsole, saved_attributes);            //grazaus pasisveikinimo pabaiga
																	//---------------------------------------------------------------------------------------------------
	cout << "\nSveiki, siekdami supaprastinti programos naudojima,\npateiksime jums programos meniu,\nkuriuo galesite naudotis visu programos veikimo periodu. " << endl;
}
void skaitymas()
{
	AUTO a[8];
	cout << "\nIveskite failo pavadinima: ";
	cin >> name;
	ifstream file(name);
	if (!file)
	{
		cout << "Neteisingai ivedete failo pavadinima" << endl;
		system("pause");
	}
	else
	{
		cout << endl << "Skaitoma..." << endl << endl;
		int i = 0;

		while (!file.eof())
		{
			file >> a[i].nr;
			file >> a[i].numeriai;
			file >> a[i].marke;
			file >> a[i].spalva;
			file >> a[i].metai;
			file >> a[i].tipas;
			file >> a[i].kw;
			file >> a[i].sanaudosmieste;
			file >> a[i].sanaudosuzmiesty;
			file >> a[i].modelis;
			i++;
			grazusspausdinimas(a[i], i == 0);
		}
		masinuskaicius = i;
	}
	file.close();
	cout << ("\n\n||||||||||||||||  Skaitymas baigtas!  ||||||||||||||||");
	meniu2(a);
}
void spalva()
{
	string spalva1;


	cout << "Iveskite norima spalva: ";
	cin >> spalva1;
	cout << "\nJusu pasirinkta spalva: " << spalva1 << ". \n\nToliau matysite sarasa masinu, kuriuos atitinka butent sia spalva." << endl << endl;
	skyriamoji();
	for (int i = 0; i <= masinuskaicius; i++)
	{
		if (spalva1 == a[i].spalva)
		{
			cout << "Eil.nr --------- " << a[i].nr << endl;
			cout << " Valstybinis numeris: " << a[i].numeriai << endl;
			cout << " Automobilio marke: " << a[i].marke << endl;
			cout << " Pagaminimo metai: " << a[i].spalva << endl;
			cout << " Automobilio spalva: " << a[i].metai << endl;
			cout << " Kuro tipas: " << a[i].tipas << endl;
			cout << " Automobilio galia: " << a[i].kw << endl;
			cout << " Kuro sanaudos mieste: " << a[i].sanaudosmieste << endl;
			cout << " Kuro sanaudos uzmiestyje: " << a[i].sanaudosuzmiesty << endl;
			cout << " Kebulo tipas: " << a[i].modelis << endl;
		}


	}
	meniu2();
}
void kaina()
{
	float  kwkaina, benzkaina, dyzelkaina, dujoskaina;
	cout << "Prasome iveskite papildoma informacija: " << endl;
	cout << "\nIveskite kiek kainuos 1 kilovatwalande: ";
	cin >> kwkaina;
	cout << "\nIveskite kiek kainuoja benzino 1 l: ";
	cin >> benzkaina;
	cout << "\nIveskite kiek kainuoja dyzelio 1 l: ";
	cin >> dyzelkaina;
	cout << "\nIveskite kiek kainuoja duju 1 kubinis l: ";
	cin >> dujoskaina;
	cout << endl;

	for (int i = 0; i <= masinuskaicius; i++)
	{
		if (a[i].tipas == "benzinas")
		{
			cout << "Eil.nr --------- " << a[i].nr << endl;
			cout << " Automobilio marke: " << a[i].marke << endl;
			cout << " Kuro tipas: " << a[i].tipas << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "| Kiek kainuos mieste nuvaziuoti 1000km " << a[i].sanaudosmieste * 10 * benzkaina << " Eur. |" << endl;
			cout << "| Kiek kainuos uzmiestyje nuvaziuoti 1000km " << a[i].sanaudosuzmiesty * 10 * benzkaina << " Eur. |" << endl;
			cout << "-------------------------------------------------" << endl;
		}
		if (a[i].tipas == "dyzelinas")
		{
			cout << "Eil.nr --------- " << a[i].nr << endl;
			cout << " Automobilio marke: " << a[i].marke << endl;
			cout << " Kuro tipas: " << a[i].tipas << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "| Kiek kainuos mieste nuvaziuoti 1000km " << a[i].sanaudosmieste * 10 * benzkaina << " Eur. |" << endl;
			cout << "| Kiek kainuos uzmiestyje nuvaziuoti 1000km " << a[i].sanaudosuzmiesty * 10 * benzkaina << " Eur. |" << endl;
			cout << "-------------------------------------------------" << endl;
		}
		if (a[i].tipas == "dujos")
		{
			cout << "Eil.nr --------- " << a[i].nr << endl;
			cout << " Automobilio marke: " << a[i].marke << endl;
			cout << " Kuro tipas: " << a[i].tipas << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "| Kiek kainuos mieste nuvaziuoti 1000km " << a[i].sanaudosmieste * 10 * benzkaina << " Eur. |" << endl;
			cout << "| Kiek kainuos uzmiestyje nuvaziuoti 1000km " << a[i].sanaudosuzmiesty * 10 * benzkaina << " Eur. |" << endl;
			cout << "-------------------------------------------------" << endl;
		}
		if (a[i].tipas == "elektra")
		{
			cout << "Eil.nr --------- " << a[i].nr << endl;
			cout << " Automobilio marke: " << a[i].marke << endl;
			cout << " Kuro tipas: " << a[i].tipas << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "| Kiek kainuos mieste nuvaziuoti 1000km " << a[i].sanaudosmieste * 10 * benzkaina << " Eur. |" << endl;
			cout << "| Kiek kainuos uzmiestyje nuvaziuoti 1000km " << a[i].sanaudosuzmiesty * 10 * benzkaina << " Eur. |" << endl;
			cout << "-------------------------------------------------" << endl;
		}
	}
	meniu2();
}
void salinimas()
{
	int dmetai, laikinasmasinuskaicius, nmetai;
	laikinasmasinuskaicius = masinuskaicius;
	skyriamoji();

	cout << "Iveskite dabartinius metus: ";
	cin >> dmetai;
	cout << "\nNurodykite kokio senumo masinu nenoretumete matyti" << endl;
	cin >> nmetai;

	for (int i = 0; i < laikinasmasinuskaicius; i++)
	{
		if ((dmetai - a[i].metai) >= nmetai)
		{
			for (int j = i; j < laikinasmasinuskaicius; j++)
			{
				a[j] = a[j + 1];
			}
			i--;
			laikinasmasinuskaicius--;
		}
		grazusspausdinimas(a[i], i == 0);
	}
	meniu2();
}
void papildymas()
{
	skyriamoji();
	for (int i = 0; i < masinuskaicius; i++)
	{
		cout << "iveskite masinos valstybini numeri";
		cin >> a[masinuskaicius + 1].numeriai;
		cout << " Automobilio marke: ";
		cin >> a[masinuskaicius + 1].marke;
		cout << " Pagaminimo metai: ";
		cin >> a[masinuskaicius + 1].metai;
		cout << " Automobilio spalva: ";
		cin >> a[masinuskaicius + 1].spalva;
		cout << " Kuro tipas: ";
		cin >> a[masinuskaicius + 1].tipas;
		cout << " Automobilio galia: ";
		cin >> a[masinuskaicius + 1].kw;
		cout << " Kuro sanaudos mieste: ";
		cin >> a[masinuskaicius + 1].sanaudosmieste;
		cout << " Kuro sanaudos uzmiestyje: ";
		cin >> a[masinuskaicius + 1].sanaudosuzmiesty;
		cout << " Kebulo tipas: ";
		cin >> a[masinuskaicius + 1].tipas;

		//grazusspausdinimas(a[i], i == 0);
	}
	masinuskaicius++;
	meniu2();
}
void rykiavimas()
{
	AUTO maximum;
	for (int i = 0; i < masinuskaicius; i++)
	{
		for (int j = 0; j < masinuskaicius; j++)
		{
			if (a[j].metai < a[i].metai)
			{
				maximum = a[j];
				a[j] = a[i];
				a[i] = maximum;
			}
		}
	}
	for (int i = 0; i < masinuskaicius; i++)
	{
		
		cout << " --------------AUTO---------------\n";
		cout << "Eil.nr --------- " << a[i].nr << endl;
		cout << " Valstybinis numeris: " << a[i].numeriai << endl;
		cout << " Automobilio marke: " << a[i].marke << endl;
		cout << " Pagaminimo metai: " << a[i].spalva << endl;
		cout << " Automobilio spalva: " << a[i].metai << endl;
		cout << " Kuro tipas: " << a[i].tipas << endl;
		cout << " Automobilio galia: " << a[i].kw << endl;
		cout << " Kuro sanaudos mieste: " << a[i].sanaudosmieste << endl;
		cout << " Kuro sanaudos uzmiestyje: " << a[i].sanaudosuzmiesty << endl;
		cout << " Kebulo tipas: " << a[i].modelis << endl;
		
		grazusspausdinimas(a[i], i == 0);
	}
	meniu2();
}
void eilute()
{
	cout << " |" << setfill('-') << setw(60) << internal << "|" << endl;
}
void autoeilute()
{
	cout << " |" << setfill(' ') << setw(30) << internal << " AUTO " << setw(30) << "|" << endl;
}
void grazusspausdinimas(AUTO z, bool arPirmaEilute = false)
{
	if (arPirmaEilute) {
		eilute();
		autoeilute();
		eilute();
	}
	cout << " |" << setfill(' ') << " Eil.nr: " << setw(50) << left << z.nr << "|" << endl;
	cout << " |" << setfill(' ') << " Valstybinis numeris: " << setw(37) << z.numeriai << "|" << endl;
	cout << " |" << setfill(' ') << " Automobilio marke: " << setw(39) << z.marke << "|" << endl;
	cout << " |" << setfill(' ') << " Automobilio spalva: " << setw(38) << z.spalva << "|" << endl;
	cout << " |" << setfill(' ') << " Automobilio metai: " << setw(39) << z.metai << "|" << endl;
	cout << " |" << setfill(' ') << " Kuro tipas: " << setw(46) << z.tipas << "|" << endl;
	cout << " |" << setfill(' ') << " Automobilio galia: " << setw(39) << z.kw << "|" << endl;
	cout << " |" << setfill(' ') << " Kuro sanaudos mieste: " << setw(36) << z.sanaudosmieste << "|" << endl;
	cout << " |" << setfill(' ') << " Kuro sanaudos uzmiestyje: " << setw(32) << z.sanaudosuzmiesty << "|" << endl;
	cout << " |" << setfill(' ') << " Kebulo tipas: " << setw(44) << z.modelis << "|" << endl;
	eilute();
	system("pause");
}
void skyriamoji()
{
	cout << endl << endl << "==============================================================" << endl << endl;
}
void meniu()
{
	skyriamoji();
	int p1;
	eilute();
	cout << " |" << setfill(' ') << setw(30) << internal << " MENIU " << setw(30) << "|" << endl;
	cout << " |" << setfill(' ') << "Noredami nuskaityti duomeninis, spauskite - 1" << setw(15) << "|" << endl;
	cout << " |" << setfill(' ') << "Noredami baigti darba, spauskite - 2" << setw(24) << "|" << endl;
	eilute();
	cout << endl << "Iveskite norima pasirinkima: ";
	cin >> p1; cout << endl;
	eilute();
	cout << " |" << setfill(' ') << "Jusu pasirinkote: " << p1 << setw(41) << "|" << endl;
	eilute();
	if (p1 == 1)
	{
		skaitymas();
	}
	if (p1 == 2)
	{
		darbopabaiga();
	}
}
void meniu2(AUTO a[8])
{
	int p1;
	skyriamoji();
	eilute();
	cout << " |" << setfill(' ') << setw(30) << internal << " MENIU " << setw(30) << "|" << endl;
	eilute();
	cout << " |" << setfill(' ') << "Noredami papildyti duomenis, spauskite - 1" << setw(18) << "|" << endl;
	cout << " |" << setfill(' ') << "Noredami pasalinti senas masinas, spauskite - 2" << setw(13) << "|" << endl;
	cout << " |" << setfill(' ') << "Noredami atskirti masinas pagal spalva, spauskite - 3" << setw(7) << "|" << endl;
	cout << " |" << setfill(' ') << "Noredami zinoti masinu sanaudas, spauskite - 4" << setw(14) << "|" << endl;
	cout << " |" << setfill(' ') << "Noredami matyti masinas pagal ju metus, spauskite - 5" << setw(7) << "|" << endl;
	cout << " |" << setfill(' ') << "Noredami baigti darba, spauskite - 6" << setw(24) << "|" << endl;
	eilute();
	cout << endl << "Iveskite norima pasirinkima: ";
	cin >> p1; cout << endl;
	eilute();
	cout << " |" << setfill(' ') << "Jusu pasirinkote: " << p1 << setw(41) << "|" << endl;
	eilute(); cout << endl;
	if (p1 == 1)
	{
		papildymas(a);
	}
	if (p1 == 2)
	{
		salinimas();
	}
	if (p1 == 3)
	{
		spalva();
	}
	if (p1 == 4)
	{
		kaina();
	}
	if (p1 == 5)
	{
		rykiavimas();
	}
	if (p1 == 6)
	{
		darbopabaiga();
	}
}
void darbopabaiga()
{
	skyriamoji();
	eilute();
	cout << " |" << setfill(' ') << "Jusu pasirinkimu, programa issijungia..." << setw(13) << "|" << endl;
	cout << " |" << setfill(' ') << "Programa baige darba sekmingai!" << setw(29) << "|" << endl;
	eilute();
}