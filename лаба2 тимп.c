#include <stdio.h>
#include <stdlib.h>

typedef struct Path
{
    int* arr;
    int pos;
} Path;
int* search_(int** array, int size, int v)
{
	int* mass = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		if (i == v)
			mass[i] = 0;
		else
			mass[i] = 3222;
	}
	int temp[size];
	for(int i = 0;i < size;i++)
	    temp[i] = 1;
	int t, minl, q;
	do {
		minl = 0;
		q = 3222;
		for (int i = 0; i < size; i++) {
			if ((temp[i] == 1) && (mass[i] < 3222)) {
				minl = mass[i];
				q = i;
			}
		}
		if (q != 3222) {
			for (int i = 0; i < size; i++) {
				if (array[q][i] > 0) {
					t = minl + array[q][i];
					if (t < mass[i])
						mass[i] = t;
				}
			}
			temp[q] = 0;
		}
	} while (q < 3222);
	return mass;
}
int full_bust(int** arr,int arr_len,Path tmp_path,int* res_pas){
    int length=-1;
    if(tmp_path.pos!=arr_len){
        for(int i=0;i<arr_len;i++){
        	int in_mas=0;
        	for (int j = 0; j < arr_len; ++j){
        		if(tmp_path.arr[j]==i){
        			in_mas=1;
        			break;
        		}
        	}
            if(!in_mas){
                if(!(tmp_path.pos!=0 && arr[tmp_path.arr[tmp_path.pos-1]][i]==0)){
                	tmp_path.arr[tmp_path.pos++]=i;
	                int tmp = full_bust(arr,arr_len,tmp_path,res_pas); 
	                if(tmp<length || length==-1){
	                    length = tmp; 
	                }
	                tmp_path.arr[--tmp_path.pos]=-1;
                }
            }
        }
    }
    else{
    	int tmp = 0;
        for(int i=1;i<arr_len;i++){
	        tmp+=arr[tmp_path.arr[i-1]][tmp_path.arr[i]]; 
        }
        length = tmp;
        for(int i=0;i<arr_len;i++){
            res_pas[i]=tmp_path.arr[i];
        }
    }
        
    return length; 
}


void optimize_ways(int** arr, int arr_len)
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

int calc_length(int** mas,int n,int* path){
    int res=0;
    for(int i=1;i<n;i++){
        res+=mas[path[i-1]][path[i]]; 
    }
    return res; 
}

int main(){
    int size_of_matrix;
    printf("%s", "Введите количество вершин:");
    scanf("%d",&size_of_matrix);
    Path tmp_path;
    tmp_path.arr = malloc(sizeof(int)*size_of_matrix);
    tmp_path.pos = 0;
    int graph[size_of_matrix][size_of_matrix];
    for (int i = 0; i < size_of_matrix; ++i){
        tmp_path.arr[i]=-1;
    }
    int* res_path = malloc(sizeof(int)*size_of_matrix);
    int** arr = malloc(sizeof(int*)*size_of_matrix);
    for(int i=0;i<size_of_matrix;i++){
        arr[i] = malloc(sizeof(int)*size_of_matrix);
    }
    printf("%s", "Введите кол-во путей:");
    int cnt_of_ways;
    scanf("%d",&cnt_of_ways);
    
    for (int i = 0; i < cnt_of_ways; ++i)
    {
    	printf("Введите начальный , конечный и вес между ними:");
    	int x,y,w;
    	scanf("%d %d %d",&x,&y,&w);
    	arr[x - 1][y - 1] = w;
    	graph [x - 1][y - 1] = arr[x - 1][y - 1];
    }
    printf("\n");
    
    for (int i = 0; i < size_of_matrix; ++i){
		for (int j = 0; j < size_of_matrix; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	    int temp;
	printf("Точка начала:\n");
	scanf("%d", &temp);
	int g = 0;
	int* f = search_(arr, size_of_matrix, temp  );
	for (int i = 0; i < size_of_matrix; i++) {
		if (f[i] <= 100000) {
			printf("Кратчайший путь %d -> %d: %d\n", temp, g, f[i]);
		}
		g++;
	}

    int length = full_bust(arr,size_of_matrix,tmp_path,res_path);
    printf("%s%d\n", "Длинна пути: ",calc_length(arr,size_of_matrix,res_path));
   printf("%s", "Путь: ");
	for(int i=0;i<size_of_matrix;i++)
        printf("%d ", res_path[i]);
	printf("\n");
    for(int i=0;i<size_of_matrix;i++){
        free(arr[i]);
    }
	free(arr);
	free(tmp_path.arr);
	free(res_path);
	return 0;
}
