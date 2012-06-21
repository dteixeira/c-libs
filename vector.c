#include "vector.h"
#include <stdlib.h>

typedef struct {
	int size;
	int capacity;
	int cap_inc;
	void ** elements;
} _vector_private;

// Vector specific method definitions
int _vector_push_back(vector * vec, void * obj);
int _vector_push_front(vector * vec, void *obj);
int _vector_resize(vector * vec, int new_size);
void * _vector_get(vector * vec, int index);
void * _vector_remove(vector * vec, int index);
void * _vector_pop_front(vector * vec);
void * _vector_pop_back(vector * vec);
void _vector_auto_cap_inc(vector * vec, int alloc);
int _vector_size(vector * vec);
int _vector_capacity(vector * vec);
int _vector_swap(vector * vec, int p1, int p2);
int _vector_insert(vector * vec, int index, void * obj);
int _vector_put(vector * vec, int index, void * obj);

// Insert new element at the end of the vector
int _vector_push_back(vector * vec, void * obj) 
{
	int res = 1;
	_vector_private * real = (_vector_private *) vec->private; 
	if(real->size >= real->capacity)
		res = vec->resize(vec, real->capacity + real->cap_inc);
	if(res)
		real->elements[real->size++] = obj;
	return res;
}

// Insert new element at the start of the vector
int _vector_push_front(vector * vec, void *obj) 
{
}

// Resize the vector; copies old values, ignoring
// ones that don't fit in new array
int _vector_resize(vector * vec, int new_size) 
{
	_vector_private * real = (_vector_private *) vec->private;
	if(new_size < 0)
		return 0;

	// Reallocate vector
	void ** ptr = (void **) realloc(real->elements, new_size * sizeof(void *));
	if(!ptr)
		return 0;
	else
	{
		real->capacity = new_size;
		real->size = real->size < real->capacity ? real->size : real->capacity;
		real->elements = ptr;
		return 1;
	}
}

// Return the element in a given index
void * _vector_get(vector * vec, int index) 
{
	_vector_private * real = (_vector_private *) vec->private;
	if(index >= real->size || index < 0)
		return (void *) NULL;
	else
		return (void *) real->elements[index];
}

// Remove the element in a given position;
// returns the removed element
void * _vector_remove(vector * vec, int index) 
{
}

// Pops the front of the vector; returns the poped
// element
void * _vector_pop_front(vector * vec) 
{
}

// Pops the back of the vector; returns the poped
// element
void * _vector_pop_back(vector * vec) 
{
	_vector_private * real = (_vector_private *) vec->private;
	if(real->size <= 0)
		return NULL;
	else
		return real->elements[--real->size];
}

// Set auto increment in capacity when push is
// done
void _vector_auto_cap_inc(vector * vec, int alloc) 
{
	alloc = alloc < 1 ? 1 : alloc;
	_vector_private * real = (_vector_private *) vec->private;
	real->cap_inc = alloc;
}

// Returns the vector current size (number of elements)
int _vector_size(vector * vec)
{
	_vector_private * real = (_vector_private *) vec->private; 
	return real->size;
}

// Returns the vector current capacity
int _vector_capacity(vector * vec)
{
	_vector_private * real = (_vector_private *) vec->private; 
	return real->capacity;
}

// Swaps two elements of the vector; returns 0 on failure,
// 1 otherwise
int _vector_swap(vector * vec, int p1, int p2)
{
}

// Inserts a new element in the given position; returns 0
// on failure, 1 otherwise
int _vector_insert(vector * vec, int index, void * obj)
{
}

// Update value at the given position with the new object;
// returns 0 on failure, 1 otherwise
int _vector_put(vector * vec, int index, void * obj)
{
}

// Create a new array with given capacity
vector * new_vector(int cap) 
{
	vector * vec = (vector *) malloc(sizeof(vector));
	_vector_private * real = (_vector_private *) malloc(sizeof(_vector_private));
	real->size = 0;
	real->capacity = cap;
	real->elements = (void **) malloc(cap * sizeof(void *));
	real->cap_inc = 10;
	vec->private = (void *) real;

	// Method bindings
	vec->push_back = _vector_push_back;
	vec->push_front = _vector_push_front;
	vec->resize = _vector_resize;
	vec->get = _vector_get;
	vec->remove = _vector_remove;
	vec->pop_front = _vector_pop_front;
	vec->pop_back = _vector_pop_back;
	vec->set_cap_inc = _vector_auto_cap_inc;
	vec->size = _vector_size;
	vec->capacity = _vector_capacity;
	vec->swap = _vector_swap;
	vec->insert = _vector_insert;
	vec->put = _vector_put;

	return vec;
}
