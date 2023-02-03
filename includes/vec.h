/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:31:32 by agiraude          #+#    #+#             */
/*   Updated: 2023/02/03 11:49:16 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

typedef struct	s_vec
{
	char**	data;
	size_t	size;
	size_t	capacity;
}				t_vec;

void	vecInit(t_vec* vec);
void	vecGrow(t_vec* vec, size_t newCap);
void	vecPushBack(t_vec* vec, char* str);
void	vecForEach(t_vec* vec, void (*fct)(char*));
char*	vecAt(t_vec* vec, size_t pos);

#endif
