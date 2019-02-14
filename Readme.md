---------------------  Elemente de garafica pe calulator ----------------------

Tema 1 : Brick Breaker
Nume : Niculescu
Prenume : Mihai Alexandru
Grupa : 335CB
Sistem de operare : Windows 10 64bit
Editor : Visual Studio 2017

--------------------------------------------------------------------------------


<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Structura Temei  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.
├── BrickBreaker.cpp
├── BrickBreaker.h
├── collision
│   ├── Collision.cpp
│   └── Collision.h
├── level
│   ├── Level.cpp
│   ├── Level.h
│   ├── Level1.cpp
│   ├── Level1.h
│   ├── Level2.cpp
│   ├── Level2.h
│   ├── Level3.cpp
│   ├── Level3.h
│   ├── Level4.cpp
│   ├── Level4.h
│   ├── LevelFactory.cpp
│   ├── LevelFactory.h
│   ├── ball
│   │   ├── Ball.cpp
│   │   └── Ball.h
│   ├── brick
│   │   ├── Brick.cpp
│   │   ├── Brick.h
│   │   ├── BrickFactory.cpp
│   │   ├── BrickFactory.h
│   │   ├── ClayBrick.cpp
│   │   ├── ClayBrick.h
│   │   ├── EngineeringBrick.cpp
│   │   ├── EngineeringBrick.h
│   │   ├── FireBrick.cpp
│   │   ├── FireBrick.h
│   │   ├── MudBrick.cpp
│   │   ├── MudBrick.h
│   │   ├── SandLimeBrick.cpp
│   │   └── SandLimeBrick.h
│   ├── paddle
│   │   ├── Paddle.cpp
│   │   └── Paddle.h
│   ├── powerup
│   │   ├── ExtraLife.cpp
│   │   ├── ExtraLife.h
│   │   ├── HugeBall.cpp
│   │   ├── HugeBall.h
│   │   ├── PowerUp.cpp
│   │   ├── PowerUp.h
│   │   ├── PowerUpFactory.cpp
│   │   ├── PowerUpFactory.h
│   │   ├── SuperBall.cpp
│   │   └── SuperBall.h
│   └── wall
│       ├── Wall.cpp
│       └── Wall.h
├── object2D
│   ├── Object2D.cpp
│   └── Object2D.h
└── transform2D
    └── Transform2D.h

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Descriere >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    Tema implementat jocul "Brick Breaker". Implementarea a pornit de la codul
laboratorului 3.
    In clasa BrickBreaker se creaza scena si logica jocului. Exista functi 
pentru initializarea fiecariu tip de mesh. Functia collision verifica daca exista
colisiune intre obiecte. powerUpSistem este folosita ca un powerUp sa dureze 45s.
Functia loseBall verifica daca mingia a iesit din suprafata deci implicit a 
pierdut o viata, functia resetLevel verifica daca jucatorul mai are vietii, altfel
resteza nivelul curent. Functia nextLevel, verifica daca mai exist caramizi, 
daca nu incarca unrmatorul nivel, prin intermediunl variabilei finish (verificare 
propriu-zisa in collision). Functiile sunt apelate in Update, unde este afisata 
si scena. Pentru acesta s-au folosit translati, rotati si scaleri.

    Pentru reprezentare caramizilor s-a folosit clasa Brick si clasele care o 
deriveaza. Se memoreaza pozitia, daca exista un powerUp activ. Pentru efectul 
de "dispartie" se foloseste scalarea. Exista caramizi care se distrug mai greu.

    Platforma este reprezenta prin clasa Paddle, un se salveza coordonatele 
curente, viteza etc. exista si o functie de resetare in stare initiala.

    In clasa Ball se salveaza pozita, viteza mingei sau daca este activ un 
powerUp si o functie care adunce in  stare initila.
    Zidul este implementat in clasa Wall.

    PowerUp-urile implementate : 
    * HugeBall -> cea mai puternica, toate caremizile se distruc la primul contact
                si bila nu se mai reflecta
    * SuperBall -> toate caremizile se distruc la primul contact
    * ExtraLife -> adauga o viata in plus
    Fiecare powerUp mosteneste clasa PowerUp.

    Colisiunile sunt dectecte cu functile din namespace-ul Collision.

    Exista mai multe nivele, fiecare genereand o "map"/ "model de aranjare" a 
caramizilor. Fiecare clasa implementeza Level. Afisare vietilor se face in coltul
stanga sus.
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

<div style="text-align:center"><img src ="https://ibb.co/YdLR3FG" /></div>
