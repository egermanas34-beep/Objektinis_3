
#pragma once
#include "bibliotekos.h"

int skaiciu_mastelis(const string &prompt, int min_val, int max_val);
string vardo_skaitymas(const string &prompt);

//! Pagrindine klase zmogus
class Zmogus {
  protected:
  string Vardas;
  string Pavarde;
  Zmogus(string v = "", string p = "") : Vardas{v}, Pavarde{p} { Vardas=v; Pavarde=p; /*std::cout<<"Zmogus K.\n";*/ }
  
  public:
  virtual string getVardas() const { return Vardas; }
  virtual string getPavarde() const { return Pavarde; }
 
//! virtual'i funkcija
    virtual void whoAmI() const = 0;
  //1 Overloadint'a (kita) virtuali whoAmI() funkcija
    virtual std::ostream& whoAmI(std::ostream& out) const {
        out << "Aš esu " << Vardas << " iš Base klasės\n";
        return out;
    }
  //! Overloadint'as operator<< kaip friend funkcija, o dešininis operandas yra Base&
    friend std::ostream& operator<<(std::ostream &out, const Zmogus &z) {
        // Visą darbą atliks whoAmI() funkcija, kuri yra virtuali!
        return z.whoAmI(out);
    }
  virtual ~Zmogus() {Vardas = ""; Pavarde = "";}; //!destruktorius
 
};

//! Klase studentas, kuri yra paveldeta is zmogaus klases
class Studentas : public Zmogus {
  private:
  //string Vardas;
  //string Pavarde;
  vector<int> paz;
  int egz;
  double vidurkis;
  double mediana;
  double rez;
  string lygis;
public:
 

  Studentas();//! default konstruktorius
 
void whoAmI() const { std::cout << "Aš esu " << getVardas() << " iš Studentas klasės\n"; }
    virtual std::ostream& whoAmI(std::ostream& out) const {
        out << "Aš esu " << getVardas() << " iš Studentas klasės\n";
        return out;
    }

  const vector<int>& getPaz() const { return paz; } //! getteris
  int getEgz() const { return egz; } //! getteris
  double Rezultatas() const {return rez;} //! getteris
  std::istream& readStudent(std::istream&); //! setteris
  
  void setVardas(const string& v) {
    Vardas = v;
  }
  void setPavarde(const string& p) {
    Pavarde = p;
  }
  void setPaz(int p) {
    paz.push_back(p);
  }
  void setEgz(int e) {
    egz = e;
  }
  

  Studentas(const Studentas& s); //! copy konstruktorius
  Studentas(Studentas&& s); //! move konstruktorius
  Studentas& operator=(const Studentas& s); //! copy priskyrimas = 
  Studentas& operator=(Studentas&& s); //! move priskyrimas =
  ~Studentas(); //! destruktorius


  void nuskaityti_ranka(int max_pazymiu);
  void nuskaityti_is_eilutes(std::istream& is);
  void skaiciuoti_rezultata(int pasirinkimas);
  void isvalyti_pazymius();
  friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
  friend std::istream& operator>>(std::istream& is, Studentas& s);
 friend std::ofstream& operator<<(std::ofstream& os, const Studentas& s);
};




//! sukurti alias StudentuGrupe, kuri galima nuadoti kaip vektoriu, lista arba deque tipo konteineri, tam, kad patikrinti programos sparta, su skirtingo tipo konteineriais.
using StudentuGrupe = std::vector<Studentas>;  // vector
//using StudentuGrupe = std::list<Studentas>;      // list
//using StudentuGrupe = std::deque<Studentas>;   // deque
const int Maxpazymiu=20;
const int Maxstudentu=10000000;