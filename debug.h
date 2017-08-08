/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 22:03:34 by                   #+#    #+#             */
/*   Updated: 2017/08/08 15:07:44 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DEBUG_H
# define _DEBUG_H

# include <stdio.h>

# define PAUSE while (1) sleep(1000000000);
# define BN ft_putchar('\n');
# define YOLO ft_putstr("\n\nYOLO\n");
# define YOLO1 ft_putstr("\nYOLO1 -\n");
# define YOLO2 ft_putstr("YOLO2 --\n");
# define TEST ft_putstr("\n\ntest\n");
# define YOLOO ft_putstr("\n\nYOLO---------------\n");
# define DEBUG printf("DEBUG -- %d -- \n", __LINE__);

#endif
