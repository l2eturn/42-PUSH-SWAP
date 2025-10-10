/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 04:34:06 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/07 04:34:06 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//recursive_chunk_sort(chunk)
//│
//├── base_case? (size <= 3)
//│     └── ใช้ simple_sort() แล้ว return
//│
//├── split_chunk(chunk, &splits)
//│     ├── ส่ง max → TOP_A
//│     ├── ส่ง mid → TOP_B
//│     └── ส่ง min → BOTTOM_B
//│
//├── recursive_chunk_sort(&splits.max)
//├── recursive_chunk_sort(&splits.mid)
//└── recursive_chunk_sort(&splits.min)


