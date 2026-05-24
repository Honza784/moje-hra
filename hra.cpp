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
bool nep1_nezasazitelny;
bool nep1_nabitiUtok;
int nep1_kolo;
bool nep1_jeBlinkron;

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

string nep3_jmeno;
int nep3_zivoty;
int nep3_maxZivoty;
int nep3_utok;
int nep3_zlato;
int nep3_xp;
int nep3_typ;
string nep3_hlaska1;
string nep3_hlaska2;
bool nep3_omracen;

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

void cara()
{
	cout << "------------------------------------------------------------\n";
}

void zobrazHrace()
{
	cara();
	cout << hrac_jmeno << " [" << hrac_trida << "] Level " << hrac_level << "\n";
	cout << "HP: " << hrac_zivoty << "/" << hrac_maxZivoty;
	cout << "  Mana: " << hrac_mana << "/" << hrac_maxMana;
	cout << "  Zlato: " << hrac_zlato << "  Utok: " << hrac_utok << "\n";
	cout << "XP: " << hrac_xp << "/" << hrac_xpDoLevelup << "\n";
	cara();
}

void zkontrolujLevelup()
{
	while (hrac_xp >= hrac_xpDoLevelup)
	{
		hrac_xp -= hrac_xpDoLevelup;
		hrac_level++;
		hrac_xpDoLevelup = 25 + hrac_level * 10;
		int bonus = nahodne(3, 5);
		hrac_maxZivoty += bonus;
		hrac_zivoty += bonus;
		if (hrac_zivoty > hrac_maxZivoty) hrac_zivoty = hrac_maxZivoty;
		hrac_maxMana++;
		hrac_utok++;
		schopnost1_poskozeni = hrac_utok;
		cout << "\n*** NOVY LEVEL " << hrac_level << "! ***\n";
		cout << "Max zivoty: +" << bonus << "  Utok: +1  Mana: +1\n";
	}
}

void nastavPaladina()
{
	hrac_trida = "Paladin";
	hrac_maxZivoty = 22; hrac_zivoty = 22;
	hrac_maxMana = 10; hrac_mana = 10;
	hrac_zlato = 15; hrac_utok = 5;
	hrac_level = 1; hrac_xp = 0; hrac_xpDoLevelup = 25;

	schopnost1_nazev = "Utok"; schopnost1_popis = "Uder za 5 poskozeni";
	schopnost1_poskozeni = 5; schopnost1_vsichni = false; schopnost1_heal = 0; schopnost1_mana = 0;

	schopnost2_nazev = "Uder svetlem"; schopnost2_popis = "3 poskozeni vsem neprum";
	schopnost2_poskozeni = 3; schopnost2_vsichni = true; schopnost2_heal = 0; schopnost2_mana = 3;

	schopnost3_nazev = "Oziveni"; schopnost3_popis = "Obnovi 5 zivotu";
	schopnost3_poskozeni = 0; schopnost3_vsichni = false; schopnost3_heal = 5; schopnost3_mana = 2;
}

void nastavLovce()
{
	hrac_trida = "Lovec";
	hrac_maxZivoty = 18; hrac_zivoty = 18;
	hrac_maxMana = 8; hrac_mana = 8;
	hrac_zlato = 20; hrac_utok = 7;
	hrac_level = 1; hrac_xp = 0; hrac_xpDoLevelup = 25;

	schopnost1_nazev = "Utok"; schopnost1_popis = "Strela za 7 poskozeni";
	schopnost1_poskozeni = 7; schopnost1_vsichni = false; schopnost1_heal = 0; schopnost1_mana = 0;

	schopnost2_nazev = "Dvojstrela"; schopnost2_popis = "Dve strely za 10 poskozeni celkem";
	schopnost2_poskozeni = 10; schopnost2_vsichni = false; schopnost2_heal = 0; schopnost2_mana = 3;

	schopnost3_nazev = "Zastaveni"; schopnost3_popis = "Omraci nepritele, preskoci jeden tah";
	schopnost3_poskozeni = 0; schopnost3_vsichni = false; schopnost3_heal = 0; schopnost3_mana = 2;
}

