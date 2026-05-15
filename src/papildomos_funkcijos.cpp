#include "funkcijos.h"

template <typename Container, typename Compare>//! Templatizuota funkcija rikiuoti, kuri naudoja std::sort algoritmą, kad rikiuotų bet kokio tipo konteinerį (vector, deque) pagal pateiktą comparatorių.
static void rikiuoti(Container &grupe, Compare comp) //! Container yra bet kokio tipo konteineris, o Compare yra funkcija, kuri nurodo, kaip rikiuoti elementus
{
    sort(grupe.begin(), grupe.end(), comp);//! sort algoritmas, kuris rikiuoja elementus nuo begin() iki end() pagal comp funkciją, kuri yra lambda funkcija, nurodanti rikiavimo kriterijų (pvz., pagal vardą, pavardę ar galutinį balą)
}
template <typename Compare>//! Templatizuota funkcija rikiuoti, kuri naudoja std::list::sort metodą, kad rikiuotų std::list konteinerį pagal pateiktą comparatorių.
static void rikiuoti(std::list<Studentas> &grupe, Compare comp) //! Specializacija funkcijai rikiuoti, skirta std::list konteineriui, nes std::list turi savo sort metodą, kuris yra optimizuotas darbui su sąrašu.
{
    grupe.sort(comp);
}
//! Funkcija rikiavimui, kuri naudoja lambda funkcijas kaip comparatorius, kad galėtų rikiuoti pagal vardą, pavardę arba galutinį balą, priklausomai nuo vartotojo pasirinkimo.
void rikiavimas(StudentuGrupe &grupe, int &rik)
{
    // Lambda comparatoriai
    auto compare_vardas = [](const Studentas &a, const Studentas &b) { return a.getVardas() > b.getVardas(); };
    auto compare_pavarde = [](const Studentas &a, const Studentas &b) { return a.getPavarde() > b.getPavarde(); };
    auto compare_rez = [](const Studentas &a, const Studentas &b) { return a.Rezultatas() > b.Rezultatas(); };

    //! list naudos list::sort(), o vector/deque naudos std::sort()
    if (rik == 1) {
        rikiuoti(grupe, compare_vardas);
    } else if (rik == 2) {
        rikiuoti(grupe, compare_pavarde);
    } else if (rik == 3) {
        rikiuoti(grupe, compare_rez);
    }
}
int skaiciu_mastelis(const string &prompt, int min_val, int max_val)
{
    int value;
    while (true) {
        try 
        {
            cout<<prompt;
            cin >> value;
            if(cin.fail())
            {
                throw std::runtime_error("Įvestas ne skaičius");
            }
            if (value < min_val || value > max_val) {
                throw std::out_of_range("Įvestas skaičius už intervalo ribų");

            }
            return value;
        }
        
        catch(const std::runtime_error& e)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Klaida: "<<e.what()<<". Bandykite dar karta.\n";
                
        }
        catch(const std::out_of_range& e)
        {
            cout<<"Klaida: "<<e.what()<<". Turi būti nuo "<<min_val<<" iki "<<max_val<<".\n";
                
        }
   
    }
    
}
void studentoLygis(StudentuGrupe &grupe, StudentuGrupe &vargsiukai, StudentuGrupe &smartukai, int &rusiavimas)
{
  // jeigu nori spausdinti i failus, komentuok situos
     vargsiukai.clear();
     smartukai.clear();
   
    if (rusiavimas == 1) 
    {
        //! 1 strategija: visi studentai lieka grupes, kopijuojami į vargsiukai ir smartukai
        for (const auto &A : grupe) 
        {
            if (A.Rezultatas() < 5.0) vargsiukai.push_back(A);
            else smartukai.push_back(A);
        }
    }
    else if (rusiavimas == 2) 
    {
        //! 2 strategija: vienu perėjimu vargsiukus perkeliame, o iš grupes ištriname.
       for(auto it = grupe.rbegin(); it != grupe.rend(); ++it) // Naudojame reverse iterator, kad galėtume saugiai trinti elementus iš grupės, nes std::vector ir std::deque iteratoriaus invalidacija įvyksta, kai triname elementus, o reverse iterator leidžia mums saugiai iteruoti atgal ir trinti elementus be rizikos sugadinti iteratorių.
       {
           const auto &A = *it;
       
            if(A.Rezultatas() < 5.0) {vargsiukai.push_back(A); grupe.pop_back();}
        }
         smartukai = grupe; // likusi grupė yra smartukai
    }
   else if( rusiavimas == 3)
   {
       //! 3 strategija: dalijame su partition, vargsiukus perkeliame, grupėje paliekame tik smartukus.
       auto border = std::partition(grupe.begin(), grupe.end(), [](const Studentas &A) { return A.Rezultatas() >= 5.0; }); 

       std::copy(border, grupe.end(), std::back_inserter(vargsiukai)); //! Kopijuojame vargsiukus į atskirą konteinerį, naudojant std::copy ir std::back_inserter, kuris prideda elementus į vargsiukai konteinerio pabaigą.
       grupe.erase(border, grupe.end());//! Iš grupės ištriname vargsiukus, palikdami tik smartukus.
       smartukai = grupe;
   }
   //jeigu nori, kad nespausdintu i failus, komentuok situos
   //vargsiukai.clear();
    //smartukai.clear();
   
}
string vardo_skaitymas(const string &prompt)
{
    string value;
    while (true) {
        try 
        {
            cout<<prompt;
            cin>>value;
            if(cin.fail())
            {
                throw std::runtime_error("Įvesties klaida");

            }

            bool has_alpha = false; //! Kintamasis, kuris nurodo, ar įvestyje yra bent viena raidė
            bool all_alnum = true; //! Kintamasis, kuris nurodo, ar visi įvesties simboliai yra raidės arba skaičiai

            for(unsigned char ch : value) 
            {
                if(std::isalpha(ch)) //! std::isalpha funkcija tikrina, ar simbolis yra raidė
                {
                    has_alpha = true;
                }
                else if(!std::isalnum(ch)) //! std::isalnum funkcija tikrina, ar simbolis yra raidė arba skaičius  
                {
                    all_alnum = false;
                    break;
                }
            }
            if(!all_alnum ||!has_alpha)
            {
                throw std::invalid_argument("Turi būti bent viena raidė ir tik raidės bei skaičiai");    

            }
            return value;
        }
            catch(const std::runtime_error& e)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //! std::numeric_limits<std::streamsize>::max() - tai funkcija, kuri grąžina didžiausią galimą streamsize reikšmę, kuri yra naudojama kaip argumentas ignore funkcijai, kad būtų ignoruojami visi likę simboliai įvesties sraute iki naujos eilutės simbolio ('\n').
                cout<<"Klaida: "<<e.what()<<". Bandykite dar karta.\n";
                    
            }
            catch(const std::invalid_argument& e)
            {
                cout<<"Klaida: "<<e.what()<<". Bandykite dar karta.\n";
                    
            }
        
    }
}
double skaiciu_skaitymas(const string &prompt, double min_val, double max_val)
{
    double value;
    while (true) {
        try 
        {
            cout<<prompt;
            cin >> value;
            if(cin.fail())
            {
                throw std::runtime_error("Įvestas ne skaičius");
            }
            if (value < min_val || value > max_val) {
                throw std::out_of_range("Įvestas skaičius už intervalo ribų");

            }
            return value;
        }
        
        catch(const std::runtime_error& e)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Klaida: "<<e.what()<<". Bandykite dar karta.\n";
                
        }
        catch(const std::out_of_range& e)
        {
            cout<<"Klaida: "<<e.what()<<". Turi būti nuo "<<min_val<<" iki "<<max_val<<".\n";
                
        }
   
    }
    
}
