#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Vector specific method definitions

// Insert new element at the end of the vector
int _vector_push_back(vector * vec, void * obj) 
{
	int res = 0;
	if(vec->size >= vec->capacity)
		res = vec->resize(vec, vec->capacity + vec->cap_inc);
	vec->elements[vec->size++] = obj;
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
	void ** ptr = (void **) realloc(vec->elements, new_size * sizeof(void *));
	if(!ptr)
		return 0;
	else
	{
		vec->capacity = new_size;
		vec->size = vec->size < vec->capacity ? vec->size : vec->capacity;
		vec->elements = ptr;
		return 1;
	}
}

// Return the element in a given index
void * _vector_get(vector * vec, int index) 
{
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
}

// Set auto increment in capacity when push is
// done
void _vector_auto_cap_inc(vector * vec, int alloc) 
{
	vec->cap_inc = alloc;
}

// Create a new array with given capacity
vector * new_vector(int cap) 
{
	vector * vec = (vector *) malloc(sizeof(vector));
	vec->size = 0;
	vec->capacity = cap;
	vec->elements = (void **) malloc(cap * sizeof(void *));
	vec->cap_inc = 10;

	// Method bindings
	vec->push_back = _vector_push_back;
	vec->push_front = _vector_push_front;
	vec->resize = _vector_resize;
	vec->get = _vector_get;
	vec->remove = _vector_remove;
	vec->pop_front = _vector_pop_front;
	vec->pop_back = _vector_pop_back;
	vec->set_cap_inc = _vector_auto_cap_inc;

	return vec;
}
