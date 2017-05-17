#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>


using namespace std;

int main()
{

    //generazione tabella
    ofstream tabAnagrafica("Nomi.sql");
    tabAnagrafica << "CREATE TABLE UTENTI (" <<endl;
    tabAnagrafica << "\tIDUtente int," << endl;
    tabAnagrafica << "\tNome VARCHAR(40)," << endl;
    tabAnagrafica << "\tCognome VARCHAR(40)," << endl;
    tabAnagrafica << "\tIndirizzo VARCHAR(100)," << endl;
    tabAnagrafica << "\tCitta VARCHAR(30)," << endl;
    tabAnagrafica << "\tRedditoAnnuo DECIMAL(12,2)" << endl;
    tabAnagrafica << ");"<< endl;

    //vettore dati Nome
    string nomiutenti[] = {"Mario","Luca","Lucia","Paolo","Giovanni","Pietro","Anna","Raffaele","Antonio","Luigi","Marco","Paola","Michela","Michele","Maria"\
                        ,"Giovanna","Pasquale","Rita","Teresa","Elena"};
    //vettore dati Cognome
    string cognomi[] = {"Rossi","Rossini","Verdi","Bianchi","Mariani","Esposito","Nardini","Renzi","Matteoli","Alessandrini","Marini","Pescatori","Lanari",\
                        "Nievo","Piccolomini","Della Santa","Roveri","Morara","Pisani","Latella"};
    //vettore dati Indirizzi
    string prefissi[] = {"Corso ","Via ","Viale ","Piazza ","Piazzale "};

    //vettore indirizzi
    string indirizzi[] ={"Garibaldi","Mazzini","Matteotti","Bixio","Cavour","Kennedy","Pertini","Indipendenza","XX Settembre","XI Febbraio","Trieste",\
                        "Italia","Roma","Liguria","Fiume","Gorizia","Abissinia","Vasari","Arno","Tevere"};
    //vettore dati citta
    string citta[] = {"Roma","Milano","Torino","Pesaro","Ancona","Macerata","Napoli","Torino","Venezia","Bari","Palermo","Perugia","Viterbo","Potenza"\
                    ,"Firenze","Treviso","Padova","Rovigo","Brescia","Livorno"};

    //inizializzazione numeri casuali
    srand(time(NULL));

    //query di inserimento
     tabAnagrafica << "INSERT INTO UTENTI (IDUtente, Nome, Cognome, Indirizzo, Citta, RedditoAnnuo) "<< endl;
     tabAnagrafica << "VALUES " << endl;


    //generazione dati
    int numRecord = 0; //numero dei record da creare
    do
    {
        cout << "Inserisci numero dei record da creare " ;
        cin >> numRecord;
    } while (numRecord <= 0);

    int nome = 0;
    int cognome = 0;
    int pref = 0;
    int indirizzo = 0;
    int c = 0;
    int nciv = 0;
    int redditoint = 0; //parte intera del reddito
    int redditodec = 0; //centesimi
    float perc = 0.0;
    for (int i = 0; i <= numRecord;i++)
    {
        nome = rand()%20;
        cognome = rand()%20;
        pref = rand()%5;
        indirizzo = rand()%20;
        c = rand()%20;
        nciv = rand()%200 + 1;
        redditoint = rand()%20000 + 1000;
        redditodec = rand()%99;
        tabAnagrafica << "(" << i << ",'" << nomiutenti[nome] << "','" << cognomi[cognome] << "','" << prefissi[pref] << indirizzi[indirizzo];
        tabAnagrafica << " " << nciv <<"','" << citta[c] << "'," << redditoint << "." << redditodec << ")";
        ;
        cout << "record creati : " << i << " di " << numRecord << endl;
        if(i < numRecord)
            tabAnagrafica <<"," << endl;
        else
            tabAnagrafica << ";" << endl;
    }

    return 0;
}
