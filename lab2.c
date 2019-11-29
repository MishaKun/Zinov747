#include <stdio.h>
#include <stdlib.h>

typedef struct lab2
{
    int* arr;
    int position;
} Path;
int* ser(int** array, int r, int v)
{
	int* tmp = (int*)malloc(r * sizeof(int));
	for (int i = 0; i < r; i++) {
		if (i == v)
			tmp[i] = 0;
		else
			tmp[i] = 3222;
	}
	int temp[r];
	for(int i = 0;i < r;i++)
	    temp[i] = 1;
	int t, minl, dek;
	do {
		minl = 0;
		dek = 3222;
		for (int i = 0; i < r; i++) {
			if ((temp[i] == 1) && (tmp[i] < 3222)) {
				minl = tmp[i];
				dek = i;
			}
		}
		if (dek != 3222) {
			for (int i = 0; i < r; i++) {
				if (array[dek][i] > 0) {
					t = minl + array[dek][i];
					if (t < tmp[i])
						tmp[i] = t;
				}
			}
			temp[dek] = 0;
		}
	} while (dek < 3222);
	return tmp;
}
int b(int** arr,int len_ar,Path t_p,int* res_pas){
    int length=-1;
    if(t_p.position!=len_ar){
        for(int i=0;i<len_ar;i++){
        	int in=0;
        	for (int j = 0; j < len_ar; ++j){
        		if(t_p.arr[j]==i){
        			in=1;
        			break;
        		}
        	}
            if(!in){
                if(!(t_p.position!=0 && arr[t_p.arr[t_p.position-1]][i]==0)){
                	t_p.arr[t_p.position++]=i;
	                int tmp = b(arr,len_ar,t_p,res_pas); 
	                if(tmp<length || length==-1){
	                    length = tmp; 
	                }
	                t_p.arr[--t_p.position]=-1;
                }
            }
        }
    }
    else{
    	int tmp = 0;
        for(int i=1;i<len_ar;i++){
	        tmp+=arr[t_p.arr[i-1]][t_p.arr[i]]; 
        }
        length = tmp;
        for(int i=0;i<len_ar;i++){
            res_pas[i]=t_p.arr[i];
        }
    }
        
    return length; 
}


void sec_task(int** arr, int arr_len)
{
    for (int mid=0; mid<arr_len; mid++){
    	for (int start=0; start<arr_len; start++){
        	for (int end=0; end<arr_len; end++){
            	if (arr[start][mid] && arr[mid][end] && start!=end){
                	if (arr[start][end]>arr[start][mid]+arr[mid][end] || arr[start][end]==0){
                        arr[start][end]=arr[start][mid]+arr[mid][end];                      	
                    }
                }
            }
        }
    }          								
}

int find_len(int** mas,int n,int* path){
    int res=0;
    for(int i=1;i<n;i++){
        res+=mas[path[i-1]][path[i]]; 
    }
    return res; 
}

int main(){
    int size_matr;
    printf("%s", "Количество вершин =");
    scanf("%d",&size_matr);
    Path tmp_path;
    tmp_path.arr = malloc(sizeof(int)*size_matr);
    tmp_path.position = 0;
    int graph[size_matr][size_matr];
    for (int i = 0; i < size_matr; ++i){
        tmp_path.arr[i]=-1;
    }
    int* res_path = malloc(sizeof(int)*size_matr);
    int** arr = malloc(sizeof(int*)*size_matr);
    for(int i=0;i<size_matr;i++){
        arr[i] = malloc(sizeof(int)*size_matr);
    }
    printf("%s", "количество путей =");
    int count_ways;
    scanf("%d",&count_ways);
    
    for (int i = 0; i < count_ways; ++i)
    {
    	printf("Введите начальный объект , конечный объект и расстояние между ними =");
    	int x,y,w;
    	scanf("%d %d %d",&x,&y,&w);
    	arr[x - 1][y - 1] = w;
    	graph [x - 1][y - 1] = arr[x - 1][y - 1];
    }
    printf("\n");
    
    for (int i = 0; i < size_matr; ++i){
		for (int j = 0; j < size_matr; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	    int temp;
	printf("Откуда считать =\n");
	scanf("%d", &temp );
	int g = 0;
	int* f = ser(arr, size_matr, temp - 1  );
	for (int i = 0; i < size_matr; i++) {
		if (f[i] <= 100000) {
			printf("Минимальный путь %d -> %d: %d\n", temp , g+1, f[i]);
		}
		g++;
	}

    int length = b(arr,size_matr,tmp_path,res_path);
    printf("%s%d\n", "Расстояние = ",find_len(arr,size_matr,res_path));
   printf("%s", "Путь = ");
	for(int i=0;i<size_matr;i++)
        printf("%d ", (res_path[i] +1));
	printf("\n");
    for(int i=0;i<size_matr;i++){
        free(arr[i]);
    }
	free(arr);
	free(tmp_path.arr);
	free(res_path);
	return 0;
}
