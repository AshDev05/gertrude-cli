/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** Point of Entry
*/

#include "../include/my.h"
#include "../include/text_mod.h"
#include "../include/gertrude.h"

int main(int ac, char **av)
{
    my_printf("%sGertrude says Welcome!%s\n", GREEN, NC);
    parse_args(ac, av);
}
