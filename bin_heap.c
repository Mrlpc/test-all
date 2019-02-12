#include <stdio.h>

void adjust_heap(int *array,int start,int end)
{
	int temp = array[start];
	int root = start;
	int child = 2 * root + 1;
	while(child < end){
		if(child+1 < end && array[child] < array[child + 1]){
			child++;
		}
		if(temp >= array[child]){
			break;
		}
		array[root] = array[child];

		root = child;
		child = 2 * child + 1;
	}
	array[root] = temp;
}

void sort(int * arr,int len){
	int i = 0;
	for(i = len / 2;i >=0;i--)
		adjust_heap(arr,i,len-1);
	
	for(i=len-1;i>0;i--){
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		adjust_heap(arr,0,i);
	}
}
int main()
{
	int arr[10] = {3,1,2,0,9,5,8,6,4,7};
	sort(arr,10);
	int i = 0;
	for(i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
