#ifndef VECTOR_H_
#define VECTOR_H_

// Vector struct definition
typedef struct vector 
{
	// Members
	int size;
	int capacity;
	int cap_inc;
	void ** elements;

	// Methods
	int (*push_back) (struct vector * vec, void * obj);
	int (*push_front) (struct vector * vec, void * obj);
	int (*resize) (struct vector * vec, int new_size);
	void * (*get) (struct vector * vec, int index);
	void * (*remove) (struct vector * vec, int index);
	void * (*pop_front) (struct vector * vec);
	void * (*pop_back) (struct vector * vec);
	void (*set_cap_inc) (struct vector * vec, int alloc);
} vector;

// Vector specific method definitions
// (INVISIBLE METHODS)
int _vector_push_back(vector * vec, void * obj);
int _vector_push_front(vector * vec, void *obj);
int _vector_resize(vector * vec, int new_size);
void * _vector_get(vector * vec, int index);
void * _vector_remove(vector * vec, int index);
void * _vector_pop_front(vector * vec);
void * _vector_pop_back(vector * vec);
void _vector_auto_cap_inc(vector * vec, int alloc);

// Initialize a new vector
vector * new_vector(int cap);

#endif
