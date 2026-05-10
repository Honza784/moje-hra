#include <iostream>
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
int hrac_xpDoLevelup;
 
string schopnost1_nazev;
string schopnost1_popis;
int schopnost1_poskozeni;
bool schopnost1_vsichni;
int schopnost1_heal;
int schopnost1_mana;
 
string schopnost2_nazev;
string schopnost2_popis;
int schopnost2_poskozeni;
bool schopnost2_vsichni;
int schopnost2_heal;
int schopnost2_mana;
 
string schopnost3_nazev;
string schopnost3_popis;
int schopnost3_poskozeni;
bool schopnost3_vsichni;
int schopnost3_heal;
int schopnost3_mana;
 
string nep1_jmeno;
int nep1_zivoty;
int nep1_maxZivoty;
int nep1_utok;
int nep1_zlato;
int nep1_xp;
int nep1_typ;
string nep1_hlaska1;
string nep1_hlaska2;
bool nep1_omracen;
 
string nep2_jmeno;
int nep2_zivoty;
int nep2_maxZivoty;
int nep2_utok;
int nep2_zlato;
int nep2_xp;
int nep2_typ;
string nep2_hlaska1;
string nep2_hlaska2;
bool nep2_omracen;
 
int pocetNepriatel;
 
int nahodne(int od, int do_)
{
	return od + rand() % (do_ - od + 1);
}
 
bool sance(int procent)
{
	if (nahodne(1, 100) <= procent)
		return true;
	return false;
}
 
void enter()
{
	cout << "\n[ENTER pro pokracovani...]";
	cin.ignore(10000, '\n');
}
 
void zobrazHrace()
{
	cout << "--------------------\n";
	cout << hrac_jmeno << " [" << hrac_trida << "] Level " << hrac_level << "\n";
	cout << "HP: " << hrac_zivoty << "/" << hrac_maxZivoty;
	cout << "  Mana: " << hrac_mana << "/" << hrac_maxMana;
	cout << "  Zlato: " << hrac_zlato << "\n";
	cout << "XP: " << hrac_xp << "/" << hrac_xpDoLevelup << "\n";
	cout << "--------------------\n";
}
 
void nastavPaladina()
{
	hrac_trida = "Paladin";
	hrac_maxZivoty = 12; hrac_zivoty = 12;
	hrac_maxMana = 8; hrac_mana = 8;
	hrac_zlato = 10; hrac_utok = 4;
	hrac_level = 1; hrac_xp = 0; hrac_xpDoLevelup = 30;
 
	schopnost1_nazev = "Utok"; schopnost1_popis = "Uder za 4 poskozeni";
	schopnost1_poskozeni = 4; schopnost1_vsichni = false; schopnost1_heal = 0; schopnost1_mana = 0;
 
	schopnost2_nazev = "Uder svetlem"; schopnost2_popis = "1 poskozeni vsem";
	schopnost2_poskozeni = 1; schopnost2_vsichni = true; schopnost2_heal = 0; schopnost2_mana = 2;
 
	schopnost3_nazev = "Oziveni"; schopnost3_popis = "Obnovi 2 zivoty";
	schopnost3_poskozeni = 0; schopnost3_vsichni = false; schopnost3_heal = 2; schopnost3_mana = 1;
}
 
void nastavLovce()
{
	hrac_trida = "Lovec";
	hrac_maxZivoty = 9; hrac_zivoty = 9;
	hrac_maxMana = 6; hrac_mana = 6;
	hrac_zlato = 15; hrac_utok = 5;
	hrac_level = 1; hrac_xp = 0; hrac_xpDoLevelup = 30;
 
	schopnost1_nazev = "Utok"; schopnost1_popis = "Strela za 5 poskozeni";
	schopnost1_poskozeni = 5; schopnost1_vsichni = false; schopnost1_heal = 0; schopnost1_mana = 0;
 
	schopnost2_nazev = "Dvojstrela"; schopnost2_popis = "Dve strely za 5 celkem";
	schopnost2_poskozeni = 5; schopnost2_vsichni = false; schopnost2_heal = 0; schopnost2_mana = 2;
 
	schopnost3_nazev = "Zastaveni"; schopnost3_popis = "Omraci nepritele na 1 tah";
	schopnost3_poskozeni = 0; schopnost3_vsichni = false; schopnost3_heal = 0; schopnost3_mana = 3;
}
 
