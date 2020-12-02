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

int					print_d_1(int filler, int space_plus, int n);

void				print_d_2(int filler, int n);

int					print_d_3(int n_chr, int puissance, int n_point, int filler);

void				print_d_4(int n_point, int puissance, int n, int filler);

int					print_d_5(int n_point, int puissance);

void				print_d_6(char *num, int n, int n_point, long int nbr);

int					print_d_n_1(int n_point, int n);

int					print_d_n_2(int puissance, int n_point);

int					print_point(char *num, int n, int n_point);

int					is_flag_point(char *num);

int					is_flag_zero(char *num);

int					ft_putpui(long long int nbr, int base_len);

int					get_flag_n(char *num);

int					get_flag_point(char *num);

int					get_space_or_plus(char *num);

int					get_filler(char *num);

void				print_x_normal(long long int n, int n_chr, char *num);

void				print_x_neg(long long int n, int n_chr, char *num);

void				print_x(long long int n, char *num);

void				print_x_6(char *num, long long int n, int n_point, long int nbr);

void				print_x_2(int filler, long long int n);

int					print_x_n_1(int n_point, long long int n);

void				print_x_4(int n_point, int puissance, long long int n, int filler);

void				print_d_normal(int space_plus, int n, int n_chr, char *num);

void				print_d_neg(int space_plus, int n, int n_chr, char *num);

void				print_d(int n, char *num);

void				print_c(int n, char *num);

void				print_c_normal(int n, int n_chr, char *num);

void				print_c_neg(int n, int n_chr, char *num);

void				print_c_6(char *num, int n, int n_point);

int					print_c_3(int n_chr, int puissance, int filler);

void				print_s(char *s, char *num);

void				print_s_normal(char *s, int n_chr, char *num);

void				print_s_neg(char *s, int n_chr, char *num);

void				print_s_npt(int n_point, char *s, int puissance, char *num);

void				print_u(unsigned int n, char *num);

void				print_u_normal(unsigned int n, int n_chr, char *num);

void				print_u_neg(unsigned int n, int n_chr, char *num);

int					print_u_2(int n_chr, int puissance, int n_point, int filler);

int					print_point_u(char *num, unsigned int n, int n_point);

void				print_u_3(char *num,unsigned int n, int n_point);

void				print_va_arg(char c, va_list, char *num);

int					ft_printf(const char *s, ...);

void				print_p(long long int n, char *num);

void				print_x_bis(long long int n, char *num);

void				print_X(long long int n, char *num);

void				print_c(int va_arg, char *num);

void				print_s(char *s, char *num);

void				print_u(unsigned int n, char *num);

#endif
