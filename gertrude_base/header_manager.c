/*
** GERTRUDE PROJECT, 2024
** Gertrude Cli
** File description:
** header_manager.c
*/

#include "../include/gertrude.h"
#include "../include/text_mod.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

static void final(char *buffer, gertrude_t *ger)
{
    write_in_file(ger->dir, buffer);
    free(buffer);
}

void print_header(gertrude_t *ger)
{
    struct stat statbuf;
    FILE *fp;
    size_t size;
    char *buffer;

    stat(ger->header, &statbuf);
    buffer = malloc(statbuf.st_size + 1);
    fp = fopen(ger->header, "r");
    if (fp == NULL) {
        fprintf(stderr, "%sBad header prebuilt location%s\n", RED, NC);
        exit(84);
    }
    size = fread(buffer, sizeof(char), statbuf.st_size, fp);
    if (ferror(fp) != 0) {
        fprintf(stderr, "%sError reading header prebuilt file%s\n", RED, NC);
        exit(84);
    }
    buffer[size] = '\0';
    fclose(fp);
    final(buffer, ger);
}