void nastavMaga()
{
	hrac_trida = "Mag";
	hrac_maxZivoty = 16; hrac_zivoty = 16;
	hrac_maxMana = 20; hrac_mana = 20;
	hrac_zlato = 12; hrac_utok = 4;
	hrac_level = 1; hrac_xp = 0; hrac_xpDoLevelup = 25;

	schopnost1_nazev = "Utok"; schopnost1_popis = "Magicky projektil za 4 poskozeni";
	schopnost1_poskozeni = 4; schopnost1_vsichni = false; schopnost1_heal = 0; schopnost1_mana = 0;

	schopnost2_nazev = "Ohniva koule"; schopnost2_popis = "6 poskozeni vsem neprum";
	schopnost2_poskozeni = 6; schopnost2_vsichni = true; schopnost2_heal = 0; schopnost2_mana = 5;

	schopnost3_nazev = "Mrazeni"; schopnost3_popis = "5 poskozeni a omraci nepritele";
	schopnost3_poskozeni = 5; schopnost3_vsichni = false; schopnost3_heal = 0; schopnost3_mana = 4;
}

void nastavWarlocka()
{
	hrac_trida = "Warlock";
	hrac_maxZivoty = 18; hrac_zivoty = 18;
	hrac_maxMana = 12; hrac_mana = 12;
	hrac_zlato = 10; hrac_utok = 5;
	hrac_level = 1; hrac_xp = 0; hrac_xpDoLevelup = 25;

	schopnost1_nazev = "Utok"; schopnost1_popis = "Temna magie za 5 poskozeni";
	schopnost1_poskozeni = 5; schopnost1_vsichni = false; schopnost1_heal = 0; schopnost1_mana = 0;

	schopnost2_nazev = "Kletba temnot"; schopnost2_popis = "4 poskozeni vsem neprum";
	schopnost2_poskozeni = 4; schopnost2_vsichni = true; schopnost2_heal = 0; schopnost2_mana = 4;

	schopnost3_nazev = "Sate sily"; schopnost3_popis = "6 poskozeni a obnovi 6 HP";
	schopnost3_poskozeni = 6; schopnost3_vsichni = false; schopnost3_heal = 6; schopnost3_mana = 3;
}

void vyberPostavu()
{
	cout << "Zadej jmeno: ";
	getline(cin, hrac_jmeno);
	if (hrac_jmeno == "") hrac_jmeno = "Hrdina";

	bool vybrano = false;
	while (!vybrano)
	{
		cout << "\nVyber classu:\n";
		cout << "1) Paladin  HP:22 Mana:10 Utok:5  (nejvetsi zivoty, heal)\n";
		cout << "2) Lovec    HP:18 Mana:8  Utok:7  (nejvyssi poskozeni, omraceni)\n";
		cout << "3) Mag      HP:16 Mana:20 Utok:4  (hodne many, silne kouzlo na vice nepratel)\n";
		cout << "4) Warlock  HP:18 Mana:12 Utok:5  (steal HP od nepritele)\n";
		cout << "Volba: ";
		int volba; cin >> volba; cin.ignore(10000, '\n');

		if (volba == 1) nastavPaladina();
		else if (volba == 2) nastavLovce();
		else if (volba == 3) nastavMaga();
		else if (volba == 4) nastavWarlocka();
		else { cout << "Neplatna volba.\n"; continue; }

		cout << "\nVybral sis: " << hrac_trida << "\n";
		cout << "HP:" << hrac_maxZivoty << " Mana:" << hrac_maxMana << " Utok:" << hrac_utok << "\n";
		cout << "Schopnosti:\n";
		cout << "  1) " << schopnost1_nazev << " - " << schopnost1_popis << "\n";
		cout << "  2) " << schopnost2_nazev << " - " << schopnost2_popis;
		if (schopnost2_mana > 0) cout << " [" << schopnost2_mana << " many]";
		cout << "\n";
		cout << "  3) " << schopnost3_nazev << " - " << schopnost3_popis;
		if (schopnost3_mana > 0) cout << " [" << schopnost3_mana << " many]";
		cout << "\n";
		cout << "Potvrzujes? 1)Ano 2)Ne: ";
		int potv; cin >> potv; cin.ignore(10000, '\n');
		if (potv == 1) vybrano = true;
	}
}

