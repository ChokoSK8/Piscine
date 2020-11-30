#ifndef PRINTF_H
#include <stdarg.h>
#include "Libft/libft.h"
#define PRINTF_H

int					ft_printf(const char *, ...);

void				ft_putunsigned_fd(unsigned int, int);

long long int		ft_pow(long long int nb, int power);

long int			ft_put_puissance(long long int nbr, size_t base_len);

void				ft_putnbr_base_fd(long long int nbr, char *base, int fd);

void				ft_putadress_fd(long long nbr, char *base, int fd);

#endif
