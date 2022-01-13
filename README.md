

# Décryption de César TP2 
## Description
Ce programme développé en C sert à décrypter un message qui a été encodé avec l'encryption de César de 3 déplacements.

## Installation

Pour installer le programme, seulement clôner le repo git sur le disque local.

```bash
git clone https://gitlab.info.uqam.ca/neault.alex.2/inf3135-automne2021-tp2.git
```

## Utiliser le programme
Pour utiliser le programme, un fichier Makefile est utilisé pour gérer les commandes.
```c
make : Lance le target all.
make all : Lance le target clean et link
make build: Lance la construction des fichiers .o nécessaire au programme.
make clean: Supprime les fichiers .o et l'exécutable cesar.
make start entree=nomEntree sortie=nomSortie : Prend l'argument entree et sortie et lance le programme. 
make test: Lance les tests avec le fichier bats
make link: Lance le build et crée l'exécutable "cesar" qui permet de décoder.
```
## Utilisation Standard
```
make
./cesar fichierEntree FichierSortie
```
## Précision sur le déroulement du programme

Si une des lignes du fichier d'entrée est plus grand que 80 caractères excluant le caractère de nouvelle ligne '\n'.
Le programme s'arrête et ne génère pas le fichier de sortie.

