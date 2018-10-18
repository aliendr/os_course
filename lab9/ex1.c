#include <limits.h>
#include <stdio.h>
#include <malloc.h>

struct a{
	int id, age;
}typedef page_frame ;

int oldest_p(page_frame *frame, int size) {
	int oldest = frame[0].age;
	for (int i = 0; i < size; i++) {
		if (frame[i].age <= frame[oldest].age)
			oldest = i;
	}
	return oldest;
}

int is_inframe(page_frame *frame, int size, int id) {
	int contains = 0;
	for (int i = 0; i < size; i++) {
		if (frame[i].id == id) {
			contains = 1;
		}
	}
	return contains;
}

int main(int args, char const *argv[]) {
	FILE *f = fopen("input.txt","r");
	int in;
	int size = atoi(argv[1]);
	page_frame *frame = (page_frame*)calloc(size,sizeof(page_frame));
	int age = 1, mis = 0, hit = 0;
	while (fscanf(f, "%d", &in) != EOF) {
		int oldest = oldest_p(frame, size);
		if (is_inframe(frame,size,in)) {
			hit++;
		} else {
			mis++;
		}
		frame[oldest].id = in;
		frame[oldest].age = age;
		age++;
	}

	free(frame);
	printf("\nHit = %d\nMiss = %d\nHit/Miss ratio = %f\n", hit, mis, (float) hit/mis);
	
	return 0;
} 
