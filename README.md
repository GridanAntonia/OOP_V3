# Ghicește capitala!

# Scurta descriere
Un joc interactiv, în care  user-ul logat trebuie să răspundă la 10 întrebări. Pentru fiecare răspuns greșit, se va afișa pe ecran capitala corectă, iar pentru un răspuns corect, codul se va actualiza.

### Folosiți template-ul corespunzător grupei voastre!

| Laborant  | Link template                                |
|-----------|----------------------------------------------|
| Dragoș B  | https://github.com/Ionnier/oop-template      |
| Tiberiu M | https://github.com/MaximTiberiu/oop-template |
| Marius MC | https://github.com/mcmarius/oop-template     |

### Important!

Aveți voie cu cod generat de modele de limbaj la care nu ați contribuit semnificativ doar în folder-ul `generated`.
Codul generat pus "ca să fie"/pe care nu îl înțelegeți se punctează doar pentru puncte bonus, doar în contextul
în care oferă funcționalități ajutătoare și doar dacă are sens.

O cerință nu se consideră îndeplinită dacă este realizată doar prin cod generat.

- **Fără cod de umplutură/fără sens!**
- **Fără copy-paste!**
- **Fără variabile globale!**
- **Fără atribute publice!**

### Tema 0

- [X] Nume proiect (poate fi schimbat ulterior)
- [X] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [X] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi; moștenirile nu se iau în considerare aici
- [X] constructori de inițializare cu parametri pentru fiecare clasă
- [X] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [X] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [X] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [X] `operator<<` pentru **toate** clasele pentru afișare (`std::ostream`) folosind compunere de apeluri cu `operator<<`
- [X] cât mai multe `const` (unde este cazul) și funcții `private`
- [X] implementarea a minim 3 funcții membru publice pentru funcționalități netriviale specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [X] scenariu de utilizare **cu sens** a claselor definite:
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [X] minim 50-55% din codul propriu să fie C++, `.gitattributes` configurat corect
- [X] tag de `git`: de exemplu `v0.1`
- [X] serviciu de integrare continuă (CI) cu **toate bifele**; exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [X] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [X] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [X] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (i.e. nu simple citiri/afișări sau preluate din biblioteci i.e. draw/update/render)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [X] apelarea constructorului din clasa de bază din constructori din derivate
  - [X] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [X] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [X] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [X] smart pointers (recomandat, opțional)
- [X] excepții
  - [X] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice distincte
    - clasele de excepții trebuie să trateze categorii de erori distincte (exemplu de erori echivalente: citire fișiere cu diverse extensii)
  - [X] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [X] funcții și atribute `static`
- [X] STL
- [X] cât mai multe `const`
- [X] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [X] minim 75-80% din codul propriu să fie C++
- [X] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3 derivate deja adăugate** din aceeași ierarhie
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
  - noua derivată va fi integrată în codul existent (adică va fi folosită, nu adăugată doar ca să fie)
- [ ] tag de `git` pe commit cu **toate bifele**: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] minim 85% din codul propriu să fie C++
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git` pe commit cu **toate bifele**: de exemplu `v0.3` sau `v1.0`

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# sau ./scripts/cmake.sh configure
```

Sau pe Windows cu GCC:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
# sau ./scripts/cmake.sh configure -g Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.


2. Pasul de compilare
```sh
cmake --build build --config Debug --parallel 6
# sau ./scripts/cmake.sh build
```

Cu opțiunea `parallel` specificăm numărul de fișiere compilate în paralel.


3. Pasul de instalare (opțional)
```sh
cmake --install build --config Debug --prefix install_dir
# sau ./scripts/cmake.sh install
```

Vezi și [`scripts/cmake.sh`](scripts/cmake.sh).

Observație: folderele `build/` și `install_dir/` sunt adăugate în fișierul `.gitignore` deoarece
conțin fișiere generate și nu ne ajută să le versionăm.


## Resurse

- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
