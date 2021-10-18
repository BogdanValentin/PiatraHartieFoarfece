#include <iostream>
#include <cstdlib> // librarie pentru alegerea la intamplare.
#include <cstring> // librarie pentru functii legate de caractere.
using namespace std;

int main()
{
    cout << "Bun venit la jocul Piatra, hartie, foarfece!\nAveti optiunea de a alege intre cele 3 optiuni: \n";
    cout << "-Piatra\n-Hartie\n-Foarfece\n";
    char stopper = 'y', userinput[100], cpuchoice[100]; // merge si cu [8] doar ca daca scrii mai mult trece peste pasi (si asa nu e nimeni nebun sa scrie mai mult de 100 de caractere).
    int random, aux;
    unsigned int i; // il declar unsigned pt ca apare un avertisment la for-ul de pe rand 21.

    while (stopper == 'y')
    {
        aux = -5; // poate sa ia doar 0,1 sau 2, astfel ca -5 este valoarea in caz ca nu trece de checkuri.
        do {

            cout << "Alegerea dvs.: ";
            cin >> userinput;
            for (i = 0; i < strlen(userinput); i++)
                if (userinput[i] < 97)                 // daca litera de pe poz i este majuscula
                    userinput[i] = userinput[i] + 32; // o facem mica pentru a fi comparata mai usor.

            if (strcmp(userinput, "piatra") == 0)
                aux = 0;                              // daca alegerea noastra este piatra, aux primeste 0 samd.
            else if (strcmp(userinput, "hartie") == 0)
                aux = 1;
            else if (strcmp(userinput, "foarfece") == 0)
                aux = 2;
            else cout << "Eroare\n";                    // daca alegerea noastra nu este nici piatra, nici hartie, nici foarfece atunci eroare.

        } while (aux == -5);

        random = rand() % 3; // random primeste o valoarea aleatorie intre 0 si 2.

        if (random == 0) strcpy_s(cpuchoice, "piatra"); // cpuchoice primeste valoarea piatra, hartie sau foarfece dupa numarul random generat mai sus.
        else if (random == 1) strcpy_s(cpuchoice, "hartie");
        else if (random == 2) strcpy_s(cpuchoice, "foarfece");
        if (random == aux)
            cout << "Remiza! Tu ai ales " << userinput << ", iar calculatorul a ales " << cpuchoice << "!\n";
        else if ((aux == 0 && random == 1) || (aux == 1 && random == 2) || (aux == 2 && random == 0))
            cout << "Ai pierdut! Tu ai ales " << userinput << ", iar calculatorul a ales " << cpuchoice << "!\n";
        else if ((aux == 0 && random == 2) || (aux == 1 && random == 0) || (aux == 2 && random == 1))
            cout << "Ai castigat! Tu ai ales " << userinput << ", iar calculatorul a ales " << cpuchoice << "!\n";

        cout << "Doriti sa jucati in continuare? (Y/N)\n"; // acceptam o litera drept raspuns, daca sunt mai multe litere, return 0.
        cin >> stopper;                                    // daca litera nu este Y,y,N sau n atunci eroare si recitim.
        if ((stopper < 65 || stopper > 90) && (stopper < 97 || stopper > 122))
            do {
                cout << "Eroare\n";
                cout << "Doriti sa jucati in continuare? (Y/N)\n";
                cin >> stopper;
            } while ((stopper < 65 || stopper > 90) && (stopper < 97 || stopper > 122));
            if (stopper <= 97)
                stopper = stopper + 32;
    }
    return 0;
}
