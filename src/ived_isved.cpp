#include "funkcijos.h"


StudentuGrupe bufer_nusk(string &read_vardas,int &pasirinkimas, int &m)
{
    StudentuGrupe grupe;// Sukuriame tuščią studentų grupės vektorių
   while(true)
    {
    try
    { m=0;
        
        std::ifstream open_f(read_vardas);// Atidarome failą skaitymui
        if (!open_f.is_open())
        {
            throw std::runtime_error("Nepavyko atidaryti failo " + read_vardas);//jeigu failas nebuvo atidarytas, ismeta klaida
        
        }
       // auto start = std::chrono::high_resolution_clock::now();// Pradedame matuoti laiką
        /* std::chrono::high_resolution_clock::now() funkcija grąžina dabartinį laiką, 
        kuris bus naudojamas vėliau apskaičiuoti, kiek laiko užtruko failo nuskaitymas ir apdorojimas*/
        string eil;// Sukuriame eilutės kintamąjį, kuris bus naudojamas skaityti kiekvieną eilutę iš failo
        std::getline(open_f, eil);// Skaitome pirmąją eilutę, kuri yra antraštė, ir ją ignoruojame

        while (std::getline(open_f, eil)) // Skaitome kiekvieną likusią eilutę iš failo, kol pasiekiame failo pabaigą
        {
            if (eil.empty()) // Tikriname, ar eilutė yra tuščia, ir jei taip, praleidžiame ją
            {
                continue;
            }

            std::stringstream ss(eil);//! Sukuriame stringstream objektą, kuris leis mums lengvai išskaidyti eilutę į atskirus žodžius ir skaičius
            Studentas A;
           ss>>A; //! Skaitome eilutę į Studentas objektą per klasės metodą
            if (A.getVardas().empty() || A.getPavarde().empty()) 
            {
                continue;
            }

            A.skaiciuoti_rezultata(pasirinkimas);
        
            A.isvalyti_pazymius(); //! Išvalome pažymių vektorių, kad jis būtų tuščias prieš kitą studento įvedimą
            
            grupe.push_back(A);
             m++;
        }

        //std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;// Apskaičiuojame, kiek laiko praėjo nuo pradžios iki dabar, ir išsaugome šį laiką diff kintamajame
        //std::chrono::duration<double> yra tipas, kuris saugo laiką sekundėmis kaip double reikšmę, o diff.count() grąžina šią reikšmę, kurią mes išvedame į ekraną
        //cout << "Failo nuskaitymas ir apdorojimas uztruko: " << diff.count() << " sekundziu." << endl;
        open_f.close();
        return grupe;
    }   
    catch(const std::runtime_error& e)
    {
        cout<<"Klaida: "<<e.what()<<". Patikrinkite ar failas egzistuoja ir bandykite dar kartą. \n";
       
    }
}
}
void inputas(Studentas &A, StudentuGrupe &grupe, int &pasirinkimas)
{
    int m = 1; // Pradinis studentų kiekis, nustatomas į 1, kad įvesties ciklas prasidėtų
    
    while (m!=0)
    {
        A.nuskaityti_ranka(Maxpazymiu); //! Rankinis įvedimas per klasės metodą
        A.skaiciuoti_rezultata(pasirinkimas);
        grupe.push_back(A);//! Pridedame studentą į grupę
        A.isvalyti_pazymius();//! Išvalome pažymių vektorių, kad jis būtų tuščias prieš kitą studento įvedimą
        cout<<"Jei norite ivesti dar viena studenta, iveskite 1, jei ne - 0: ";
        cin>>m;
    }
}
void outputas(const StudentuGrupe &vargsiukai, const StudentuGrupe &smartukai, int &pasirinkimas, int &isvedimas, int &m)
{
    
    auto start = std::chrono::high_resolution_clock::now();//! Pradedame matuoti laiką
    /*! std::chrono::high_resolution_clock::now() funkcija grąžina dabartinį laiką, 
    kuris bus naudojamas vėliau apskaičiuoti, kiek laiko užtruko failo nuskaitymas ir apdorojimas*/
    if(isvedimas==2)
    {
        std::ofstream out_f("vargsiukai"+std::to_string(m)+".txt");
        std::ofstream out_s("smartukai"+std::to_string(m)+".txt");
        
        if(pasirinkimas==1) 
        {
            out_f << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(vid.):" << '\n';
            out_f << " -------------------------------------------------------------------------------------------------------------------" << '\n';
            out_f << fixed << setprecision(2);
            for (const auto &A : vargsiukai)
            {
                out_f << A << '\n';
               
            }
        }
       else
        {
            out_f << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(med.):" << '\n';
            out_f << " -------------------------------------------------------------------------------------------------------------------" << '\n';
            out_f << fixed << setprecision(2);
            for (const auto &A : vargsiukai)
            {
                out_f << A << '\n';
                
            }
        }
         if(pasirinkimas==1) 
        {
            out_s << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(vid.):" << '\n';
            out_s << " -------------------------------------------------------------------------------------------------------------------" << '\n';
            out_s << fixed << setprecision(2);
            for (const auto &A : smartukai)
            {
                out_s << A << '\n';
               
            }
        }
       else
        {
            out_s << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(med.):" << '\n';
            out_s << " -------------------------------------------------------------------------------------------------------------------" << '\n';
            out_s << fixed << setprecision(2);
            for (const auto &A : smartukai)
            {
                out_s << A << '\n';
                
            }
        }
        
        
       cout<<"Rezultatai išsaugoti failuose vargsiukai"+std::to_string(m)+".txt ir smartukai"+std::to_string(m)+".txt"<<endl;
       std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;//! Apskaičiuojame, kiek laiko praėjo nuo pradžios iki dabar, ir išsaugome šį laiką diff kintamajame
        //!std::chrono::duration<double> yra tipas, kuris saugo laiką sekundėmis kaip double reikšmę, o diff.count() grąžina šią reikšmę, kurią mes išvedame į ekraną
        cout << "Duomenų išvedimas užtruko: " << diff.count() << " sekundžių." << endl;
        out_f.close();
        out_s.close();
        
       return;
    }
   

    
    if (pasirinkimas == 1)
    {
        cout << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(vid.):" << '\n';
    }
    else
    {
        cout << left << setw(15) << "Vardas:" << left << setw(30) << "Pavardė:" << left << setw(45) << "Galutinis(med.):" << '\n';
    }
    cout << " -------------------------------------------------------------------------------------------------------------------" << '\n';
    cout << "Vargsiukai:" << '\n';
    for (const auto &A : vargsiukai)
    {
        cout << A << '\n';
    }
    cout << '\n' << "Smartukai:" << '\n';
    for (const auto &A : smartukai)
    {
        cout << A << '\n';
    }

     std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;//! Apskaičiuojame, kiek laiko praėjo nuo pradžios iki dabar, ir išsaugome šį laiką diff kintamajame
        //!std::chrono::duration<double> yra tipas, kuris saugo laiką sekundėmis kaip double reikšmę, o diff.count() grąžina šią reikšmę, kurią mes išvedame į ekraną
        cout << "Duomenų išvedimas užtruko: " << diff.count() << " sekundžių." << endl;
    
}