#ifndef VECTOR_H_
#define VECTOR_H_

// Vector struct definition
typedef struct vector 
{
	// Members
	void * private;

	// Methods
	int (*push_back) (struct vector * vec, void * obj);
	int (*push_front) (struct vector * vec, void * obj);
	int (*resize) (struct vector * vec, int new_size);
	void * (*get) (struct vector * vec, int index);
	void * (*remove) (struct vector * vec, int index);
	void * (*pop_front) (struct vector * vec);
	void * (*pop_back) (struct vector * vec);
	void (*set_cap_inc) (struct vector * vec, int alloc);
	int (*size) (struct vector * vec);
	int (*capacity) (struct vector * vec);
	int (*swap) (struct vector * vec, int p1, int p2);
	int (*insert) (struct vector * vec, int index, void * obj);
	int (*put) (struct vector * vec, int index, void * obj);
} vector;

// Initialize a new vector
vector * new_vector(int cap);

#endif
