#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//快排
void quickSort(int *number,int first,int last){
	int i, j, pivot;
	int temp;
	if (first<last) {
		pivot = first;
		i = first;
		j = last;
		while (i<j) {
			while (number[i] <= number[pivot] && i<last)
				i++;
			while (number[j]>number[pivot])
				j--;
			if (i<j) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quickSort(number, first, j - 1);
		quickSort(number, j + 1, last);
	}
}
//归并
 
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void merge_sort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
 
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
        
    }
}


//选择
void SelectSort1(int r[],int n) {
	int i,j,min,temp;
	for(i=0; i<n-1; i++) {	 
		min=i;	
		for(j=i+1; j<n; j++) {	 
			if(r[j]<r[min])	
				min=j;
		}	 
		temp=r[i];	
		r[i]=r[min];
		r[min]=temp;
	}
}

//冒泡
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) 
    {
        for (j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//插入
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int a[10],a1[10],a2[10],a3[10],a4[10],a5[10];
    int b[100],b1[100],b2[100],b3[100],b4[100],b5[100];
    int c[1000],c1[1000],c2[1000],c3[1000],c4[1000],c5[1000];
    int d[10000],d1[10000],d2[10000],d3[10000],d4[10000],d5[10000];
    long e[100000];
    long e1[100000];

    for(int i=0;i<10;i++){
        a[i]=rand();
        a1[i]=a[i];
        a2[i]=a[i];
        a3[i]=a[i];
        a4[i]=a[i];
        a5[i]=a[i];
    }
    for(int i=0;i<100;i++){
        b[i]=rand();
        b1[i]=b[i];
        b2[i]=b[i];
        b3[i]=b[i];
        b4[i]=b[i];
        b5[i]=b[i];
    }
    for(int i=0;i<1000;i++){
        c[i]=rand();
        c1[i]=c[i];
        c2[i]=c[i];
        c3[i]=c[i];
        c4[i]=c[i];
        c5[i]=c[i];
    }
    for(int i=0;i<10000;i++){
        d[i]=rand();
        d1[i]=d[i];
        d2[i]=d[i];
        d3[i]=d[i];
        d4[i]=d[i];
        d5[i]=d[i];
    }
    clock_t start, end;
    double cpu_time_used;
    printf("十个数排序\n");

    start=clock();
    quickSort(a1,0,10);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("快排运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    merge_sort(a2,0,10);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("归并运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    SelectSort1(a3,10);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("选择运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    bubbleSort(a4,10);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("冒泡运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    insertionSort(a5,10);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("插入运行时间： %f 秒\n", cpu_time_used);

    printf("一百个数个数排序\n");

    start=clock();
    quickSort(b1,0,100);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("快排运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    merge_sort(b2,0,100);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("归并运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    SelectSort1(b3,100);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("选择运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    bubbleSort(b4,100);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("冒泡运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    insertionSort(b5,100);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("插入运行时间： %f 秒\n", cpu_time_used);


    printf("一千个数排序\n");

    start=clock();
    quickSort(c1,0,1000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("快排运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    merge_sort(c2,0,1000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("归并运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    SelectSort1(c3,1000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("选择运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    bubbleSort(c4,1000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("冒泡运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    insertionSort(c5,1000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("插入运行时间： %f 秒\n", cpu_time_used);


    printf("一万个数排序\n");
    start=clock();
    quickSort(d1,0,10000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("快排运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    merge_sort(d2,0,10000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("归并运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    SelectSort1(d3,10000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("选择运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    bubbleSort(d4,10000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("冒泡运行时间： %f 秒\n", cpu_time_used);

    start=clock();
    insertionSort(d5,10000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("插入运行时间： %f 秒\n", cpu_time_used);

    printf("十万个数排序\n");
    for(long i=0;i<100000;i++){
        e[i]=rand();
        e1[i]=e[i];
    }
    start=clock();
    quickSort(e1,0,100000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("快排运行时间： %f 秒\n", cpu_time_used);

    for(long i=0;i<100000;i++){
        e[i]=rand();
        e1[i]=e[i];
    }
    start=clock();
    merge_sort(e1,0,100000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("归并运行时间： %f 秒\n", cpu_time_used);

    for(long i=0;i<100000;i++){
        e[i]=rand();
        e1[i]=e[i];
    }
    start=clock();
    SelectSort1(e1,100000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("选择运行时间： %f 秒\n", cpu_time_used);

    for(long i=0;i<100000;i++){
        e[i]=rand();
        e1[i]=e[i];
    }
    start=clock();
    bubbleSort(e1,100000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("冒泡运行时间： %f 秒\n", cpu_time_used);

for(long i=0;i<100000;i++){
        e[i]=rand();
        e1[i]=e[i];
    }
    start=clock();
    insertionSort(e1,100000);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("插入运行时间： %f 秒\n", cpu_time_used);

return 0;
    
}
