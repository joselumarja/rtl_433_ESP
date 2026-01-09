/** @file
    Generic list.

    Copyright (C) 2018 Christian Zuckschwerdt

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
*/

#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_

#include <stddef.h>

/// Dynamically growing list, elems is always NULL terminated, call list_ensure_size() to alloc elems.
typedef struct list {
    void **elems;
    size_t size;
    size_t len;
} list_t;

typedef void (*list_elem_free_fn)(void *);

/// Alloc elems if needed and ensure the list has room for at least min_size elements.
void rtl_433_list_ensure_size(list_t *list, size_t min_size);

/// Add to the end of elems, allocs or grows the list if needed and ensures the list has a terminating NULL.
void rtl_433_list_push(list_t *list, void *p);

/// Adds all elements of a NULL terminated list to the end of elems, allocs or grows the list if needed and ensures the list has a terminating NULL.
void rtl_433_list_push_all(list_t *list, void **p);

/// Remove element from the list, frees element with fn.
void rtl_433_list_remove(list_t *list, size_t idx, list_elem_free_fn elem_free);

/// Clear the list, frees each element with fn, does not free backing or list itself.
void rtl_433_list_clear(list_t *list, list_elem_free_fn elem_free);

/// Clear the list, free backing, does not free list itself.
void rtl_433_list_free_elems(list_t *list, list_elem_free_fn elem_free);

// Mantén nombres antiguos en el código fuente, pero enlaza a rtl_list_*
#define list_ensure_size  rtl_433_list_ensure_size
#define list_push         rtl_433_list_push
#define list_push_all     rtl_433_list_push_all
#define list_remove       rtl_433_list_remove
#define list_clear        rtl_433_list_clear
#define list_free_elems   rtl_433_list_free_elems

#endif /* INCLUDE_LIST_H_ */