void nastavMonstrum(int slot, string jmeno, int hp, int atk, int xp, int zlatoMin, int zlatoMax, string h1, string h2)
{
	int zlato = 0;
	if (sance(50)) zlato = nahodne(zlatoMin, zlatoMax);

	if (slot == 1)
	{
		nep1_jmeno = jmeno; nep1_maxZivoty = hp; nep1_zivoty = hp;
		nep1_utok = atk; nep1_zlato = zlato; nep1_xp = xp; nep1_typ = 1;
		nep1_hlaska1 = h1; nep1_hlaska2 = h2;
		nep1_omracen = false; nep1_nezasazitelny = false; nep1_nabitiUtok = false; nep1_kolo = 0; nep1_jeBlinkron = false;
	}
	else if (slot == 2)
	{
		nep2_jmeno = jmeno; nep2_maxZivoty = hp; nep2_zivoty = hp;
		nep2_utok = atk; nep2_zlato = zlato; nep2_xp = xp; nep2_typ = 1;
		nep2_hlaska1 = h1; nep2_hlaska2 = h2; nep2_omracen = false;
	}
	else
	{
		nep3_jmeno = jmeno; nep3_maxZivoty = hp; nep3_zivoty = hp;
		nep3_utok = atk; nep3_zlato = zlato; nep3_xp = xp; nep3_typ = 1;
		nep3_hlaska1 = h1; nep3_hlaska2 = h2; nep3_omracen = false;
	}
}

void nastavGoblina(int slot)   { nastavMonstrum(slot, "Goblin",    10, 3,  8,  2, 5,  "Goblin vristi: \"Moje zlato! Moje kosti!\"",                        "Goblin vristi: \"Vrazim te do zeme!\""); }
void nastavZombii(int slot)    { nastavMonstrum(slot, "Zombie",    12, 3,  10, 2, 5,  "Zombie mumla: \"Moooozeeek...\"",                                    "Zombie mumla: \"Sluuuuziiiit...\""); }
void nastavTrolla(int slot)    { nastavMonstrum(slot, "Troll",     18, 5,  15, 3, 7,  "Troll rve: \"Tamaten hnufak chce nasejc zlato, majznu ho palici!\"", "Troll rve: \"Troll moc hladovy!\""); }
void nastavVlkodlaka(int slot) { nastavMonstrum(slot, "Vlkodlak",  14, 4,  12, 2, 5,  "Vlkodlak vyje: \"Aaauuuu! Krev!\"",                                 "Vlkodlak vrci: \"Moje noci, moje korist!\""); }
void nastavDraka(int slot)     { nastavMonstrum(slot, "Drak",      16, 5,  15, 3, 8,  "Drak reve: \"Smrtelnici jsou tak malickati!\"",                      "Drak reve: \"Tvoje kosti ohriji moje vejce!\""); }
void nastavKostlivce(int slot) { nastavMonstrum(slot, "Kostlivec", 12, 4,  10, 2, 5,  "Kostlivec rachoti: \"Klapklapklap!\"",                               "Kostlivec rachoti: \"Nemas sanci!\""); }
void nastavPriseru(int slot)   { nastavMonstrum(slot, "Prisera",   13, 5,  12, 2, 6,  "Prisera vrzci neznamy zvuk.",                                        "Prisera trese vzduchem svymi chapadly."); }
void nastavBanditu(int slot)   { nastavMonstrum(slot, "Bandit",    11, 4,  10, 2, 6,  "Bandit vristi: \"Zlato nebo smrt!\"",                                "Bandit vristi: \"Mas smulu, pocestny!\""); }

void nastavMiniboss1()
{
	nep1_jmeno = "Zar Stinovy"; nep1_maxZivoty = 28; nep1_zivoty = 28;
	nep1_utok = 5; nep1_zlato = nahodne(15, 25); nep1_xp = 30; nep1_typ = 2;
	nep1_hlaska1 = "Zar Stinovy krici: \"Temnota pohltit te!\"";
	nep1_hlaska2 = "Zar Stinovy syci: \"Nemas zadnou sanci!\"";
	nep1_omracen = false; nep1_nezasazitelny = false; nep1_nabitiUtok = false; nep1_kolo = 0; nep1_jeBlinkron = false;
	pocetNepriatel = 1;
}

