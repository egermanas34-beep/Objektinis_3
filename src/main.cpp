
#include "funkcijos.h" 
#include <windows.h>// Įtraukiame Windows.h biblioteką, kad galėtume naudoti funkcijas, susijusias su konsolės kodavimo nustatymais


int main(){
    SetConsoleOutputCP(CP_UTF8); //! Nustatome konsolės išvesties kodavimą į UTF-8, kad būtų galima teisingai rodyti lietuviškus simbolius
    SetConsoleCP(CP_UTF8); //! Nustatome konsolės įvesties kodavimą į UTF-8, kad būtų galima teisingai skaityti lietuviškus simbolius iš vartotojo įvesties
    
system("powershell ls studentai*.txt");
   std::ios::sync_with_stdio(false);//! Išjungia sinchronizaciją tarp C++ srautų ir C srautų, kad pagerintų įvesties/išvesties našumą
    //std::ios::sync_with_stdio(false) funkcija yra naudojama norint pagerinti įvesties/išvesties našumą,
    // išjungiant sinchronizaciją tarp C++ srautų (std::cin, std::cout) ir C srautų (scanf, printf).
    // Tai leidžia C++ srautams veikti greičiau, nes jie nebėra priversti sinchronizuotis su C srautais.
    // Tačiau tai reiškia, kad negalima naudoti C srautų funkcijų kartu su C++ srautais, nes tai gali sukelti nenumatytų rezultatų,
    // todėl rekomenduojama naudoti tik vieną tipą srautų visame programoje. pvz. jei naudojate std::cout, venkite naudoti printf ir atvirkščiai.

    
    Studentas A;
    StudentuGrupe grupe;
    StudentuGrupe vargsiukai;
    StudentuGrupe smartukai;
    int pasirinkimas;
    int isvedimas;
    int m;
  //Zmogus z;
    cout<<"Ką jūs norite padaryti? \n 1 - rankiniu būdu įvesti studentus \n 2 - generuoti tik pažymius \n 3 - generuoti vardus su pažymiais \n 4 - nuskaityti iš failo \n 5 -baigti darbą \n 6 -generuoti failą \n 7- testuoti generuojant failus(daryti kai nera failų) \n 8 - testuoti visa programa \n 9 - testuoti klasės metodus \n Pasirinkite: ";
    int veiksmas = skaiciu_mastelis("", 1, 9);
    if(veiksmas==5) return 0;
    if(veiksmas==6)
   {int n =skaiciu_mastelis("Kiek yra studentų? ", 1, 100000);
    failuGeneravimas( n); return 0;}
    if(veiksmas==7) {tyrimasFailoKurimas(); return 0;}
    if(veiksmas==8) {tyrimasVisasProcesas(); return 0;}
    if(veiksmas==9) {tyrimasKlasesMetodams(); return 0;}
    cout<<"Kaip norite apskaičiuoti galutinį balą? \n 1 - pagal vidurkį \n 2 - pagal medianą \n Pasirinkite: ";
    pasirinkimas = skaiciu_mastelis("", 1, 2);  
    cout<<"Kaip norite rikiuoti rezultatus? \n 1 - pagal vardą \n 2 - pagal pavardę \n 3 - pagal galutinį balą \n Pasirinkite: ";
    int rik = skaiciu_mastelis("", 1, 3);
    cout<<"Kaip norite išvesti rezultatus? \n 1 - į ekraną \n 2 - į failą \n Pasirinkite: ";
    isvedimas = skaiciu_mastelis("", 1, 2);
    if(veiksmas==1) inputas(A, grupe, pasirinkimas);
    else if(veiksmas==2) generavimasSk(A, grupe, pasirinkimas);
    else if(veiksmas==3) generavimasVisko(A, grupe, pasirinkimas);
    else if (veiksmas==4) {
        string read_vardas;
        cout << "Iveskite failo pavadinimą iš sarašo (pvz. studentai10000.txt): ";
        cin >> read_vardas;
        grupe = bufer_nusk( read_vardas,pasirinkimas, m);
    }
   

int rus = skaiciu_mastelis("Pasirinkite studentu skirstymo strategija (1, 2 arba 3): ", 1, 3);

    
    rikiavimas(grupe, rik);
    studentoLygis(grupe, vargsiukai, smartukai, rus);
   outputas(vargsiukai, smartukai, pasirinkimas, isvedimas, m);
   
    return 0;
}


