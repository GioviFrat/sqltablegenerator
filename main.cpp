#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ofstream tabAnagrafica("Nomi.sql");
    tabAnagrafica << "CREATE TABLE UTENTI (" <<endl;
    tabAnagrafica << "\tIDUtente int," << endl;
    tabAnagrafica << "\tNome VARCHAR(40)," << endl;
    tabAnagrafica << "\tCognome VARCHAR(40)," << endl;
    tabAnagrafica << "\tIndirizzo VARCHAR(100)," << endl;
    tabAnagrafica << "\tCittà VARCHAR(30)" << endl;
    tabAnagrafica << ");"<< endl;
    return 0;
}
