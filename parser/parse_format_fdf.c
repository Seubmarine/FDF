/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:43:43 by tbousque          #+#    #+#             */
/*   Updated: 2022/05/31 02:46:22 by tbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	get_num(char *line)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (line[i])
	{		
		if (line[i] != ' ')
		{
			num++;
			printf("(num++ = %li)\n", num);
			while (line[i] != ' ' && line[i])
			{
				printf("%c", line[i]);
				i++;
			}
			printf(" ");
		}
		else
			i++;
	}
	printf("\n");
	return (num);
}
