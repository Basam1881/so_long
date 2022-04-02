/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:16:58 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/02 22:17:13 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen((char *)s1);
	while (ft_strchr((char *)set, s1[start]) && s1[start])
		start++;
	while (s1[start] != 0
		&& ft_strchr((char *)set, s1[end - 1]) && end != start)
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}
