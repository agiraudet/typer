/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:31:20 by agiraude          #+#    #+#             */
/*   Updated: 2023/02/03 11:48:36 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vec.h"

void	vecInit(t_vec* vec)
{
	vec->data = NULL;
	vec->size = 0;
	vec->capacity = 0;
}

void	vecGrow(t_vec* vec, size_t newCap)
{
	if ((vec->data = reallocarray(vec->data, newCap, sizeof(char*))))
		vec->capacity = newCap;
}

void	vecPushBack(t_vec* vec, char* str)
{
	if (vec->size >= vec->capacity)
		vecGrow(vec, vec->capacity ? vec->capacity * 2 : 1);
	vec->data[vec->size] = str;
	vec->size++;
}

void	vecForEach(t_vec* vec, void (*fct)(char*))
{
	for (size_t i = 0; i < vec->size; i++)
		fct(vec->data[i]);
}

char*	vecAt(t_vec* vec, size_t pos)
{
	if (pos >= vec->size)
		return NULL;
	return vec->data[pos];
}