void nastavMiniboss2()
{
	nep1_jmeno = "Krvava Jena"; nep1_maxZivoty = 32; nep1_zivoty = 32;
	nep1_utok = 6; nep1_zlato = nahodne(20, 30); nep1_xp = 40; nep1_typ = 2;
	nep1_hlaska1 = "Krvava Jena vristi: \"Tvoje krev ozdobi muj mes!\"";
	nep1_hlaska2 = "Krvava Jena vristi: \"Padni pred meho krale!\"";
	nep1_omracen = false; nep1_nezasazitelny = false; nep1_nabitiUtok = false; nep1_kolo = 0; nep1_jeBlinkron = false;
	pocetNepriatel = 1;
}

void nastavBlinkrona()
{
	nep1_jmeno = "BLINKRON";
	nep1_maxZivoty = 40; nep1_zivoty = 40;
	nep1_utok = 6; nep1_zlato = 0; nep1_xp = 0; nep1_typ = 3;
	nep1_hlaska1 = "Blinkron vristi: \"Nikdy mne nechytis!\"";
	nep1_hlaska2 = "Blinkron vristi: \"Mas prilis pomalou ruku!\"";
	nep1_omracen = false; nep1_nezasazitelny = false; nep1_nabitiUtok = false; nep1_kolo = 0; nep1_jeBlinkron = true;
	pocetNepriatel = 1;
}

void nahodneSetkani1v1()
{
	int r = nahodne(1, 4);
	if (r == 1)      { cout << "\nPri ceste te prepadl Goblin!\n";        nastavGoblina(1); }
	else if (r == 2) { cout << "\nZe tmy vylezla Zombie!\n";              nastavZombii(1); }
	else if (r == 3) { cout << "\nZ lesa vyskocil Bandit!\n";             nastavBanditu(1); }
	else             { cout << "\nZ temna se vynoril Kostlivec!\n";        nastavKostlivce(1); }
	pocetNepriatel = 1;
}

void nahodneSetkani2v1()
{
	int r1 = nahodne(1, 3);
	int r2 = nahodne(1, 3);

	if (r1 == 1) nastavGoblina(1);
	else if (r1 == 2) nastavZombii(1);
	else nastavBanditu(1);

	if (r2 == 1) nastavVlkodlaka(2);
	else if (r2 == 2) nastavKostlivce(2);
	else nastavPriseru(2);

	cout << "\n" << nep1_jmeno << " a " << nep2_jmeno << " vam zahrazuji cestu!\n";
	pocetNepriatel = 2;
}

void pridejXPaZlato()
{
	if (nep1_typ != 3)
	{
		hrac_xp += nep1_xp; zkontrolujLevelup();
		if (nep1_zlato > 0) { hrac_zlato += nep1_zlato; cout << nep1_jmeno << " mel " << nep1_zlato << " zlata!\n"; }
	}
	if (pocetNepriatel >= 2)
	{
		hrac_xp += nep2_xp; zkontrolujLevelup();
		if (nep2_zlato > 0) { hrac_zlato += nep2_zlato; cout << nep2_jmeno << " mel " << nep2_zlato << " zlata!\n"; }
	}
	if (pocetNepriatel >= 3)
	{
		hrac_xp += nep3_xp; zkontrolujLevelup();
		if (nep3_zlato > 0) { hrac_zlato += nep3_zlato; cout << nep3_jmeno << " mel " << nep3_zlato << " zlata!\n"; }
	}
}

