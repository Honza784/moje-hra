s#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string hrac_jmeno;
string hrac_trida;
int hrac_zivoty;
int hrac_maxZivoty;
int hrac_mana;
int hrac_maxMana;
int hrac_zlato;
int hrac_utok;
int hrac_level;
int hrac_xp;

string nep1_jmeno;
int nep1_zivoty;
int nep1_utok;
int nep1_zlato;

int nahodne(int od, int do_)
{
	return od + rand() % (do_ - od + 1);
}

void zobrazHrace()
{
	cout << "--------------------\n";
	cout << hrac_jmeno << " [" << hrac_trida << "] Level " << hrac_level << "\n";
	cout << "HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
	cout << "Mana: " << hrac_mana << "/" << hrac_maxMana << "\n";
	cout << "Zlato: " << hrac_zlato << "\n";
	cout << "--------------------\n";
}

void nastavPaladina()
{
	hrac_trida = "Paladin";
	hrac_maxZivoty = 12;
	hrac_zivoty = 12;
	hrac_maxMana = 8;
	hrac_mana = 8;
	hrac_zlato = 10;
	hrac_utok = 4;
	hrac_level = 1;
	hrac_xp = 0;
}

void nastavLovce()
{
	hrac_trida = "Lovec";
	hrac_maxZivoty = 9;
	hrac_zivoty = 9;
	hrac_maxMana = 6;
	hrac_mana = 6;
	hrac_zlato = 15;
	hrac_utok = 5;
	hrac_level = 1;
	hrac_xp = 0;
}

void nastavMaga()
{
	hrac_trida = "Mag";
	hrac_maxZivoty = 7;
	hrac_zivoty = 7;
	hrac_maxMana = 14;
	hrac_mana = 14;
	hrac_zlato = 12;
	hrac_utok = 3;
	hrac_level = 1;
	hrac_xp = 0;
}

void nastavWarlocka()
{
	hrac_trida = "Warlock";
	hrac_maxZivoty = 8;
	hrac_zivoty = 8;
	hrac_maxMana = 10;
	hrac_mana = 10;
	hrac_zlato = 8;
	hrac_utok = 4;
	hrac_level = 1;
	hrac_xp = 0;
}

void vyberPostavu()
{
	cout << "Zadej jmeno: ";
	getline(cin, hrac_jmeno);

	cout << "Vyber classu:\n";
	cout << "1) Paladin\n2) Lovec\n3) Mag\n4) Warlock\n";
	cout << "Volba: ";
	int volba;
	cin >> volba;
	cin.ignore(10000, '\n');

	if (volba == 1)
		nastavPaladina();
	else if (volba == 2)
		nastavLovce();
	else if (volba == 3)
		nastavMaga();
	else if (volba == 4)
		nastavWarlocka();
	else
	{
		cout << "Spatna volba, davam Paladina.\n";
		nastavPaladina();
	}

	cout << "Vybral sis: " << hrac_trida << "\n";
}

void souboj()
{
	cout << "\nSouboj s " << nep1_jmeno << "!\n";
	cout << nep1_jmeno << " ma " << nep1_zivoty << " HP a utoci za " << nep1_utok << "\n";

	while (hrac_zivoty > 0 && nep1_zivoty > 0)
	{
		zobrazHrace();
		cout << nep1_jmeno << " HP: " << nep1_zivoty << "\n";

		cout << "Co udelat? 1) Utocit  2) Nic\nVolba: ";
		int akce;
		cin >> akce;
		cin.ignore(10000, '\n');

		if (akce == 1)
		{
			nep1_zivoty = nep1_zivoty - hrac_utok;
			cout << "Utocis za " << hrac_utok << "! " << nep1_jmeno << " ma ted " << nep1_zivoty << " HP\n";
		}

		if (nep1_zivoty > 0)
		{
			hrac_zivoty = hrac_zivoty - nep1_utok;
			cout << nep1_jmeno << " utoci za " << nep1_utok << "! Mas ted " << hrac_zivoty << " HP\n";
		}
	}

	if (hrac_zivoty <= 0)
	{
		cout << "Prohral jsi...\n";
	}
	else
	{
		cout << "Vyhral jsi!\n";
		if (nep1_zlato > 0)
		{
			hrac_zlato = hrac_zlato + nep1_zlato;
			cout << "Ziskal jsi " << nep1_zlato << " zlata!\n";
		}
	}
}

void vesnice()
{
	cout << "\n=== VESNICE ===\n";
	cout << "Mas " << hrac_zlato << " zlata.\n";
	cout << "1) Koupit zivoty (2 zlata za 1 HP)\n2) Odejit\nVolba: ";
	int v;
	cin >> v;
	cin.ignore(10000, '\n');

	if (v == 1)
	{
		if (hrac_zlato < 2)
		{
			cout << "Nemas dost zlata.\n";
		}
		else
		{
			int koupit = hrac_zlato / 2;
			int chybi = hrac_maxZivoty - hrac_zivoty;
			if (koupit > chybi)
				koupit = chybi;
			hrac_zivoty = hrac_zivoty + koupit;
			hrac_zlato = hrac_zlato - koupit * 2;
			cout << "Zivoty: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
		}
	}
}

int main()
{
	srand((unsigned int)time(0));

	cout << "=== RPG HRA ===\n";
	vyberPostavu();

	vesnice();

	nep1_jmeno = "Goblin";
	nep1_zivoty = 5;
	nep1_utok = 2;
	nep1_zlato = 3;

	souboj();

	return 0;
}
