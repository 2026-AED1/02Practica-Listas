#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<int> ordena(vector<int> lista) {
    
}

int main() {
    string linea;
    getline(cin, linea);

    stringstream ss(linea);
    vector<int> lista;
    int x;

    while (ss >> x) {
        lista.push_back(x);
    }

    lista = ordena(lista);

    for (int i = 0; i < (int)lista.size(); i++) {
        if (i > 0) cout << " ";
        cout << lista[i];
    }

    cout << endl;

    return 0;
}