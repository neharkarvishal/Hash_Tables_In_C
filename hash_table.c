// Created by Jagermeister on 8/19/2018.

/* Initialising and deleting
 * We need to define initialisation functions for ht_items.
 * This function allocates a chunk of memory the size of an ht_item,
 * and saves a copy of the strings k and v in the new chunk of memory.
 * The function is marked as static because it will only ever be called
 * by code internal to the hash table. */

#include <stdlib.h>
#include "hash_table.h"

static ht_item* ht_new_item(const char* k, const char* v)
{
    ht_item* item  =   malloc( sizeof(ht_item) );

    item->key = strdup(k);
    item->value = strdup(v);

    return item;
}

/* ht_new initialises a new hash table.
 * size defines how many items we can store.
 * This is fixed at 53 for now.
 * We'll expand this in the section on resizing.
 * We initialise the array of items with calloc,
 * which fills the allocated memory with NULL bytes.
 * A NULL entry in the array indicates that the bucket is empty. */

ht_hash_table* ht_new()
{
    ht_hash_table* hashtable = malloc( sizeof(ht_hash_table) );

    hashtable->size = 53;
    hashtable->count = 0;
    hashtable->items = calloc( (size_t)hashtable->size, sizeof(ht_item*) );

    return hashtable;
}

/*We also need functions for deleting ht_items and ht_hash_tables,
 * which free the memory we've allocated, so we don't cause memory leaks. */

static void ht_del_item(ht_item* item)
{
    free(item->key);
    free(item->value);
    free(item);
}
void ht_del_hash_table(ht_hash_table* hashtable)
{
    for (int i = 0; i < hashtable->size ; ++i)
    {
        ht_item* currentItem = hashtable->items[i];    //iterating through each item in table

        if(currentItem != NULL )
            ht_del_item(currentItem);                  //freeing currentItem if not null
    }

    free(hashtable->items);
    free(hashtable);
}