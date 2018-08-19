// Created by Jagermeister on 8/19/2018.

#ifndef HASH_TABLES_IN_C_HAST_TABLE_H
#define HASH_TABLES_IN_C_HAST_TABLE_H

// Hash table structure:

/* Our key-value pairs (items) will each be stored in a struct ht_item */
typedef struct
{
    char* key;
    char* value;
} ht_item;

/* Our hash table stores an array of pointers to item,
 * and some details about its size and how full it is. */
typedef struct
{
    int size;
    int count;
    ht_item** items;
} ht_hash_table;

static ht_item* ht_new_item(const char* k, const char* v);
ht_hash_table* ht_new();
static void ht_del_item(ht_item* item);
void ht_del_hash_table(ht_hash_table* hashtable);

#endif //HASH_TABLES_IN_C_HAST_TABLE_H