bool souboj(bool hracPrvni)
{
	cout << "\n*** SOUBOJ ***\n";
	cout << "-> " << nep1_jmeno << " HP:" << nep1_zivoty << " ATK:" << nep1_utok << "\n";
	if (pocetNepriatel >= 2) cout << "-> " << nep2_jmeno << " HP:" << nep2_zivoty << " ATK:" << nep2_utok << "\n";
	if (pocetNepriatel >= 3) cout << "-> " << nep3_jmeno << " HP:" << nep3_zivoty << " ATK:" << nep3_utok << "\n";
	enter();

	bool hracNaTahu = hracPrvni;
	int kolo = 0;

	while (hrac_zivoty > 0)
	{
		bool vseMrtvo = true;
		if (nep1_zivoty > 0) vseMrtvo = false;
		if (pocetNepriatel >= 2 && nep2_zivoty > 0) vseMrtvo = false;
		if (pocetNepriatel >= 3 && nep3_zivoty > 0) vseMrtvo = false;
		if (vseMrtvo) break;

		kolo++;

		if (nep1_jeBlinkron && nep1_zivoty > 0)
		{
			nep1_kolo++;
			nep1_nezasazitelny = false;

			if (nep1_kolo % 3 == 0)
			{
				cout << "\n*** Blinkron mizi v zablesku svetla! ***\n";
				cout << "    Teleportuje se za teba - dvojnasobne poskozeni, nelze zablokovat!\n";
				int dmg = nep1_utok * 2;
				hrac_zivoty -= dmg;
				if (hrac_zivoty < 0) hrac_zivoty = 0;
				cout << "Blinkron te zasahl zezadu za " << dmg << " poskozeni!\n";
				cout << "Tvoje HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
				if (hrac_zivoty <= 0) return false;
			}

			if (sance(50))
			{
				nep1_nezasazitelny = true;
				cout << "\n[BLINKRON] se odbleskl - je NEZASAZITELNY do dalsiho tahu!\n";
			}
		}

		if (hracNaTahu || kolo == 1)
		{
			zobrazHrace();
			cout << "Nepratele:\n";
			if (nep1_zivoty > 0)
			{
				cout << "  1) " << nep1_jmeno << " HP:" << nep1_zivoty << "/" << nep1_maxZivoty;
				if (nep1_nezasazitelny) cout << " (NEZASAZITELNY)";
				cout << "\n";
			}
			if (pocetNepriatel >= 2 && nep2_zivoty > 0) cout << "  2) " << nep2_jmeno << " HP:" << nep2_zivoty << "/" << nep2_maxZivoty << "\n";
			if (pocetNepriatel >= 3 && nep3_zivoty > 0) cout << "  3) " << nep3_jmeno << " HP:" << nep3_zivoty << "/" << nep3_maxZivoty << "\n";

			cout << "Schopnosti:\n";
			cout << "  1) " << schopnost1_nazev << " - " << schopnost1_popis << "\n";
			cout << "  2) " << schopnost2_nazev << " - " << schopnost2_popis;
			if (schopnost2_mana > 0) cout << " [" << schopnost2_mana << " many]";
			cout << "\n  3) " << schopnost3_nazev << " - " << schopnost3_popis;
			if (schopnost3_mana > 0) cout << " [" << schopnost3_mana << " many]";
			cout << "\n";

			int volba = 0;
			while (volba < 1 || volba > 3) { cout << "Volba (1-3): "; cin >> volba; cin.ignore(10000, '\n'); }

			string s_nazev; int s_posk; bool s_vsichni; int s_heal; int s_mana;
			if (volba == 1) { s_nazev = schopnost1_nazev; s_posk = schopnost1_poskozeni; s_vsichni = schopnost1_vsichni; s_heal = schopnost1_heal; s_mana = schopnost1_mana; }
			else if (volba == 2) { s_nazev = schopnost2_nazev; s_posk = schopnost2_poskozeni; s_vsichni = schopnost2_vsichni; s_heal = schopnost2_heal; s_mana = schopnost2_mana; }
			else { s_nazev = schopnost3_nazev; s_posk = schopnost3_poskozeni; s_vsichni = schopnost3_vsichni; s_heal = schopnost3_heal; s_mana = schopnost3_mana; }

			if (s_mana > hrac_mana) { cout << "Nemas dost many, utocis normalne.\n"; s_nazev = schopnost1_nazev; s_posk = schopnost1_poskozeni; s_vsichni = false; s_heal = 0; s_mana = 0; }
			hrac_mana -= s_mana;

			if (s_heal > 0 && s_posk == 0)
			{
				hrac_zivoty += s_heal;
				if (hrac_zivoty > hrac_maxZivoty) hrac_zivoty = hrac_maxZivoty;
				cout << "Obnovil sis " << s_heal << " HP. Mas: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
			}

			bool jeOmr = (s_nazev == "Zastaveni" || s_nazev == "Mrazeni");

			if (s_vsichni && s_posk > 0)
			{
				if (nep1_zivoty > 0)
				{
					if (nep1_nezasazitelny) { cout << nep1_jmeno << " je nezasazitelny, utok minal!\n"; nep1_nabitiUtok = true; }
					else { nep1_zivoty -= s_posk; if (nep1_zivoty < 0) nep1_zivoty = 0; cout << nep1_jmeno << " -" << s_posk << " HP:" << nep1_zivoty << "\n"; }
				}
				if (pocetNepriatel >= 2 && nep2_zivoty > 0) { nep2_zivoty -= s_posk; if (nep2_zivoty < 0) nep2_zivoty = 0; cout << nep2_jmeno << " -" << s_posk << " HP:" << nep2_zivoty << "\n"; }
				if (pocetNepriatel >= 3 && nep3_zivoty > 0) { nep3_zivoty -= s_posk; if (nep3_zivoty < 0) nep3_zivoty = 0; cout << nep3_jmeno << " -" << s_posk << " HP:" << nep3_zivoty << "\n"; }
			}
			else if (!s_vsichni && s_posk > 0)
			{
				int cil = 1;
				int zivych = 0;
				if (nep1_zivoty > 0) zivych++;
				if (pocetNepriatel >= 2 && nep2_zivoty > 0) zivych++;
				if (pocetNepriatel >= 3 && nep3_zivoty > 0) zivych++;
				if (zivych > 1) { cout << "Vyber cil: "; cin >> cil; cin.ignore(10000, '\n'); }
				else { if (nep1_zivoty > 0) cil = 1; else if (nep2_zivoty > 0) cil = 2; else cil = 3; }

				if (cil == 1 && nep1_zivoty > 0)
				{
					if (nep1_nezasazitelny) { cout << nep1_jmeno << " je nezasazitelny - utok minal!\n"; nep1_nabitiUtok = true; }
					else
					{
						if (s_heal > 0 && s_posk > 0) { hrac_zivoty += s_heal; if (hrac_zivoty > hrac_maxZivoty) hrac_zivoty = hrac_maxZivoty; cout << "Ukradl jsi " << s_heal << " HP!\n"; }
						nep1_zivoty -= s_posk; if (nep1_zivoty < 0) nep1_zivoty = 0;
						cout << nep1_jmeno << " dostava " << s_posk << " HP:" << nep1_zivoty;
						if (jeOmr && nep1_zivoty > 0) { nep1_omracen = true; cout << " (omracen)"; }
						cout << "\n";
					}
				}
				else if (cil == 2 && nep2_zivoty > 0)
				{
					if (s_heal > 0 && s_posk > 0) { hrac_zivoty += s_heal; if (hrac_zivoty > hrac_maxZivoty) hrac_zivoty = hrac_maxZivoty; cout << "Ukradl jsi " << s_heal << " HP!\n"; }
					nep2_zivoty -= s_posk; if (nep2_zivoty < 0) nep2_zivoty = 0;
					cout << nep2_jmeno << " dostava " << s_posk << " HP:" << nep2_zivoty;
					if (jeOmr && nep2_zivoty > 0) { nep2_omracen = true; cout << " (omracen)"; }
					cout << "\n";
				}
				else if (cil == 3 && nep3_zivoty > 0)
				{
					if (s_heal > 0 && s_posk > 0) { hrac_zivoty += s_heal; if (hrac_zivoty > hrac_maxZivoty) hrac_zivoty = hrac_maxZivoty; cout << "Ukradl jsi " << s_heal << " HP!\n"; }
					nep3_zivoty -= s_posk; if (nep3_zivoty < 0) nep3_zivoty = 0;
					cout << nep3_jmeno << " dostava " << s_posk << " HP:" << nep3_zivoty;
					if (jeOmr && nep3_zivoty > 0) { nep3_omracen = true; cout << " (omracen)"; }
					cout << "\n";
				}
			}
		}

		if (nep1_zivoty > 0)
		{
			if (nep1_jeBlinkron && nep1_kolo % 3 == 0)
			{
			}
			else if (nep1_omracen) { cout << nep1_jmeno << " je omracen, preskakuje tah.\n"; nep1_omracen = false; }
			else
			{
				if (sance(50)) cout << "\n" << nep1_hlaska1 << "\n"; else cout << "\n" << nep1_hlaska2 << "\n";
				int dmg = nep1_utok;
				if (nep1_jeBlinkron && nep1_nabitiUtok) { dmg = dmg + dmg / 2; cout << "[Blinkron nabity utok!] "; nep1_nabitiUtok = false; }
				hrac_zivoty -= dmg; if (hrac_zivoty < 0) hrac_zivoty = 0;
				cout << nep1_jmeno << " utoci za " << dmg << "! HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
				if (hrac_zivoty <= 0) return false;
			}
		}
		if (pocetNepriatel >= 2 && nep2_zivoty > 0)
		{
			if (nep2_omracen) { cout << nep2_jmeno << " je omracen.\n"; nep2_omracen = false; }
			else
			{
				if (sance(50)) cout << "\n" << nep2_hlaska1 << "\n"; else cout << "\n" << nep2_hlaska2 << "\n";
				hrac_zivoty -= nep2_utok; if (hrac_zivoty < 0) hrac_zivoty = 0;
				cout << nep2_jmeno << " utoci za " << nep2_utok << "! HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
				if (hrac_zivoty <= 0) return false;
			}
		}
		if (pocetNepriatel >= 3 && nep3_zivoty > 0)
		{
			if (nep3_omracen) { cout << nep3_jmeno << " je omracen.\n"; nep3_omracen = false; }
			else
			{
				if (sance(50)) cout << "\n" << nep3_hlaska1 << "\n"; else cout << "\n" << nep3_hlaska2 << "\n";
				hrac_zivoty -= nep3_utok; if (hrac_zivoty < 0) hrac_zivoty = 0;
				cout << nep3_jmeno << " utoci za " << nep3_utok << "! HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "\n";
				if (hrac_zivoty <= 0) return false;
			}
		}

		hracNaTahu = true;
		enter();
	}

	cout << "\n*** VYHRAL JSI! ***\n";
	pridejXPaZlato();
	cout << "HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "  Zlato: " << hrac_zlato << "\n";
	enter();
	return true;
}

