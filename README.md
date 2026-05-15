# 3.0 versija
## Realizuotos Vector funkcijos
### emplace()
emplace() funkcija iterpia nauja elementa i nurodyta vektoriaus vieta. Skirtingai nuo insert(), si funkcija leidzia perduoti reiksmes, is kuriu naujas objektas sukuriamas vektoriaus viduje.
Funkcijos realizacijoje: apskaiciuojama iterpimo pozicija, jei reikia, padidinama konteinerio talpa, esami elementai pastumiami i desine, o naudojant std::forvard(funkcija priima argumentus, reakalingus naujo objekto sukurimui) sukuriamas naujas objektas.
Pvz.: 
Vector<std::string> v;
v.emplace(v.begin(), 5, 'a');
Rezultatas: ["aaaaa"].
### assign(first, last)
assign(first,last) funkcija pakeicia esama vektoriaus turini naujais elementais is nurodyto intervalo.
Intervalas aprasomas dviem iteratoriais: first - pirmas kopijuojamas elementas, last - vieta uz paskutinio kopijuojamo elemento.
Kaip veikia si funkcija: istrina sena vektoriaus atminti, apskaiciuoja nauju elementu kieki naudojant std::distance, sukuria nauja masyva ir tada elementai is intevalo yra nukopijuojami i vektoriu.
Pvz. :
std::vector<int> data = {1, 2, 3, 4};
Vector<int> v;
v.assign(data.begin(),data.end());
Rezultatas: [1,2,3,4].
### push_back
push_back() funkcija prideda nauja elementa i vektoriaus pabaiga. Jei vektoriaus talpa yra pilnai uzpildyta, funkcija automatiskai padidina ja.
Funkcijos veikimas: pirma patikrinama, ar uztenka vietos naujam elementui, jei ne, talpa padidinama. Tada naujas elementas irasomas i paskutine pozicija. Galiausiai yra padidinamas vektoriaus dydis.
Pvz. :
Vector<int> v;
v.push_back(10);
v.push_back(11);
Rezultatas: [10,11].
### resize(count, value)
resize() funkcija pakeicia vektoriaus dydi. Jei naujas dydis yra mazesnis uz esama, tai pertekliniai elementai yra pasalinami. Jei naujas dydis yra didesnis uz esama, tai vektorius ispleciamas, o naujos vietos yra uzpildomos nurodyta reiksme.
Kaip veikia si funkcija: Pirma patikrinama ar count < sz, jei taip, tai sumazinamas Vector dydis, jei ne tai rezervuojama papildoma atmintis. Tada nauji elementai uzpildo perduota reiksme value.
Pvz. :
Vector<int> v{1, 2, 3};
v.resize(6,10);
Rezultatas: [1, 2, 3, 10, 10, 10].
v.resize(2, 0);
Rezultatas: [1, 2].
### shrink_to_fit()
shrink_to_fit funkcija sumazina vektoriaus rezervuota talpa iki esamo elementu kiekio(size). Jei vektoriaus talpa yra didesne uz naudojamu elementu skaiciu, tai sukuriamas naujas mazesnis masyvas, i ji nukopijuojami esami elementai. Tada pasalinama sena atmintis, o talpa tampa lygi dydziui.
Pvz. :
Vector<int> v{1, 2, 3};
v.reserve(10);
Dabar dydis = 3, o talpa = 10.
v.shrink_to_fit();
Dabar dydis = 3 ir talpa = 3.
### at(pos)
at() funkcija grazina elementa nurodytoje pozicijoje. Jei nurodytas indeksas neteisingas, ismetama std::out_of_range isimtis.
Funkcijos veikimas: Pirma patikriname, ar indeksas priklauso vektoriaus riboms, jei ne - ismetama klaida. Kitu atveju grazinamas elementas.
Pvz. :
Vector<int>  v{1,2,3};
std::cout<<v.at(1);
isves 2.
std::cout<<v.at(10);
isves std::out_of_range.
## Spartos analize lyginant su std::vector
Buvo atlikta spartos analize tam, kad patikrinti kaip greitai veikia mano sukurtas Vector palyginus su std::vector konteineriu. Spartos analize buvo tikrinama naudojant push_back funkcija. Testavimo metu buvo naudojamas std::chrono::high_resolution_clock laikui matuoti, o elementai buvo iterpiami nuo 1 iki n(100.000 iki 100.000.000). Noredamas patikrinti optimizavimo flagus, dar karta atlikau testa naudodamas -O2 flaga bei n = 100.000.000. 
### Gauti rezultatai:
|             | 100.000    | 1.000.000   | 10.000.000  | 100.000.000 | 100.000.000 su -O2 flagu |
|-------------|------------|-------------|-------------|-------------|--------------------------|
| std::vector | 0,00001(s) | 0,012045(s) | 0,078756(s) | 0,714367(s) | 0,312670(s)              |
| Vector      | 0,00011(s) | 0,010462(s) | 0,065000(s) | 0,49257(s)  | 0,273827(s)              |


Atlikus testavima, pastebeta, kad nuosava Vector realizacija veikia panasiu, kartais ir greiciau negu  std::vector.
