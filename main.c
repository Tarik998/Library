#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define COMMAND_ADD_NEW_BOOK 1
#define COMMAND_DELETE_BOOK 2
#define COMMAND_CHECK_BOOK 3
#define COMMAND_RENT_BOOK 4
#define COMMAND_RETURN_BOOK 5
#define COMMAND_EXIT 6

//Maksimalni broj naslova
int MAX_BROJ_NASLOVA = 1000;

//Vlastiti tip koji predstavlja jedan naslov
struct Naslov
{
    char naslov[40];
    char autor[50];
    int broj_primjeraka;
};

//Pozivom ove funkcije program od korisnika oèekuje unos u formatu: Naslov|Autor|Broj primjeraka - može se iskorstiti pri dodavanju naslova
//Takoðer je moguæe unijeti naslov i u formatu: Naslov|Autor ali æe u tom sluèaju broj primjeraka postaviti na 0 - može se iskoristi pri brisanju/iznajmljivanju/vraæanju/pregledu naslova
struct Naslov ucitaj_naslov()
{
    struct Naslov naslov;

    char unos[100];
    char delim[] = "|";
    char * token;
    fflush(stdin);
    fgets(unos, 100, stdin);
    token = strtok(unos, delim);

    int i = 0;
    while(token != NULL)
    {
        if(i == 0)
        {
            strcpy(naslov.naslov, token);
        }
        else if(i == 1)
        {
            strcpy(naslov.autor, token);
        }
        else if(i == 2)
        {
            naslov.broj_primjeraka = atoi(token);
        }

        token = strtok(NULL, delim);
        i++;
    }
    return naslov;
}
struct Naslov vracanje_knjiga()
{
    struct Naslov naslov;

    char unos[100];
    char delim[] = "|";
    char * token;
    fflush(stdin);
    fgets(unos, 100, stdin);
    unos[strlen(unos)-1]='\0';
    token = strtok(unos, delim);

    int i = 0;
    while(token != NULL)
    {
        if(i == 0)
        {
            strcpy(naslov.naslov, token);
        }
        else if(i == 1)
        {
            strcpy(naslov.autor, token);
        }

        token = strtok(NULL, delim);
        i++;
    }
    return naslov;
}

struct Naslov naslovZaRentanje()
{
    struct Naslov naslov;

    char unos[100];
    char delim[] = "|";
    char * token;
    fflush(stdin);
    fgets(unos, 100, stdin);
    unos[strlen(unos)-1]='\0';
    token = strtok(unos, delim);

    int i = 0;
    while(token != NULL)
    {
        if(i == 0)
        {
            strcpy(naslov.naslov, token);
        }
        else if(i == 1)
        {
            strcpy(naslov.autor, token);
        }

        token = strtok(NULL, delim);
        i++;
    }
    return naslov;
}

//Funkcija koja uèitava sve naslove iz fajla te ih sprema u listu naslova koja je proslijeðena kao parametar
int ucitaj_sve_naslove_iz_fajla(struct Naslov * naslovi)
{
    struct Naslov naslov;

    char unos[100];
    int brojac = 0;
    FILE * fajl;
    char delim[] = "|";
    fajl = fopen("naslovi.txt", "r");

    if(fajl == NULL)
    {
        printf("Nije ucitalo fajl!\n");
        return 0;
    }
    fflush(stdin);
    while(fgets(unos, 100, fajl) != NULL)
    {
        struct Naslov naslov;
        if(brojac > MAX_BROJ_NASLOVA)
        {
            break;
        }
        int i = 0;

        char *token = strtok(unos, delim);
        while(token != NULL)
        {
            if(i == 0)
            {
                strcpy(naslov.naslov, token);

            }
            else if(i == 1)
            {
                strcpy(naslov.autor, token);

            }
            else if(i == 2)
            {
                naslov.broj_primjeraka = atoi(token);
            }

            token = strtok(NULL, delim);
            i++;
        }
        naslovi[brojac] = naslov;
        brojac++;
    }
    fclose(fajl);
    return brojac;
}

