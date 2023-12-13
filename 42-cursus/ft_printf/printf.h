/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:14:09 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/07 15:29:33 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *i, int *count);
void	ft_puthex(unsigned int number, char *base, int *nb, int *count);
void	ft_putnbr(int nb, int *nbr, int *count);
void	ft_putptr(unsigned long number, char *base, int *nb, int *count);
void	ft_putstr(const char *str, int *nb, int *count);
void	ft_putunbr(unsigned int nb, int *nbr, int *count);

#endif
