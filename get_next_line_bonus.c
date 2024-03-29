/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:45:22 by pmaury            #+#    #+#             */
/*   Updated: 2021/06/01 12:17:40 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

int	get_next_line(int fd, char **line)
{
	static char	buff[64][BUFFER_SIZE + 1];
	int			i;
	int			ret;

	if (fd < 0 || fd >= 64 || BUFFER_SIZE < 1 || read(fd, buff[fd], 0) < 0
		|| !line)
		return (-1);
	*line = NULL;
	while (42)
	{
		i = ft_strnlen(buff[fd]);
		*line = ft_strnjoin(*line, buff[fd], i);
		if (i == BUFFER_SIZE || (!buff[fd][0] && !**line))
		{
			ret = read(fd, buff[fd], BUFFER_SIZE);
			if (ret < 1)
				return (ret);
		}
		else
			return (1);
	}
}
