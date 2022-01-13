#ifndef CESAR_H
#define CESAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CHAR_MAX 80
#define USAGE "Décryption de César\n./cesar [Fichier Entree] [Fichier Sortie]"

/**
 * @brief Ouvre un fichier pour écrire ou lire
 * 
 * @param filename chemin du fichier à ouvrir
 * @param mode Le mpde pour lire ou écrire
 * @return FILE* Retourne un pointeur vers le fichier
 */
FILE *open_file(char *filename, char *mode);

/**
 * @brief Lis un fichier et mets chaque ligne lue dans le tableau
 * 
 * @param file fichier à lire
 * @param line pointeur vers un tableau pour ranger chaque ligne
 * @return le nombre de ligne dans le tableau
 */
int store_file(FILE *file, char *lines[]);

/**
 * @brief Vérifie si le fichier n'a pas de ligne qui contient plus de 80 caractères
 * 
 * @param file 
 */
void check_file(FILE *file);

/**
 * @brief transforme les lettres de a à z et A à Z
 * 
 * @param line tableau à transformer
 * @param nb_element le nombre de ligne dans le tableau
 */
void transform(char *line[], int nb_element);

/**
 * @brief Écris ligne par ligne dans un fichier
 * 
 * @param file fichier à écrire
 * @param line tableau à écrire dans le fichier
 * @param nb_element Le nombre de ligne dans le tableau
 */
void write_to_file(FILE *file, char *line[], int nb_element);

#endif