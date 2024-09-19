/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthoffma <sthoffma@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:04:14 by sthoffma          #+#    #+#             */
/*   Updated: 2024/09/19 14:38:55 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_KEY_LEN 256
#define TABLE_SIZE 20

struct Entry
{
	char	key[MAX_KEY_LEN];
	char	*value;
	struct	Entry *next;
};

struct Entry *hashmap[TABLE_SIZE];

unsigned long int	ft_strnlen(char *str, unsigned int maxlen)
{
	unsigned int	len;

	len = 0;
	while (len < maxlen && str[len] != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	ft_hash(char *key)
{
	unsigned int	hash_value;
	int	i;
	int	len;

	hash_value = 0;
	i = 0;
	len = ft_strnlen(key, MAX_KEY_LEN);
	while (i < len)
	{
		hash_value += key[i];
		hash_value = (hash_value * key[i]) % TABLE_SIZE;
		i++;
	}
	return (hash_value);
}

bool	ft_insert(struct Entry *record)
{
	struct	Entry*	current;
	unsigned int	index;

	if (record == NULL)
		return (false);
	index = ft_hash(record->key);
	if (hashmap[index] == NULL)
	{
		hashmap[index] = record;
		record->next = NULL;
		return (true);
	}
	else 
	{
		current = hashmap[index];
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = record;
		record->next = NULL;
		return (true);
	}
	return (false);
}

int	ft_strncmp(const char *str1, const char *str2, unsigned int nb)
{
	unsigned int	i;
	i = 0;

	while (i < nb && str1[i] != '\0' && str2[i] != '\0') {
	if (str1[i] != str2[i]) {
            return ((unsigned char)str1[i] - (unsigned char)str2[i]);
        }
        i++;
    }
    if (i == nb) {
        return (0);
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

struct Entry*	ft_lookup(char *key)
{
	unsigned int	hash;
    struct Entry* current;

	hash = ft_hash(key);
	if (hashmap[hash] != NULL)
	{
		current = hashmap[hash];
		while (current != NULL)
		{
			if (ft_strncmp(current->key, key, MAX_KEY_LEN) == 0)
			{
				return current;
			}
			current = current->next;
		}
	}
	return (NULL);
}

void	ft_init_table()
{
	unsigned int	i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		hashmap[i] = NULL;
		i++;
	}
}

void	ft_print_table()
{
	int	i;
	struct Entry* current;

	i = 0;
	while (i < TABLE_SIZE)
	{
	if (hashmap[i] == NULL)
	{
		printf("\t%i\t----\n", i);
	}
	else
	{
		current = hashmap[i];
		printf("\t%i\t", i);

		while (current != NULL)
		{
			printf("%s:%s", current->key, current->value);
			if (current->next != NULL)
		{
	                	printf(" -> ");
		}
			current = current->next;
		}
	printf("\n"); 
	}
	i++;
	}
}

void	free_entry(struct Entry *entry)
{
	if (entry) 
	{
		free(entry->value);
		free(entry);
	}
}

int	main(void)
{
	ft_init_table();
	struct Entry new_entry = {.key = "100", .value = "hundred"};
	struct Entry new_entry2 = {.key = "1000", .value = "thousand"};
	struct Entry new_entry3 = {.key = "10000", .value = "ten thousand"};
	struct Entry new_entry4 = {.key = "50", .value = "fifty"};
	struct Entry new_entry5 = {.key = "60", .value = "sixty"};
	struct Entry new_entry6 = {.key = "100000", .value = "hundred thousand"};

	ft_insert(&new_entry);
	ft_insert(&new_entry2);
	ft_insert(&new_entry3);
	ft_insert(&new_entry4);
	ft_insert(&new_entry5);
	ft_insert(&new_entry6);

	struct Entry* record = ft_lookup("60");

	ft_print_table();
	if (record != NULL)
	{	
		printf("res of lookup = {%s: %s}", record->key, record->value);
	}
	else
	{
		printf("res of lookup = %s", "undefined");
	}
	return (0);
}
