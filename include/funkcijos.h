#pragma once
#include "studentas.h"



void inputas(Studentas &A, StudentuGrupe &grupe, int &pasirinkimas);
void outputas(const StudentuGrupe &vargsiukai, const StudentuGrupe &smartukai, int &pasirinkimas, int &isvedimas, int &m);
StudentuGrupe bufer_nusk(string &read_vardas,int &pasirinkimas, int &m);
void generavimasSk(Studentas &A, StudentuGrupe &grupe, int &pasirinkimas);
void generavimasVisko(Studentas &A, StudentuGrupe &grupe, int &pasirinkimas);
void failuGeneravimas( int &n);

int skaiciu_mastelis(const string &prompt, int min_val, int max_val);
string vardo_skaitymas(const string &prompt);
double skaiciu_skaitymas(const string &prompt, double min_val, double max_val);
void rikiavimas(StudentuGrupe &grupe, int &pasirinkimas);
void studentoLygis(StudentuGrupe &grupe, StudentuGrupe &vargsiukai, StudentuGrupe &smartukai, int &rusiavimas);
void tyrimasFailoKurimas();
void tyrimasVisasProcesas();
void tyrimasKlasesMetodams();