/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:12:43 by vpopovyc          #+#    #+#             */
/*   Updated: 2016/11/24 15:15:17 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if ((c >= 65) && (c <= 90))
	{
		c = c + 32;
		return (c);
	}
	else
		return (c);
}
