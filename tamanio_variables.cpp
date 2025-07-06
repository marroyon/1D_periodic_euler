#include <iostream>
#include <vector>

using namespace std;

// Nueva estructura personalizada
struct DatosSensor {
    char id[3];             // identificador (3 caracteres)
    int muestras[6];        // 6 enteros
    float valores[2];       // 2 floats
    double calibracion;     // 1 double
};

int main() {
    // Tamaños de tipos básicos
    cout << "Tipo bool: "   << sizeof(bool)   << " bytes" << endl;
    cout << "Tipo char: "   << sizeof(char)   << " bytes" << endl;
    cout << "Tipo int: "    << sizeof(int)    << " bytes" << endl;
    cout << "Tipo float: "  << sizeof(float)  << " bytes" << endl;
    cout << "Tipo double: " << sizeof(double) << " bytes" << endl << endl;

    // Tamaño de la estructura personalizada
    cout << "Estructura DatosSensor: " << sizeof(DatosSensor) << " bytes" << endl << endl;

    // Tamaño de un vector float
    vector<float> medidas = {9.8f, 7.2f, 6.1f, 4.3f};
    cout << "std::vector<float>: " << sizeof(medidas) << " bytes" << endl;

    return 0;
}
