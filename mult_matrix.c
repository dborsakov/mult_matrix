#include <stdio.h>

#define A 15

int a[A*A], b[A*A], c[A*A];
int count = 0;

void print_matrix(int arr[A*A]) {
	int i;
	for (i=0;i<A*A;i++) {
		if ((i%A==0) && (i!=0)) printf("\n");
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

int main() {
	int i,j,k;
	for (i=0;i<A*A;i++) {
		a[i]=i;
		b[i]=A*A-i;
	}
	print_matrix(a);
	print_matrix(b);


	#pragma omp parallel for
	for (i=0;i<A;i++)
		for(j=0;j<A;j++) {
			c[A*i+j] = 0;
			for (k=0; k<A; k++) {
				c[A*i+j] += a[A*i+k] * b[k*A+j];
				//printf("%d * %d\n", a[A*i+k], b[k*A+j]); //вывод действий
				//count++; //счетчик количества действий
			}
		}
	printf("\n\n");
	for (i=0;i<A*A;i++) {
		if ((i%A==0) && (i!=0)) printf("\n");
		printf("%d ", c[i]);
	}

	if (count !=0) printf("\n%d", count);
	printf("\n");
return 0;
}