void vesnice(int cislo)
{
	cout << "\n============================================================\n";
	cout << "*** VESNICE " << cislo << " ***\n";
	cout << "============================================================\n";
	cout << "Vesnicane te vitaji. Mas " << hrac_zlato << " zlata.\n";

	bool konec = false;
	while (!konec)
	{
		cout << "\nCo chces udelat?\n";
		cout << "1) Doplnit zivoty (1 zlato za 1 HP)\n";
		cout << "2) Zvysit max HP o 3 (8 zlata)\n";
		cout << "3) Zvysit max manu o 3 (6 zlata)\n";
		cout << "4) Zvysit utok o 1 (10 zlata)\n";
		cout << "5) Odejit\nVolba: ";
		int v; cin >> v; cin.ignore(10000, '\n');

		if (v == 1)
		{
			int chybi = hrac_maxZivoty - hrac_zivoty;
			if (chybi == 0) cout << "Mas plne HP.\n";
			else if (hrac_zlato < 1) cout << "Nemas zadne zlato.\n";
			else
			{
				int koupit = hrac_zlato;
				if (koupit > chybi) koupit = chybi;
				hrac_zivoty += koupit;
				hrac_zlato -= koupit;
				cout << "HP: " << hrac_zivoty << "/" << hrac_maxZivoty << "  Zlato: " << hrac_zlato << "\n";
			}
		}
		else if (v == 2) { if (hrac_zlato < 8)  cout << "Nemas dost zlata (8).\n";  else { hrac_zlato -= 8;  hrac_maxZivoty += 3; hrac_zivoty += 3; if (hrac_zivoty > hrac_maxZivoty) hrac_zivoty = hrac_maxZivoty; cout << "Max HP: " << hrac_maxZivoty << "\n"; } }
		else if (v == 3) { if (hrac_zlato < 6)  cout << "Nemas dost zlata (6).\n";  else { hrac_zlato -= 6;  hrac_maxMana  += 3; hrac_mana  += 3; if (hrac_mana > hrac_maxMana) hrac_mana = hrac_maxMana; cout << "Max mana: " << hrac_maxMana << "\n"; } }
		else if (v == 4) { if (hrac_zlato < 10) cout << "Nemas dost zlata (10).\n"; else { hrac_zlato -= 10; hrac_utok++; schopnost1_poskozeni = hrac_utok; cout << "Utok: " << hrac_utok << "\n"; } }
		else if (v == 5) { cout << "Odchazis. Hodne stesti!\n"; konec = true; }
		else cout << "Neplatna volba.\n";
	}
}

