/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:41:32 by overetou          #+#    #+#             */
/*   Updated: 2018/03/20 14:41:34 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "corewar.h"



t_op    *op_filler()
{
    t_op *op;
    // t_op *op2;
    // int i;

    

    static t_op    op_tab[17] =
    {
        {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, NULL},
        {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, NULL},
        {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, NULL},
        {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, NULL},
        {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, NULL},
        {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
            "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, NULL},
        {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
            "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, NULL},
        {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
            "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, NULL},
        {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, NULL},
        {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
            "load index", 1, 1, NULL},
        {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
            "store index", 1, 1, NULL},
        {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, NULL},
        {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, NULL},
        {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
            "long load index", 1, 1, NULL},
        {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, NULL},
        {"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, NULL},
        {0, 0, {0}, 0, 0, 0, 0, 0, NULL}
    };
    // i = 0;
    // if (!(op = (t_op*)malloc(sizeof(t_op))))
    //     return (NULL);
    // op2 = op;
    // while (i < 17)
    // {
    //     *op2 = op_tab[i];
    //     ft_printf("%d\n", i);
    //     op2 = op2->next;
    //     i++;
    // }

    op = op_new(op_tab[0]);
    return ((t_op*)op_tab);
}

int main(int argc, char **argv)
{
    int fd;

    if (argc < 1)
        return (0); //exit("u");
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (0); //exit("o");
    //parse(fd);


    t_op *op;
    op = op_filler();
}
