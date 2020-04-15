/*
** EPITECH PROJECT, 2020
** my_repo
** File description:
** file.h
*/

#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

bool is_file_openable(char const *filepath);
bool is_file_fopenable(char const *filepath);
bool is_dir_openable(char const *filepath);

size_t file_len(char const *filepath);
size_t nb_in_dir(char *dirpath, unsigned char type);

ssize_t get_pos_word_in_str(char const  *word, char const *str);
ssize_t get_pos_word_end_in_str(char const *word, char const *str);
ssize_t get_pos_word_in_double_arr(char const *word, char const **arr);

char *get_entire_file(char const *filepath);
char **get_entire_file_double_arr(char const *filepath);

char **check_get_xml_file(char const *filepath);

char **get_filepaths(char *dirpath, unsigned char type);

char *rm_trailling_char_in_str(char *str, const char ch);
char **rm_trailling_char_in_double_arr(char **arr, const char ch);
char **remove_char_in_double_arr(char **arr, const char ch);
char *remove_char_in_str(char *str, const char ch);

bool check_comments(char *str);

#endif /*FILE_H_*/