void moudryStrom()
{
	cout << "\n============================================================\n";
	cout << "* Na mytine stoji osamely strom. *\n";
	cout << "Strom: \"Zdravim, pocestny! Odvazujes se pomerit sily mysli?\"\n";
	cout << "1) Ano  2) Ne\nVolba: ";
	int v; cin >> v; cin.ignore(10000, '\n');
	if (v != 1) { cout << "Strom: \"Jak chces...\"\n"; return; }

	cout << "Strom: \"Kazdy den na obloze se vznasi, radost nam prinasi a bubaky strasi.\n";
	cout << "  Co to je?\"\n";
	cout << "Odpoved: ";
	string odp; getline(cin, odp);
	for (int i = 0; i < (int)odp.size(); i++) odp[i] = tolower(odp[i]);

	bool ok = false;
	if (odp.find("slunce") != string::npos) ok = true;
	if (odp.find("slunko") != string::npos) ok = true;

	if (ok)
	{
		cout << "Strom: \"Ha, koumak jsi koukim! Navysim ti max zivoty o 4 a doplnim je.\"\n";
		hrac_maxZivoty += 4; hrac_zivoty = hrac_maxZivoty;
		cout << "Max zivoty: " << hrac_maxZivoty << "\n";
	}
	else
	{
		cout << "Strom: \"Spatne! Za trest ztratis 5 zlata.\"\n";
		hrac_zlato -= 5;
		if (hrac_zlato < 0) hrac_zlato = 0;
		cout << "Zlato: " << hrac_zlato << "\n";
	}
	enter();
}