void nastavMaga()
{
	hrac_trida = "Mag";
	hrac_maxZivoty = 7; hrac_zivoty = 7;
	hrac_maxMana = 14; hrac_mana = 14;
	hrac_zlato = 12; hrac_utok = 3;
	hrac_level = 1; hrac_xp = 0; hrac_xpDoLevelup = 30;
 
	schopnost1_nazev = "Utok"; schopnost1_popis = "Magicky projektil za 3 poskozeni";
	schopnost1_poskozeni = 3; schopnost1_vsichni = false; schopnost1_heal = 0; schopnost1_mana = 0;
 
	schopnost2_nazev = "Ohniva koule"; schopnost2_popis = "4 poskozeni vsem neprum";
	schopnost2_poskozeni = 4; schopnost2_vsichni = true; schopnost2_heal = 0; schopnost2_mana = 4;
 
	schopnost3_nazev = "Mrazeni"; schopnost3_popis = "3 poskozeni a omraci nepritele";
	schopnost3_poskozeni = 3; schopnost3_vsichni = false; schopnost3_heal = 0; schopnost3_mana = 3;
}
 
void nastavWarlocka()
{
	hrac_trida = "Warlock";
	hrac_maxZivoty = 8; hrac_zivoty = 8;
	hrac_maxMana = 10; hrac_mana = 10;
	hrac_zlato = 8; hrac_utok = 4;
	hrac_level = 1; hrac_xp = 0; hrac_xpDoLevelup = 30;
 
	schopnost1_nazev = "Utok"; schopnost1_popis = "Temna magie za 4 poskozeni";
	schopnost1_poskozeni = 4; schopnost1_vsichni = false; schopnost1_heal = 0; schopnost1_mana = 0;
 
	schopnost2_nazev = "Kletba temnot"; schopnost2_popis = "3 poskozeni vsem";
	schopnost2_poskozeni = 3; schopnost2_vsichni = true; schopnost2_heal = 0; schopnost2_mana = 3;
 
	schopnost3_nazev = "Sate sily"; schopnost3_popis = "Ukradne 3 HP nepriteli";
	schopnost3_poskozeni = 3; schopnost3_vsichni = false; schopnost3_heal = 3; schopnost3_mana = 2;
}
 
void vyberPostavu()
{
	cout << "Zadej jmeno: ";
	getline(cin, hrac_jmeno);
	if (hrac_jmeno == "")
		hrac_jmeno = "Hrdina";
 
	bool vybrano = false;
	while (!vybrano)
	{
		cout << "\nVyber classu:\n";
		cout << "1) Paladin  HP:12 Mana:8  Utok:4\n";
		cout << "2) Lovec    HP:9  Mana:6  Utok:5\n";
		cout << "3) Mag      HP:7  Mana:14 Utok:3\n";
		cout << "4) Warlock  HP:8  Mana:10 Utok:4\n";
		cout << "Volba: ";
 
		int volba;
		cin >> volba;
		cin.ignore(10000, '\n');
 
		if (volba == 1) nastavPaladina();
		else if (volba == 2) nastavLovce();
		else if (volba == 3) nastavMaga();
		else if (volba == 4) nastavWarlocka();
		else { cout << "Neplatna volba.\n"; continue; }
 
		cout << "\nVybral sis: " << hrac_trida << "\n";
		cout << "HP:" << hrac_maxZivoty << " Mana:" << hrac_maxMana << " Utok:" << hrac_utok << "\n";
		cout << "Schopnosti:\n";
		cout << "  1) " << schopnost1_nazev << " - " << schopnost1_popis << "\n";
		cout << "  2) " << schopnost2_nazev << " - " << schopnost2_popis << "\n";
		cout << "  3) " << schopnost3_nazev << " - " << schopnost3_popis << "\n";
		cout << "Potvrzujes? 1)Ano 2)Ne: ";
		int potv;
		cin >> potv;
		cin.ignore(10000, '\n');
		if (potv == 1) vybrano = true;
	}
}
 
