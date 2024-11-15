#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tree[100];

void maxHeapify(char tree[100],int size,int i) {
	int largest,l,r,temp;
	largest = i;
	l = 2*i+1;
	r = 2*i+2;
	if(l<size && tree[l]>tree[largest])
        largest = l;
    if(r<size && tree[r]>tree[largest])
        largest = r;

    if(largest!=i) {
        temp = tree[i];
        tree[i] = tree[largest];
        tree[largest] = temp;
        maxHeapify(tree,size,largest);
    }    
}

void heapSort(char tree[100],int size) {
    int n = size;
    int temp;
    for(int i = n/2 -1; i>=0 ; i--) {
        maxHeapify(tree,size,i);
    }

    for(int i=n-1 ; i>0 ; i++) {
        temp = tree[i];
        tree[i] = tree[0];
        tree[0] = temp;
        maxHeapify(tree,n,0);
    }
}

void main() {
	int size;
	printf("Enter the size of tree : ");
	scanf("%d",&size);
	printf("Enter the elements : \n");
	for(int i = 0;i<size; i++) {
		scanf("%d",&tree[i]);
	}

}