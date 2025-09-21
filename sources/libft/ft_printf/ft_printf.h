/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:54:38 by tcardair          #+#    #+#             */
/*   Updated: 2025/02/18 14:23:28 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define HEXA "0123456789abcdef"
# define HEXA_MAJ "0123456789ABCDEF"

int					ft_printf(const char *str, ...);
int					type_c(char c);
int					type_s(char *str);
int					type_i(int nb);
int					type_p(void *p);
unsigned long long	to_hexa(unsigned long long addr);
int					type_xx(unsigned int nb, char c);
int					type_u(unsigned int u);

#endif
