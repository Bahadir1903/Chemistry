#include <iostream>
#include <vector>
#include <string>

using namespace std;

string elementName[118] = { "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
" Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
 "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium",
    "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
  "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium",
   "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
    "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon",
     "Francium","Radium","Actinium","Thorium","Protactinium","Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium","Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium",
      "Rutherfordium","Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium","Roentgenium","Copernicium","Nihonium","Flerovium","Moscovium","Livermorium","Tennessine",
       "Oganesson" };
int atomicNumber[118] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 , 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,61, 62, 63, 64, 65, 66, 67, 68, 69, 70,71 ,72 ,73 ,74 ,75 ,76 ,77 ,78 ,79 ,80 ,81 ,82 ,83 ,84 ,85 ,86 ,87 ,88 ,89 ,90 ,91 ,92 ,93 ,94 ,95 ,96 ,97 ,98 ,99 ,100 ,101 ,102 ,103 ,104 ,105 ,106 ,107 ,108 ,109 ,110 ,111 ,112 ,113 ,114 ,115 ,116 ,117 ,118 };
string type[8] = { "Metal", "Yari Metal", "Ametal","Gecis Metalleri","Soygazlar","Halojenler","Toprak Alkali Metal","Alkali Metal" };

string getType(int atomicNum) {
    if (atomicNum == 1 || atomicNum == 3 || atomicNum == 11 || atomicNum == 19 || atomicNum == 37 || atomicNum == 55 || atomicNum == 87)
        return type[7];
    else if (atomicNum == 2 || atomicNum == 10 || atomicNum == 18 || atomicNum == 36 || atomicNum == 54 || atomicNum == 86 || atomicNum == 118)
        return type[4];
    else if (atomicNum == 9 || atomicNum == 17 || atomicNum == 35 || atomicNum == 53 || atomicNum == 85)
        return type[5];
    else if (atomicNum == 4 || atomicNum == 12 || atomicNum == 20 || atomicNum == 38 || atomicNum == 56 || atomicNum == 88)
        return type[6];
    else if (atomicNum == 13 || atomicNum == 31 || atomicNum == 49 || atomicNum == 81)
        return type[1];
    else if (atomicNum == 5 || atomicNum == 14 || atomicNum == 32 || atomicNum == 33 || atomicNum == 51 || atomicNum == 52 || atomicNum == 84)
        return type[2];
    else if ((atomicNum >= 21 && atomicNum <= 30) || (atomicNum >= 39 && atomicNum <= 48) || (atomicNum >= 72 && atomicNum <= 80) || (atomicNum >= 104 && atomicNum <= 112))
        return type[0];
    else
        return type[3];
}

vector<int> bohrShells(int atomicNum) {
    vector<int> shells;
    int limits[7] = { 2, 8, 18, 32, 50, 72, 98 };
    int remaining = atomicNum;
    for (int i = 0; i < 7; ++i) {
        if (remaining > limits[i]) {
            shells.push_back(limits[i]);
            remaining -= limits[i];
        }
        else {
            shells.push_back(remaining);
            break;
        }
    }
    return shells;
}

int hacim(double hacim) {
	return hacim * 1000;
}
int kutle(double kutle) {
    return kutle * 1000;
}
int mol(double kutle, double molarKutle) {
    return kutle / molarKutle;
}

int main()
{
    cout << "-----------------------------Welcome to the Chemistry Calculator!----------------------" << endl;
    cout << "Element Name | Atomic Number | Type | Bohr Shells" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 118; i++)
    {
        string name = elementName[i];
        if (!name.empty() && name[0] == ' ')
            name = name.substr(1);

        string t = getType(atomicNumber[i]);
        vector<int> shells = bohrShells(atomicNumber[i]);
        cout << name << " | " << atomicNumber[i] << " | " << t << " | ";
        cout << "[";
        for (size_t j = 0; j < shells.size(); ++j) {
            cout << shells[j];
            if (j != shells.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
	cout << "Lutfen bir element seciniz (1-118): ";
    int x;
	cin >> x;
    if (x < 1 || x > 118) {
        cout << "Gecersiz element numarasi!" << endl;
        return 1;
    }
    cout << "Secilen Element: " << elementName[x - 1] << endl;
    cout << "Hacim (L): ";
    double hacimInput;
    cin >> hacimInput;
    cout << "Kutle (g): ";
    double kutleInput;
    cin >> kutleInput;
    cout << "Molar Kutle (g/mol): ";
    int hacimResult = hacim(hacimInput);
    int kutleResult = kutle(kutleInput);
	double molResult = mol(kutleInput, atomicNumber[x - 1]);
    cout << "Hacim (mL): " << hacimResult << endl;
    cout << "Kutle (mg): " << kutleResult << endl;
    cout << "Mol Sayisi: " << molResult << endl;
	return 0;
}