void nastavGoblina(int slot)
{
	int zlato = 0;
	if (sance(50)) zlato = nahodne(2, 7);
	if (slot == 1)
	{
		nep1_jmeno = "Goblin"; nep1_maxZivoty = 5; nep1_zivoty = 5;
		nep1_utok = 2; nep1_zlato = zlato; nep1_xp = 5; nep1_typ = 1;
		nep1_hlaska1 = "Goblin vristi: \"Moje zlato! Moje kosti!\"";
		nep1_hlaska2 = "Goblin vristi: \"Vrazim te do zeme!\"";
		nep1_omracen = false;
	}
	else
	{
		nep2_jmeno = "Goblin"; nep2_maxZivoty = 5; nep2_zivoty = 5;
		nep2_utok = 2; nep2_zlato = zlato; nep2_xp = 5; nep2_typ = 1;
		nep2_hlaska1 = "Goblin vristi: \"Moje zlato! Moje kosti!\"";
		nep2_hlaska2 = "Goblin vristi: \"Vrazim te do zeme!\"";
		nep2_omracen = false;
	}
}
 
void nastavZombii(int slot)
{
	int zlato = 0;
	if (sance(50)) zlato = nahodne(2, 7);
	if (slot == 1)
	{
		nep1_jmeno = "Zombie"; nep1_maxZivoty = 6; nep1_zivoty = 6;
		nep1_utok = 2; nep1_zlato = zlato; nep1_xp = 6; nep1_typ = 1;
		nep1_hlaska1 = "Zombie mumla: \"Moooozeeek...\"";
		nep1_hlaska2 = "Zombie mumla: \"Sluuuuziiiit...\"";
		nep1_omracen = false;
	}
	else
	{
		nep2_jmeno = "Zombie"; nep2_maxZivoty = 6; nep2_zivoty = 6;
		nep2_utok = 2; nep2_zlato = zlato; nep2_xp = 6; nep2_typ = 1;
		nep2_hlaska1 = "Zombie mumla: \"Moooozeeek...\"";
		nep2_hlaska2 = "Zombie mumla: \"Sluuuuziiiit...\"";
		nep2_omracen = false;
	}
}
 
void nastavBanditu(int slot)
{
	int zlato = 0;
	if (sance(50)) zlato = nahodne(2, 7);
	if (slot == 1)
	{
		nep1_jmeno = "Bandit"; nep1_maxZivoty = 6; nep1_zivoty = 6;
		nep1_utok = 3; nep1_zlato = zlato; nep1_xp = 7; nep1_typ = 1;
		nep1_hlaska1 = "Bandit vristi: \"Zlato nebo smrt!\"";
		nep1_hlaska2 = "Bandit vristi: \"Mas smulu, pocestny!\"";
		nep1_omracen = false;
	}
	else
	{
		nep2_jmeno = "Bandit"; nep2_maxZivoty = 6; nep2_zivoty = 6;
		nep2_utok = 3; nep2_zlato = zlato; nep2_xp = 7; nep2_typ = 1;
		nep2_hlaska1 = "Bandit vristi: \"Zlato nebo smrt!\"";
		nep2_hlaska2 = "Bandit vristi: \"Mas smulu, pocestny!\"";
		nep2_omracen = false;
	}
}
 
