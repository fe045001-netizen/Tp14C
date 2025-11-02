#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

void lireFichier(const string& nomFichier) {
    ifstream fichier(nomFichier.c_str());
    if (!fichier.is_open()) {
        throw runtime_error(" impossible d'ouvrir le fichier '" + nomFichier + "'.");
    }

    string ligne;
    cout << "Contenu du fichier '" << nomFichier << "' :" << endl;

    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }

    fichier.close();
}

int main() {
    string nom;
    cout << " le nom du fichier : ";
    cin >> nom;

    try {
        lireFichier(nom);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

