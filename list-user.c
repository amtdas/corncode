#include <assert.h>
#include <stdlib.h>

#include "list.h"

int main(void)
{
    struct list *my_list = list_create(free);
    assert(my_list);

    // put numbers 1 to 5 in the data of the list
    for (size_t index = 1; index < 6; index++) {
	    int *number = calloc(1, sizeof(*number));
	    if (!number)
		    abort();
	    *number = index;

	    list_append(my_list, number);
    }
    assert(list_size(my_list) == 5);

    // put 6 at the head of the list
    int *my_head_data = calloc(1, sizeof(*my_head_data));
    *my_head_data = 6;
    struct list_node *my_head = list_prepend(my_list, my_head_data);
    assert(list_is_head(my_list, my_head));

    // track the old list tail
    struct list_node *old_tail = list_tail(my_list);

    // add 7 to the end of the list
    int *my_tail_data = calloc(1, sizeof(*my_tail_data));
    *my_tail_data = 7;
    struct list_node *my_tail = list_append(my_list, my_tail_data);
    assert(list_is_tail(my_list, my_tail));
    assert(list_size(my_list) == 7);

    // find list->tail->prev and confirm it's the old tail
    assert(list_prev(my_list, list_tail(my_list)) == old_tail);

    // check a non-member isn't on the list
    struct list *my_second_list = list_create(NULL);
    struct list_node *my_orphan = list_append(my_second_list, NULL);
    assert(!list_has_node(my_list, my_orphan));
    list_destroy(my_second_list);

    // delete 1 from the list
    free(list_delete_node_after(my_list, list_head(my_list)));

    // delete 7 from the list
    free(list_delete_node(my_list, list_tail(my_list)));

    // delete 4 from the list
    free(list_delete_node_before(my_list, list_tail(my_list)));

    assert(list_size(my_list) == 4);

    // delete 7 from the list
    free(list_delete_node(my_list, list_head(my_list)));

    // confirm 2 is the list head
    int *two = (int *)list_get_node_data(list_head(my_list));
    assert(*two == 2);

    // confirm 3 is list->head->next
    int *three = (int *)list_get_node_data(list_next(list_head(my_list)));
    assert(*three == 3);

    // clean up
    list_destroy(my_list);

    return 0;
}