//Pomoæna funkcija koja printa jedan naslov, samo primjer, moguæe je da je potrebna modifikacija za upotrebu.
void printaj_naslov(struct Naslov naslov)
{
    printf("Ime naslova: %s, autor: %s, broj primjeraka: %d\n", naslov.naslov, naslov.autor, naslov.broj_primjeraka);
}


//Pomoæna funkcija koja printa sve naslove koristeæi pomoænu funkciju za printanje naslova. Takoðer pomoæna funkcija kao primjer kako se prolazi kroz naslove.
void printaj_sve_naslove(struct Naslov * naslovi, int broj_naslova)
{
    int i;
    for(i = 0; i < broj_naslova; i++)
    {
        printaj_naslov(naslovi[i]);
    }
}
int checkCommand(int komanda, int broj){

    if(komanda == broj){

        return TRUE;
    }

    return FALSE;
}

int selectCommand() {
    int command;

    printf("\n1 - Dodavanje naslova\n");
    printf("2 - Brisanje naslova\n");
    printf("3 - Provjera naslova\n");
    printf("4 - Iznajmljivanje primjerka\n");
    printf("5 - Vracanje primjerka\n");
    printf("6 - Izlaz\n");
    printf("\nUnesite broj komande: ");
    scanf("%d", &command);

    return command;
}

int isIncorrectCommandSelected(int odabrana_komanda){

    if(odabrana_komanda < 1 || odabrana_komanda > 6){
        return TRUE;
    }
    return FALSE;
}

int isCommandAddNewBookToLibrary(int selectedCommand) {
    return checkCommand(selectedCommand, COMMAND_ADD_NEW_BOOK);
}

int isCommandDeleteBookFromLibrary(int selectedCommand) {
    return checkCommand(selectedCommand, COMMAND_DELETE_BOOK);
}

int isCommandCheckTheBookInTheLibrary(int selectedCommand) {
    return checkCommand(selectedCommand, COMMAND_CHECK_BOOK);
}

int isCommandRentABookFromTheLibrary(int selectedCommand) {
    return checkCommand(selectedCommand, COMMAND_RENT_BOOK);
}

int isCommandReturnTheBookToTheLibrary(int selectedCommand) {
    return checkCommand(selectedCommand, COMMAND_RETURN_BOOK);
}

int isCommandExit(int selectedCommand) {
    return checkCommand(selectedCommand, COMMAND_EXIT);
}

int saveData() {

    return TRUE;
}

int loadData() {

    return FALSE;
}

int findTheBook(struct Naslov bookToFind, struct Naslov* books, int numberOfBooks) {
    for(int i = 0; i < numberOfBooks; i++) {
        if (strcmp(books[i].autor, bookToFind.autor) == 0 && strcmp(books[i].naslov, bookToFind.naslov) == 0) {
            return i;
        }
    }

    return -1;
}
int nadji_knjigu(struct Naslov nadjena_knjiga, struct Naslov *knjige, int broj_knjiga)
{
    for(int i = 0; i < broj_knjiga; i++)
    {
        if (strcmp(knjige[i].autor, nadjena_knjiga.autor) == 0 && strcmp(knjige[i].naslov, nadjena_knjiga.naslov) == 0)
        {
            return i;
        }
    }

    return -1;
}

