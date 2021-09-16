/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:30:05 by fmeira            #+#    #+#             */
/*   Updated: 2021/09/16 17:32:13 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	free_slice(char **arr, int current, int end)
{
	if (arr)
	{
		while (++current <= end)
			free(arr[current]);
	}
}