int main()
{
	srand((unsigned int)time(0));

	cout << "============================================================\n";
	cout << "       *** CESTA ZA BLINKRONEM ***\n";
	cout << "============================================================\n";

	vyberPostavu();
	cout << "\nHodne stesti, " << hrac_jmeno << "!\n";
	enter();

	bool prohra = false;

	vesnice(1);

	if (!prohra) { nahodneSetkani1v1(); if (!souboj(true)) prohra = true; }
	if (!prohra) { hrac_mana = hrac_maxMana; cout << "\nOdpocinul sis. Mana doplnena.\n"; }
	if (!prohra) { nahodneSetkani1v1(); if (!souboj(true)) prohra = true; }
	if (!prohra) { vesnice(2); }
	if (!prohra) { cout << "\n=== ZAR STINOVY blokuje branu! ===\n"; nastavMiniboss1(); if (!souboj(false)) prohra = true; }
	if (!prohra) { hrac_mana = hrac_maxMana; cout << "\nOdpocinul sis. Mana doplnena.\n"; }
	if (!prohra) { nahodneSetkani1v1(); if (!souboj(true)) prohra = true; }
	if (!prohra) { hrac_mana = hrac_maxMana; cout << "\nOdpocinul sis. Mana doplnena.\n"; }
	if (!prohra) { nahodneSetkani2v1(); if (!souboj(true)) prohra = true; }
	if (!prohra) { moudryStrom(); }
	if (!prohra) { vesnice(3); }
	if (!prohra) { cout << "\n=== KRVAVA JENA blokuje most! ===\n"; nastavMiniboss2(); if (!souboj(false)) prohra = true; }
	if (!prohra) { hrac_mana = hrac_maxMana; cout << "\nOdpocinul sis. Mana doplnena.\n"; }
	if (!prohra)
	{
		cout << "\nTri nepratele ti zahrazuji posledni cestu!\n";
		nastavGoblina(1); nastavZombii(2); nastavBanditu(3); pocetNepriatel = 3;
		if (!souboj(true)) prohra = true;
	}
	if (!prohra) { hrac_mana = hrac_maxMana; cout << "\nOdpocinul sis. Mana doplnena.\n"; }

	if (!prohra)
	{
		cout << "\n============================================================\n";
		cout << "Pred tebou se zraji brana citadely...\n";
		cout << "\n*** BLINKRON se materializuje pred tebou! ***\n";
		cout << "Blinkron vristi: \"Jsi dalsi blazen, ktery chce zemrit v zablesku svetla!\"\n";
		cout << "============================================================\n";
		enter();
		nastavBlinkrona();
		if (!souboj(false)) prohra = true;
	}

	if (!prohra)
	{
		cout << "\n============================================================\n";
		cout << "*** GRATULUJEME! Porazil jsi Blinkrona! ***\n";
		cout << "Svet je zachranen! " << hrac_jmeno << " se vraci domu v slade slave.\n";
		cout << "============================================================\n";
	}
	else
	{
		cout << "\n=== GAME OVER ===\n";
		cout << hrac_jmeno << " padl v boji.\n";
	}

	return 0;
}