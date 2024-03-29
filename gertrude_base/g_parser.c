/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** A CLI-based Makefile Tool
*/

#include <string.h>

#include "../include/gertrude.h"
#include "../include/error_codes.h"
#include "../include/ger_conf.h"

void parse_args(int ac, char **av, gertrude_t *ger)
{
    for (int i = 0; i < ac; i ++) {
        if (strcmp(av[i], "-h") == 0) {
            help(0);
        } else if (strcmp(av[i], "--var") == 0 || strcmp(av[i], "-v") == 0) {
            if (i == ac - 1)
                gertrude_errors(av, ac, i, VARERR);
            if (av[i + 1][0] == '-')
                gertrude_errors(av, ac, i, VARERR);
            i ++;
            variable_def(av, ac, i, ger);
        } else if (strcmp(av[i], "-d") == 0) {
            if (i == ac - 1)
                gertrude_errors(av, ac, i, DIRERR);
            if (av[i + 1][0] == '-')
                gertrude_errors(av, ac, i, DIRERR);
            i ++;
            directory_def(ger, av, i);
        } else if (strcmp(av[i], "--rule") == 0 || strcmp(av[i], "-r") == 0) {
            if (i == ac - 1)
                gertrude_errors(av, ac, i, RULERR);
            if (av[i + 1][0] == '-')
                gertrude_errors(av, ac, i, RULERR);
            i ++;
            rule_def(av, ac, &i, ger);
        } else if (strcmp(av[i], "-e") == 0 || strcmp(av[i], "--epi") == 0) {
            ger->header = EPIHEADER;
            continue;
        }
    }
}