bool souboj(bool hracPrvni)
{
	cout << "\n*** SOUBOJ ***\n";
	cout << "-> " << nep1_jmeno << " HP:" << nep1_zivoty << " ATK:" << nep1_utok << "\n";
	if (pocetNepriatel == 2)
		cout << "-> " << nep2_jmeno << " HP:" << nep2_zivoty << " ATK:" << nep2_utok << "\n";
	enter();
 
	bool hracNaTahu = hracPrvni;
	int kolo = 0;
 
	while (hrac_zivoty > 0)
	{
		bool vseMrtvo = true;
		if (nep1_zivoty > 0) vseMrtvo = false;
		if (pocetNepriatel == 2 && nep2_zivoty > 0) vseMrtvo = false;
		if (vseMrtvo) break;
 
		kolo++;
 
		if (hracNaTahu || kolo == 1)
		{
			zobrazHrace();
			cout << "Nepratele:\n";
			if (nep1_zivoty > 0)
				cout << "  1) " << nep1_jmeno << " HP:" << nep1_zivoty << "/" << nep1_maxZivoty << "\n";
			if (pocetNepriatel == 2 && nep2_zivoty > 0)
				cout << "  2) " << nep2_jmeno << " HP:" << nep2_zivoty << "/" << nep2_maxZivoty << "\n";
 
			cout << "Schopnosti:\n";
			cout << "  1) " << schopnost1_nazev << " - " << schopnost1_popis;
			if (schopnost1_mana > 0) cout << " [" << schopnost1_mana << " many]";
			cout << "\n  2) " << schopnost2_nazev << " - " << schopnost2_popis;
			if (schopnost2_mana > 0) cout << " [" << schopnost2_mana << " many]";
			cout << "\n  3) " << schopnost3_nazev << " - " << schopnost3_popis;
			if (schopnost3_mana > 0) cout << " [" << schopnost3_mana << " many]";
			cout << "\n";
 
			int volba = 0;
			while (volba < 1 || volba > 3)
			{
				cout << "Volba (1-3): ";
				cin >> volba;
				cin.ignore(10000, '\n');
			}
 
			string s_nazev; int s_posk; bool s_vsichni; int s_heal; int s_mana;
			if (volba == 1) { s_nazev = schopnost1_nazev; s_posk = schopnost1_poskozeni; s_vsichni = schopnost1_vsichni; s_heal = schopnost1_heal; s_mana = schopnost1_mana; }
			else if (volba == 2) { s_nazev = schopnost2_nazev; s_posk = schopnost2_poskozeni; s_vsichni = schopnost2_vsichni; s_heal = schopnost2_heal; s_mana = schopnost2_mana; }
			else { s_nazev = schopnost3_nazev; s_posk = schopnost3_poskozeni; s_vsichni = schopnost3_vsichni; s_heal = schopnost3_heal; s_mana = schopnost3_mana; }
 
			if (s_mana > hrac_mana)
			{
				cout << "Nemas dost many, utocis normalne.\n";
				s_nazev = schopnost1_nazev; s_posk = schopnost1_poskozeni; s_vsichni = false; s_heal = 0; s_mana = 0;
			}
			hrac_mana -= s_mana;
 
			if (s_heal > 0 && s_posk == 0)
			{
				hrac_zivoty += s_heal;
				if (hrac_zivoty > hrac_maxZivoty) hrac_zivoty = hrac_maxZivoty;
				cout << "Obnovil sis " << s_heal << " HP. Mas: " << hrac_zivoty << "\n";
			}
 
			bool jeOmr = (s_nazev == "Zastaveni" || s_nazev == "Mrazeni");
 
			if (s_vsichni && s_posk > 0)
			{
				if (nep1_zivoty > 0) { nep1_zivoty -= s_posk; if (nep1_zivoty < 0) nep1_zivoty = 0; cout << nep1_jmeno << " -" << s_posk << " HP:" << nep1_zivoty << "\n"; }
				if (pocetNepriatel == 2 && nep2_zivoty > 0) { nep2_zivoty -= s_posk; if (nep2_zivoty < 0) nep2_zivoty = 0; cout << nep2_jmeno << " -" << s_posk << " HP:" << nep2_zivoty << "\n"; }
			}
			else if (!s_vsichni && s_posk > 0)
			{
				int cil = 1;
				if (pocetNepriatel == 2 && nep1_zivoty > 0 && nep2_zivoty > 0)
				{
					cout << "Vyber cil (1 nebo 2): ";
					cin >> cil;
					cin.ignore(10000, '\n');
				}
				else if (nep1_zivoty <= 0) cil = 2;
 
				if (cil == 1 && nep1_zivoty > 0)
				{
					if (s_heal > 0 && s_posk > 0) { hrac_zivoty += s_heal; if (hrac_zivoty > hrac_maxZivoty) hrac_zivoty = hrac_maxZivoty; cout << "Ukradl jsi " << s_heal << " HP!\n"; }
					nep1_zivoty -= s_posk; if (nep1_zivoty < 0) nep1_zivoty = 0;
					cout << nep1_jmeno << " dostava " << s_posk << " HP:" << nep1_zivoty;
					if (jeOmr && nep1_zivoty > 0) { nep1_omracen = true; cout << " (omracen)"; }
					cout << "\n";
				}
				else if (cil == 2 && nep2_zivoty > 0)
				{
					if (s_heal > 0 && s_posk > 0) { hrac_zivoty += s_heal; if (hrac_zivoty > hrac_maxZivoty) hrac_zivoty = hrac_maxZivoty; cout << "Ukradl jsi " << s_heal << " HP!\n"; }
					nep2_zivoty -= s_posk; if (nep2_zivoty < 0) nep2_zivoty = 0;
					cout << nep2_jmeno << " dostava " << s_posk << " HP:" << nep2_zivoty;
					if (jeOmr && nep2_zivoty > 0) { nep2_omracen = true; cout << " (omracen)"; }
					cout << "\n";
				}
			}
		}
 
		if (nep1_zivoty > 0)
		{
			if (nep1_omracen) { cout << nep1_jmeno << " je omracen.\n"; nep1_omracen = false; }
			else
			{
				if (sance(50)) cout << "\n" << nep1_hlaska1 << "\n";
				else cout << "\n" << nep1_hlaska2 << "\n";
				hrac_zivoty -= nep1_utok;
				if (hrac_zivoty < 0) hrac_zivoty = 0;
				cout << nep1_jmeno << " utoci za " << nep1_utok << "! HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
				if (hrac_zivoty <= 0) return false;
			}
		}
		if (pocetNepriatel == 2 && nep2_zivoty > 0)
		{
			if (nep2_omracen) { cout << nep2_jmeno << " je omracen.\n"; nep2_omracen = false; }
			else
			{
				if (sance(50)) cout << "\n" << nep2_hlaska1 << "\n";
				else cout << "\n" << nep2_hlaska2 << "\n";
				hrac_zivoty -= nep2_utok;
				if (hrac_zivoty < 0) hrac_zivoty = 0;
				cout << nep2_jmeno << " utoci za " << nep2_utok << "! HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
				if (hrac_zivoty <= 0) return false;
			}
		}
 
		hracNaTahu = true;
		enter();
	}
 
	cout << "\n*** VYHRAL JSI! ***\n";
	hrac_xp += nep1_xp;
	if (nep1_zlato > 0) { hrac_zlato += nep1_zlato; cout << nep1_jmeno << " mel " << nep1_zlato << " zlata!\n"; }
	if (pocetNepriatel == 2)
	{
		hrac_xp += nep2_xp;
		if (nep2_zlato > 0) { hrac_zlato += nep2_zlato; cout << nep2_jmeno << " mel " << nep2_zlato << " zlata!\n"; }
	}
	enter();
	return true;
}
 
