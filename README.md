# 3.0 versija
## Realizuotos Vector funkcijos
### emplace()
emplace() funkcija iterpia nauja elementa i nurodyta vektoriaus vieta. Skirtingai nuo insert(), si funkcija leidzia perduoti reiksmes, is kuriu naujas objektas sukuriamas vektoriaus viduje.
Funkcijos realizacijoje: apskaiciuojama iterpimo pozicija, jei reikia, padidinama konteinerio talpa, esami elementai pastumiami i desine, o naudojant std::forvard(funkcija priima argumentus, reakalingus naujo objekto sukurimui) sukuriamas naujas objektas.
Pvz.: 
Vector<std::string> v;
v.emplace(v.begin(), 5, 'a');
Rezultatas: ["aaaaa"].

## Spartos analize lyginant su std::vector
Buvo atlikta spartos analize tam, kad patikrinti kaip greitai veikia mano sukurtas Vector palyginus su std::vector konteineriu. Spartos analize buvo tikrinama naudojant push_back funkcija. Testavimo metu buvo naudojamas std::chrono::high_resolution_clock laikui matuoti, o elementai buvo iterpiami nuo 1 iki n(100.000 iki 100.000.000). Noredamas patikrinti optimizavimo flagus, dar karta atlikau testa naudodamas -O2 flaga bei n = 100.000.000. 
### Gauti rezultatai:
|             | 100.000    | 1.000.000   | 10.000.000  | 100.000.000 | 100.000.000 su -O2 flagu |
|-------------|------------|-------------|-------------|-------------|--------------------------|
| std::vector | 0,00001(s) | 0,012045(s) | 0,078756(s) | 0,714367(s) | 0,312670(s)              |
| Vector      | 0,00011(s) | 0,010462(s) | 0,065000(s) | 0,49257(s)  | 0,273827(s)              |


Atlikus testavima, pastebeta, kad nuosava Vector realizacija veikia panasiu, kartais ir greiciau negu  std::vector.
