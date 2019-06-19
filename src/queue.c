/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:32:57 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/19 17:33:10 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_to_queue(t_room *room, t_queue *queue)
{
	if (queue->size == 0)
	{
		queue->end = room;
		queue->start = queue->end;
	}
	else
	{
		queue->end->queue_next = room;
		queue->end = room;
	}
	room->queue_next = NULL;
	queue->size++;
}

static void		body_atpq(t_room *start, t_queue *queue, t_room *room)
{
	while (start)
	{
		if (start->queue_next == NULL)
		{
			start->queue_next = room;
			queue->end = room;
			room->queue_next = NULL;
			break ;
		}
		if (room->dijkstra <= start->queue_next->dijkstra)
		{
			if (start == queue->end)
				queue->end = room;
			room->queue_next = start->queue_next;
			start->queue_next = room;
			break ;
		}
		start = start->queue_next;
	}
}

void			add_to_priority_queue(t_room *room, t_queue *queue)
{
	t_room		*start;

	room->queue_next = NULL;
	queue->size++;
	start = queue->start;
	if (queue->size == 1)
	{
		queue->end = room;
		queue->start = queue->end;
		return ;
	}
	if (room->dijkstra <= start->dijkstra)
	{
		room->queue_next = start;
		queue->start = room;
		return ;
	}
	body_atpq(start, queue, room);
}

t_room			*pop_from_queue(t_queue *queue)
{
	t_room		*res;

	if (queue->size <= 0)
		return (NULL);
	else
	{
		if (queue->size == 1)
			queue->end = NULL;
		res = queue->start;
		queue->start = queue->start->queue_next;
	}
	queue->size--;
	return (res);
}

void			free_queue(t_queue *queue)
{
	free(queue);
}
