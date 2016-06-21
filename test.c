/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:54:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/21 10:12:58 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_spot
{
	int		var1;
}				t_spot;

int main()
{
	int			i;
	t_spot		*spot;
	char		*str;

	str = (char *)malloc(sizeof(char) * 3);
	str[2] = 0;
	spot = (t_spot *)malloc(sizeof(t_spot) * 3);
	spot[2].var1 = 1;
}
