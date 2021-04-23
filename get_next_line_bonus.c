/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:17:15 by pmaury            #+#    #+#             */
/*   Updated: 2021/04/23 17:47:28 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	buff[64][BUFFER_SIZE];
	int			i;
	int			ret;
		
	if (fd < 0 || fd >= 64 || BUFFER_SIZE < 1 || read(fd, buff[fd], 0) < 0)
		return (-1);
	*line = NULL;
	while (42)
	{
		i = ft_strnlen(buff[fd]);
		if (buff[fd][i] != '\n')
		{
			*line = ft_strnjoin(*line, buff[fd], i);
			ft_memcpy(buff[fd], buff[fd] + i + 1, BUFFER_SIZE - i);
			ret = read(fd, buff[fd], BUFFER_SIZE);
			if (ret < 1)
				return (ret);
		}
		else
		{
			*line = ft_strnjoin(*line, buff[fd], i);
			ft_memcpy(buff[fd], buff[fd] + i + 1, BUFFER_SIZE - i);
			return (1);
		}
	}
}
