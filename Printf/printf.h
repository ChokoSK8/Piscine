/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:28:43 by abrun             #+#    #+#             */
/*   Updated: 2021/01/14 19:04:45 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "Libft/libft.h"

int					ft_printf(const char *s, ...);

void				ft_putunsigned_fd(unsigned int n, int fd);

long long int		ft_pow(long long int nb, int power);

long int			ft_put_puissance(long long int nbr, size_t base_len);

void				ft_putnbr_base_fd(long long int nbr, char *base, int fd);

void				ft_putadress_fd(long long nbr, char *base, int fd);

int					print_d_1(int filler, int space_plus, int n);

void				print_d_2(int filler, int n);

int					print_d_3(int n_chr, int puissance,
		int n_point, int filler);

void				print_d_4(int n_point, int puissance,
		long int n, int filler);

int					print_d_5(int n_point, int puissance,
		long int n, int filler);

void				print_d_6(char *num, int n, int n_point, long int nbr);

int					print_d_n_1(int n_point, int n);

int					print_d_n_2(int puissance, int n_point);

int					p_p(char *num, int n, int n_point);

int					is_flag_point(char *num);

int					is_flag_zero(char *num);

int					is_flag_minus(char *num);

int					ft_putpui(long long int nbr, int base_len);

int					get_flag_n(char *num);

int					get_flag_point(char *num);

int					get_flag_point_s(char *num, int puissance);

int					get_space_or_plus(char *num);

int					get_filler(char *num, int n_point);

int					get_res(int puissance, int n_chr);

int					get_res_s(int puissance, int n_chr, int n_point);

int					get_res_npt(int puissance, int n_chr,
		int npt, int space_plus);

int					get_res_npt_pos(int n, int n_chr, int npt, int space_plus);

int					get_res_npt_neg(int n, int n_chr, int npt, int space_plus);

int					print_p_normal(long long int n, int n_chr);

int					print_p_neg(long long int n, int n_chr);

int					print_p(long long int n, char *num);

int					print_bigx_normal(unsigned int n, int n_chr, char *num);

int					print_bigx_neg(unsigned int n, int n_chr, char *num);

int					print_bigx(unsigned int n, char *num);

void				print_bigx_6(char *num, unsigned int n, int n_point);

int					print_x_normal(unsigned int n, int n_chr, char *num);

int					print_x_neg(unsigned int n, int n_chr, char *num);

int					print_x(unsigned int n, char *num);

void				print_x_6(char *num, unsigned int n, int n_point);

void				print_x_2(int filler, unsigned int n);

int					print_x_n_1(int n_point, unsigned int n);

void				print_x_4(int n_point, int puissance,
		unsigned int n, int filler);

int					print_d_normal(int space_plus, int n, int n_chr, char *num);

int					print_d_neg(int space_plus, int n, int n_chr, char *num);

int					print_d(int n, char *num);

int					print_c(int n, char *num);

int					print_c_normal(int n, int n_chr, char *num);

int					print_c_neg(int n, int n_chr, char *num);

void				print_c_6(char *num, int n, int n_point);

int					print_c_3(int n_chr, int puissance, int filler);

int					print_s(char *s, char *num);

int					print_s_normal(char *s, int n_chr, char *num);

int					print_s_neg(char *s, int n_chr, char *num);

void				print_s_npt(int n_point, char *s, int puissance, char *num);

int					print_u(unsigned int n, char *num);

int					print_u_normal(unsigned int n, int n_chr, char *num);

int					print_u_neg(unsigned int n, int n_chr, char *num);

int					print_u_2(int n_chr, int puissance,
		int n_point, int filler);

int					print_point_u(char *num, unsigned int n, int n_point);

void				print_u_3(char *num, unsigned int n, int n_point);

int					print_va_arg(char c, va_list lst, char *num);

int					ft_printf(const char *s, ...);

int					pass_the_spaces(const char *s, int *c_num, char *num);

int					browse_2nd_step(const char *s, char *num, int *c_num);

int					browse_3rd_step(const char *s, char *num,
		int c_num, va_list lst);

int					browse_s(const char *s, int *n_chr);

int					fill_num_last_step(int puissance, char *num,
		int n, int counter);

int					fill_num_star(char *num, int *c_num, int n);

#endif
