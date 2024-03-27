#ifndef MY_LIST_H
#define MY_LIST_H

#include <stdbool.h>

/**
 * Abstract data type for list.
 */
struct list;

/**
 * Abstract data type for list node.
 */
struct list_node;

/**
 * Create a new list.
 *
 * Terminates on failure with message via `error()`.
 *
 * Caller is responsible for freeing the list later with `list_destroy()`.
 *
 * Argument is either NULL if data is managed elsewhere, or a function such
 * as `free()` which will be used to free data pointers on list destroy.
 *
 * @param  destroy  Data destructor function
 *
 * @return  List pointer on success, terminate via error() on failure
 */
struct list *list_create(void (*destroy)(void *data));

/**
 * Free a list previously allocated with `list_create()`.
 *
 * If a `destroy` function pointer was provided when the list was created,
 * then that function is run on data for each list node.
 *
 * @param  list  Pointer to valid list structure
 */
void list_destroy(struct list *list);

/**
 * Return the size of the list.
 *
 * @param  list  Pointer to valid list structure
 *
 * @return  Number of elements in the list
 */
size_t list_size(struct list *list);

/**
 * Return pointer to head of list.
 *
 * @param  list  Pointer to valid list structure
 *
 * @return  Pointer to head node of list
 */
struct list_node *list_head(struct list *list);

/**
 * Return pointer to tail of list.
 *
 * @param  list  Pointer to valid list structure
 *
 * @return  Pointer to tail node of list
 */
struct list_node *list_tail(struct list *list);

/**
 * Return pointer to the list node after this node.
 *
 * @param  node  Pointer to valid list_node structure
 *
 * @return  Pointer to node after the node specified
 */
struct list_node *list_next(struct list_node *node);

/* Return pointer to the list node before this node.
 *
 * @param  list  Pointer to valid list structure
 * @param  node  Pointer to valid list_node structure
 *
 * @return  Pointer to node before the node specified
 */
struct list_node *list_prev(struct list *list, const struct list_node *node);

/**
 * Determine if a node is the head of the list.
 *
 * @param  list  Pointer to valid list structure
 * @param  node  Pointer to valid list_node structure
 *
 * @return  True if list head, false if not
 */
bool list_is_head(struct list *list, const struct list_node *node);

/**
 * Determine if a node is the tail of the list.
 *
 * @param  list  Pointer to valid list structure
 * @param  node  Pointer to valid list_node structure
 *
 * @return  True if list tail, false if not
 */
bool list_is_tail(struct list *list, const struct list_node *node);

/**
 * Determine if a node is on the list.
 *
 * @param  list  Pointer to valid list structure
 * @param  node  Pointer to valid list_node structure
 *
 * @return  True if node is on list, false if not
 */
bool list_has_node(struct list *list, const struct list_node *node);

/**
 * Insert new data after the list node.
 *
 * @param  list  Pointer to valid list structure
 * @param  node  Pointer to valid list_node structure
 * @param  data  Pointer to data to add to a new list node
 *
 * @return  Pointer to list node holding the data
 */
struct list_node *list_insert_after(struct list *list, struct list_node *node,
				    const void *data);
/**
 * Insert new data at the head of the list.
 *
 * @param  list  Pointer to valid list structure
 * @param  data  Pointer to data to add to a new list node
 *
 * @return  Pointer to list node holding the data
 */
struct list_node *list_prepend(struct list *list, const void *data);

/**
 * Insert new data at the tail of the list.
 *
 * @param  list  Pointer to valid list structure
 * @param  data  Pointer to data to add to a new list node
 *
 * @return  Pointer to list node holding the data
 */
struct list_node *list_append(struct list *list, const void *data);

/**
 * Delete the list node after this node, taking data off the list.
 *
 * @param  list  Pointer to valid list structure
 * @param  node  Pointer to valid list_node structure
 *
 * @return  Pointer to data taken off the list
 */
void *list_delete_node_after(struct list *list, struct list_node *node);

/**
 * Delete the list node before this node, taking data off the list.
 *
 * @param  list  Pointer to valid list structure
 * @param  node  Pointer to valid list_node structure
 *
 * @return  Pointer to data taken off the list
 */
void *list_delete_node_before(struct list *list, struct list_node *node);

/**
 * Delete this list node, taking data off the list.
 *
 * @param  list  Pointer to valid list structure
 * @param  node  Pointer to valid list_node structure
 */
void *list_delete_node(struct list *list, struct list_node *node);

/**
 * Return a pointer to the data held by this list node.
 *
 * @param  list  Pointer to valid list structure
 * @param  node  Pointer to valid list_node structure
 */
void *list_get_node_data(struct list_node *node);

#endif /* LIST_H */