int main(){

    struct Naslov books[1000];
    int broj_ucitanih_naslova = ucitaj_sve_naslove_iz_fajla(books);

    printf("Dobrodosli u skolsku biblioteku.\n");

    while(TRUE){

        int selectedCommand = selectCommand();

        if(isIncorrectCommandSelected(selectedCommand)) {
            printf("Unijeli ste pogresnu komandu.");
            continue;
        }

        if(isCommandExit(selectedCommand)){
            printf("Hvala na koristenju aplikacije. Dovidjenja.");
            FILE * fajl;
            fajl = fopen("naslovi.txt", "w");
                for(int i=0; i<broj_ucitanih_naslova; i++) {
                    fprintf(fajl, "%s|%s|%d\n", books[i].naslov, books[i].autor, books[i].broj_primjeraka);
                }
            fclose(fajl);
            return 0;
        }

        if(isCommandAddNewBookToLibrary(selectedCommand)) {

            printf("Unesite novi naslov u formatu: Naslov|Autor|Broj primjeraka\n");
            struct Naslov currentBook;
            currentBook = ucitaj_naslov();

            printaj_naslov(currentBook);

            int foundBookIndex = findTheBook(currentBook, books, broj_ucitanih_naslova);

            if (foundBookIndex == -1) {
                books[broj_ucitanih_naslova] = currentBook;
                broj_ucitanih_naslova += 1;
                printf("Uspjesno ste dodali naslov: %s\n", currentBook.naslov);
            } else {
                books[foundBookIndex].broj_primjeraka += currentBook.broj_primjeraka;
            }
        }

        if(isCommandDeleteBookFromLibrary(selectedCommand)){

            printf("Unesite naslov koji zelite obrisati: Naslov|Autor \n");
            struct Naslov deletedBook;
            deletedBook = naslovZaRentanje();

            int foundBookIndex = findTheBook(deletedBook, books, broj_ucitanih_naslova);

            if (foundBookIndex == -1) {
                printf("Nazalost navedeni naslov ne postoji u bazi.");
            } else {
                if (foundBookIndex < broj_ucitanih_naslova) {
                          broj_ucitanih_naslova = broj_ucitanih_naslova - 1;
                          for (int i = foundBookIndex; i < broj_ucitanih_naslova; i++)
                              books[i] = books[i+1];
                    printf("Uspjesno ste obrisali naslov %s .", deletedBook.naslov);
                }
            }
        }

        if(isCommandRentABookFromTheLibrary(selectedCommand)){

            printf("Unesite naslov koji zelite iznajmiti: Naslov|Autor \n");
            struct Naslov bookForRent;
            bookForRent = naslovZaRentanje();

            int foundBookIndex = findTheBook(bookForRent, books, broj_ucitanih_naslova);

            if (foundBookIndex == -1) {
                printf("Nazalost navedeni naslov ne postoji u bazi.");
            } else {
                if(books[foundBookIndex].broj_primjeraka>0) {
                    books[foundBookIndex].broj_primjeraka=books[foundBookIndex].broj_primjeraka - 1;
                    printf("Uspjesno ste iznajmili naslov %s, preostalo je: %d primjerka tog naslova.\n", books[foundBookIndex].naslov, books[foundBookIndex].broj_primjeraka);
                } else {
                    printf("Nazalost nema raspolozivih primjeraka naslova %s.", bookForRent.naslov);
                }
            }
        }
         if(isCommandReturnTheBookToTheLibrary(selectedCommand))
        {

            printf("Unesite naslov koji zelite vratiti: Naslov|Autor: \n");
            struct Naslov knjiga_za_vracanje;
            knjiga_za_vracanje = vracanje_knjiga();


            int nadjeni_index_knjige = nadji_knjigu(knjiga_za_vracanje, books, broj_ucitanih_naslova);



            if( nadjeni_index_knjige == -1)
            {
                printf("Nazalost navedeni naslov ne postoji u bazi.");
            }
            else
            {
                    (books[nadjeni_index_knjige].broj_primjeraka > 0);
                    books[nadjeni_index_knjige]. broj_primjeraka = books[nadjeni_index_knjige]. broj_primjeraka +1;
                    printf("Uspjesno ste vratili naslov %s, sada na raspolaganju ima: %d primjeraka tog naslova.\n", books[nadjeni_index_knjige].naslov, books[nadjeni_index_knjige].broj_primjeraka);
            }

        }
    }
     return 0;
}
