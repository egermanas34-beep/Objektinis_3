#include "funkcijos.h"

void tyrimasVektoriu()
{
    vector<int> v1;
    size_t perskristimu_skaicius1 = 0;
    for(int i = 0; i < 100000000; i++)
    {
        if(v1.capacity() == v1.size())
        {
            perskristimu_skaicius1++;
        }
        v1.push_back(i);
    }
    cout << "Perskristimų skaičius std::vector: " << perskristimu_skaicius1 << endl;
    Vector<int> v2;
    size_t perskristimu_skaicius2 = 0;
    for(int i = 0; i < 100000000; i++)
    {
        if(v2.capacity() == v2.size())
        {
            perskristimu_skaicius2++;
        }
        v2.push_back(i);
    }
    cout << "Perskristimų skaičius custom Vector: " << perskristimu_skaicius2 << endl;
}
void tyrimasKlasesMetodams()
{
     Studentas s1;
    s1.setVardas("Jonas");
    s1.setPavarde("Jonaitis");
    s1.setPaz(6);
    s1.setEgz(9);
    s1.skaiciuoti_rezultata(1); // Apskaičiuojame rezultatą pagal vidurkį

    Studentas s2;
    cout << "Įveskite studento vardą, pavardę, pažymius ir egzamino pažymį(paskutinis ivestas pazymis bus egzamino pazimys, o norint nutraukti ivedima iveskite 0):\n";
    cin>>s2;
    s2.skaiciuoti_rezultata(2); // Apskaičiuojame rezultatą pagal medianą

    std::cout << "Pradinis studentas s1:\n";
    std::cout << s1 << "\n";
    std::cout << "Pradinis studentas s2:\n";
    std::cout << s2 << "\n";
    //! 1. Copy konstruktoriaus testas
    Studentas s3{s1};
    std::cout << "Po copy konstruktoriaus (s3{s1}):\n";
    std::cout << "s1: " << s1 << "\n";
    std::cout << "s3: " << s3 << "\n";

    //! 2. Copy priskyrimo operatoriaus testas
    Studentas s4;
    s4 = s2;
    std::cout << "Po copy priskyrimo (s4 = s2):\n";
    std::cout << "s2: " << s2 << '\n';
    std::cout << "s4: " << s4 << "\n\n";

    //! 3. Move konstruktoriaus testas
    Studentas s5{std::move(s1)};
    std::cout << "Po move konstruktoriaus (s5{std::move(s1)}):\n";
    std::cout << "s5: " << s5 << "\n\n";
    std::cout<<"s1"<<s1<<"\n\n"; // s1 turėtų būti tuščias arba "nulintas" po move konstruktoriaus
    
    
    //! 4. Move priskyrimo operatoriaus testas
    Studentas s6;
    s6 = std::move(s2);
    std::cout << "Po move priskyrimo (s6 = std::move(s2)):\n";
    std::cout << "s6: " << s6 << "\n\n";

    Studentas s7; 
    s7.setVardas("Asta");
    s7.setPavarde("Astaitė");   
   s7.whoAmI();
    //Zmogus z1{"Tomas", "Tomaitis"};
   // std::cout << "Zmogus z1:\n";
   // std::cout << "Vardas: " << z1.getVardas() << ", Pavardė: " << z1.getPavarde() << "\n";
  
}


void tyrimasFailoKurimas() {
    vector<int> dydziai = {100000, 1000000}; 

    for (int n : dydziai) 
    {
        string failas = "studentai_" + std::to_string(n) + ".txt";

        auto pradzia = std::chrono::high_resolution_clock::now();
        failuGeneravimas(n);
        auto pabaiga = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> trukme = pabaiga - pradzia;
        cout << failas << " kurimo laikas: " << trukme.count() << " s\n";
    }
}
void tyrimasVisasProcesas() {
   vector<int> dydziai = { 100000, 1000000}; 

    for (int n : dydziai) 
    {
    
        string failas = "studentai_" + std::to_string(n) + ".txt";
        int pasirinkimas = 1;
        int rikiavimo_budas = 3;
        int isvedimas = 2;
        int rusiavimas = 3;

        auto pradzia = std::chrono::high_resolution_clock::now();
        StudentuGrupe grupe = bufer_nusk(failas, pasirinkimas, n); // Nuskaitome duomenis iš failo
        auto pabaiga1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> trukme = pabaiga1 - pradzia;
        cout << failas << " nuskaitymo ir apdorojimo laikas: " << trukme.count() << " s\n";
        rikiavimas(grupe, rikiavimo_budas); // Rikiuojame pagal galutinį balą
         auto pabaiga2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> rikiavimo_trukme = pabaiga2 - pabaiga1;
        cout << failas << " rikiavimo laikas mazejimo tvarka su sort funkcija: " << rikiavimo_trukme.count() << " s\n";

        StudentuGrupe vargsiukai;
        StudentuGrupe smartukai;
        studentoLygis(grupe, vargsiukai, smartukai, rusiavimas); // Skirstome į vargšus ir smartukus
        auto pabaiga3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> studentoLygio_trukme = pabaiga3 - pabaiga2;
        cout << failas << " studentų lygio nustatymo laikas: " << studentoLygio_trukme.count() << " s\n";

        outputas(vargsiukai, smartukai, pasirinkimas, isvedimas, n); // Išvedame į failus
        auto pabaiga4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> isvedimo_trukme = pabaiga4 - pabaiga3;
        cout << failas << " rezultatu isvedimo i faila laikas: " << isvedimo_trukme.count() << " s\n";
        std::chrono::duration<double> visa_trukme = pabaiga4 - pradzia;
        cout<<" \n";
        cout << failas << " visas proceso laikas: " << visa_trukme.count() << " s\n";
        cout << "-------------------------------------------------------------\n";
    }
}