void vesnice()
{
	cout << "\n=== VESNICE ===\n";
	cout << "Mas " << hrac_zlato << " zlata.\n";
 
	bool konec = false;
	while (!konec)
	{
		cout << "1) Koupit zivoty (2 zlata/HP)\n2) Zvysit max HP o 2 (10 zlata)\n3) Odejit\nVolba: ";
		int v;
		cin >> v;
		cin.ignore(10000, '\n');
 
		if (v == 1)
		{
			if (hrac_zlato < 2) cout << "Nemas dost zlata.\n";
			else
			{
				int chybi = hrac_maxZivoty - hrac_zivoty;
				if (chybi == 0) cout << "Mas plne HP.\n";
				else
				{
					int koupit = hrac_zlato / 2;
					if (koupit > chybi) koupit = chybi;
					hrac_zivoty += koupit;
					hrac_zlato -= koupit * 2;
					cout << "HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
				}
			}
		}
		else if (v == 2)
		{
			if (hrac_zlato < 10) cout << "Nemas dost zlata (10).\n";
			else { hrac_zlato -= 10; hrac_maxZivoty += 2; hrac_zivoty += 2; cout << "Max HP: " << hrac_maxZivoty << "\n"; }
		}
		else if (v == 3) konec = true;
		else cout << "Neplatna volba.\n";
	}
}
 
int main()
{
	srand((unsigned int)time(0));
 
	cout << "=== CESTA ZA BLINKRONEM ===\n\n";
	vyberPostavu();
	cout << "\nHodne stesti, " << hrac_jmeno << "!\n";
	enter();
 
	bool prohra = false;
 
	vesnice();
 
	if (!prohra)
	{
		cout << "\nPri ceste te prepadl Goblin!\n";
		nastavGoblina(1); pocetNepriatel = 1;
		if (!souboj(true)) prohra = true;
	}
	if (!prohra)
	{
		cout << "\nZe tmy vylezla Zombie!\n";
		nastavZombii(1); pocetNepriatel = 1;
		if (!souboj(true)) prohra = true;
	}
	if (!prohra)
	{
		cout << "\nGoblin a Bandit vam zahrazuji cestu!\n";
		nastavGoblina(1); nastavBanditu(2); pocetNepriatel = 2;
		if (!souboj(true)) prohra = true;
	}
 
	if (!prohra)
		cout << "\n(Zatim konec - pridal bych minibossy, vice monster a levelup)\n";
 
	if (prohra)
	{
		cout << "\n=== GAME OVER ===\n";
		cout << hrac_jmeno << " padl v boji.\n";
	}
 
	return 0;
}
