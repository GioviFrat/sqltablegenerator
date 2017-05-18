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
    ofstream fileDB("Database.sql");
    fileDB << "CREATE TABLE UTENTI (" <<endl;
    fileDB << "\tIDUtente int," << endl;
    fileDB << "\tNome VARCHAR(40)," << endl;
    fileDB << "\tCognome VARCHAR(40)," << endl;
    fileDB << "\tIndirizzo VARCHAR(100)," << endl;
    fileDB << "\tCitta VARCHAR(30)," << endl;
    fileDB << "\tRedditoAnnuo DECIMAL(12,2)" << endl;
    fileDB << ");"<< endl;

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
     fileDB << "INSERT INTO UTENTI (IDUtente, Nome, Cognome, Indirizzo, Citta, RedditoAnnuo) "<< endl;
     fileDB << "VALUES " << endl;


    //generazione dati
    int numRecordUtenti = 0; //numero dei record da creare
    do
    {
        cout << "Inserisci numero dei record utenti da creare " ;
        cin >> numRecordUtenti;
    } while (numRecordUtenti <= 0);

    int nome = 0;
    int cognome = 0;
    int pref = 0;
    int indirizzo = 0;
    int c = 0;
    int nciv = 0;
    int redditoint = 0; //parte intera del reddito
    int redditodec = 0; //centesimi

    for (int i = 1; i <= numRecordUtenti;i++)
    {
        nome = rand()%20;
        cognome = rand()%20;
        pref = rand()%5;
        indirizzo = rand()%20;
        c = rand()%20;
        nciv = rand()%200 + 1;
        redditoint = rand()%20000 + 1000;
        redditodec = rand()%99;
        fileDB << "(" << i << ",'" << nomiutenti[nome] << "','" << cognomi[cognome] << "','" << prefissi[pref] << indirizzi[indirizzo];
        fileDB << " " << nciv <<"','" << citta[c] << "'," << redditoint << "." << redditodec << ")";

        cout << "record  utenti creati : " << i << " di " << numRecordUtenti << endl;
        if(i < numRecordUtenti)
            fileDB <<"," << endl;
        else
            fileDB << ";" << endl;
    }

    int numRecordProdotti = 0;
    //generazione tabella prodotti
    fileDB << "CREATE TABLE Prodotti (" <<endl;
    fileDB << "\tIDProdotto int," << endl;
    fileDB << "\tNomeProdotto VARCHAR(40)," << endl;
    fileDB << "\tDescrizione VARCHAR(40)," << endl;
    fileDB << "\tCategoria VARCHAR(100)," << endl;
    fileDB << "\tPrezzoListino DECIMAL(12,2)," << endl;
    fileDB << "\tProduttore VARCHAR(40)" << endl;
    fileDB << ");"<< endl;

    do
    {
        cout << "Inserisci numero dei record prodotti da creare " ;
        cin >> numRecordProdotti;
    } while (numRecordProdotti <= 0);

    string PrefissoNomiProdotti[] = {"Axiol","PeriDeluxe","SaniSan","Artemix","Fanrid","Articol","Unixel","Introfan","Eritex","Firstemol","Anovax",\
                                    "Uffisat","Ritrogan","UrtiMel","Wertol","Indenat","Storilas","Piref","Ondepan","Lumibat"};
    string suffissoNomiProdotti[] = {"Plus","Minus","Optimal","Excellence","Red","Black","White","Gold", "Silver","Medium", "Maximus", "Minimum",\
                                    "Limited","Expert","Entry","Middle","Work","Safe","Superior","Start"};

    string Categorie[] = {"Chimico","Biologico","Misto","Naturale","Artificiale"};

    string Produttori[] = {"Astra Inc.","Vega ltd","Miami snc","aria Spa","Ecosan Inc","Art Limited Inc","Rix Industries","Ultima Sas","Exital Inc","Ultra Chemical"};

    string Descrizione = "Descrizione generica";

        //query di inserimento tab prodotti
     fileDB << "INSERT INTO Prodotti (IDProdotto, NomeProdotto, Descrizione, Categoria, PrezzoListino, Produttore) "<< endl;
     fileDB << "VALUES " << endl;
    int numProdotto = 0;
    int nomep1 = 0;
    int nomep2 = 0;
    int ncat = 0;
    int plistino1 = 0;
    int plistinodec = 0;
    int nProduttore = 0;

    //generazione record tabella prodotti
    for (int i = 1; i <= numRecordProdotti;i++)
    {
        nomep1 = rand()%20;
        nomep2 = rand()%20;
        ncat = rand()%5;
        nProduttore = rand()%10;
        plistino1 = rand()%1000 +1;
        plistinodec = rand()%50;
        numProdotto = rand()%10;
        fileDB << "(" << i << ",'" << PrefissoNomiProdotti[nomep1] << " " << suffissoNomiProdotti[nomep2] << " " << numProdotto*10 << \
                        "','" << Descrizione << "','" << Categorie[ncat] << "'," << plistino1 << "." << plistinodec << ",'" << Produttori[nProduttore] << "')";
        cout << "record  prodotti creati : " << i << " di " << numRecordProdotti << endl;
        if(i < numRecordProdotti)
            fileDB <<"," << endl;
        else
            fileDB << ";" << endl;
    }

    //generazione chiavi primarie
    fileDB << "ALTER TABLE UTENTI " << endl;
    fileDB <<"ADD PRIMARY KEY(IDUtente);";

    fileDB << "ALTER TABLE Prodotti " << endl;
    fileDB <<"ADD PRIMARY KEY(IDProdotto);";

    //creazione tabella ordini
    fileDB << "CREATE TABLE ORDINI(" << endl;
    fileDB << "\tIDOrdine int," << endl;
    fileDB << "\tDataOrdine DATE," << endl;
    fileDB << "\tCodCliente int," << endl;
    fileDB << "\tCodProdotto int," << endl;
    fileDB << "\tQuantitativo int" << endl;
    fileDB << ");"<< endl;
    //chiave primaria
    fileDB << "ALTER TABLE ORDINI " << endl;
    fileDB <<"ADD PRIMARY KEY(IDOrdine);";
    //chiavi esterne
    fileDB << "ALTER TABLE ORDINI " << endl;
    fileDB << "ADD FOREIGN KEY(CodCliente) REFERENCES UTENTI(IDUtente);" << endl;

    fileDB << "ALTER TABLE ORDINI " << endl;
    fileDB << "ADD FOREIGN KEY(CodProdotto) REFERENCES PRODOTTI(IDProdotto);" << endl;

    //popolamento tabella ordini
    int numOrdini = 0;
    do
    {
        cout << "Inserisci numero dei record ordini da creare " ;
        cin >> numOrdini;
    } while (numOrdini <= 0);

    int codCliente = 0;
    int codProdotto = 0;
    int anno = 0;
    int mese = 0;
    int giorno = 0;
    int quantita = 0;

    fileDB << "INSERT INTO ORDINI(IDOrdine, DataOrdine,CodCliente,CodProdotto,Quantitativo)" << endl;
    fileDB << "VALUES" << endl;
    for (int i = 1; i <= numOrdini;i++)
    {
        codCliente = rand()%(numRecordUtenti - 1) + 1;
        codProdotto = rand()%(numRecordProdotti - 1) + 1;
        anno = 2000 + rand()%20;
        mese = rand()%12 + 1;
        giorno = rand()%27 + 1;
        quantita = rand()%100;
        fileDB << "(" << i << ",'" << anno << "-" << mese << "-" << giorno <<"'," << codCliente <<"," << codProdotto << "," << quantita << ")";
        if(i < numOrdini)
            fileDB <<"," << endl;
        else
            fileDB << ";" << endl;
        cout << "record  ordini creati : " << i << " di " << numOrdini << endl;
    }
    return 0;

}
