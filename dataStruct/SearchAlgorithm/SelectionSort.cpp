#include <iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

const int Max_Data = 25;
const int offset = 10;
const int range = 101;

const int NBUCKET = 6;
const int INTERNAL = 10;
struct Node{
    int data;
    Node *next;
};



class SortAlgorithm{

};

int * getData(int offset, int range){
    srand((unsigned)time(NULL));
    static int data[Max_Data];
    for(int i =0; i <  Max_Data; i++){
        data[i] = offset + (rand() % range);
    }
    return data;
}

void swap(int &sorce, int &destination){
    int tmp = sorce;
    sorce =  destination;
    destination = tmp;
}/**/

void Pswap(int *sor, int *des){
    int tmp = *sor;
    *sor = *des;
    *des = tmp;
}
/**/
void selectionSort(int arr[], int size){
    for(int i = 0; i < size -1; i++){
        int min_idx = i;
        for(int j = i + 1; j < size; j ++){            
            if(arr[j] < arr[min_idx]){
                swap(arr[i], arr[j]);                
                //Pswap(&arr[j], &arr[i]);
                min_idx = j;
            }
        }
    }
}

void bubbleSort(int arr[], int size){
    for(int step = 0; step < size; ++step){
        for(int i = 0; i < size -step; ++i){
            if(arr[i] > arr[i + 1]){
                swap(arr[i], arr[i+1]);
            }
        }
    }
}

void insertionSort(int arr[], int size){
    for(int step = 1; step < size; step++){
        int key = arr[step];
        int j = step -1;
        while(key < arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right){
    int leftIndex= mid -left +1;
    int rightIndex = right - mid;

    int leftArray[leftIndex], rightArray[rightIndex];
    for(int i = 0; i < leftIndex; i++){
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < rightIndex; j++){
        rightArray[j] = arr[mid + 1 + j];
    }
    int indxOfLeftArr = 0;
    int indxOfRightArr = 0;
    int indxOfMergedArr = left;

    while(indxOfLeftArr < leftIndex && indxOfLeftArr < rightIndex){
        if(leftArray[indxOfLeftArr] <= rightArray[indxOfRightArr]){
            arr[indxOfMergedArr] = leftArray[indxOfLeftArr];
            indxOfLeftArr++;
        }else{
            arr[indxOfMergedArr] = rightArray[indxOfRightArr];
            indxOfRightArr++;
        }
        indxOfMergedArr++;
    }
    while(indxOfLeftArr < leftIndex){
        arr[indxOfMergedArr] = leftArray[indxOfLeftArr];
        indxOfLeftArr++;
        indxOfMergedArr++;
    }
    while(indxOfRightArr < rightIndex){
        arr[indxOfMergedArr] = rightArray[indxOfRightArr];
        indxOfRightArr++;
        indxOfMergedArr++;
    }

}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + (right - 1)) /2;    
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int partion(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low -1);
    for (int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            Pswap(&arr[i], &arr[j]);
        }
    }
    Pswap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partion(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi+1, high);
    }
}

int getBucketIndex(int value){
    return value/INTERNAL;
}

struct Node *InsertionSort(struct Node *list){
    struct Node *k, *nodeList;
    if(list == 0 || list->next == 0){
        return list;
    }
    nodeList = list;
    k = list->next;
    nodeList->next = 0;
    while(k != 0){
        struct Node *ptr;
        if(nodeList->data = k->data){
            struct Node *tmp;            
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            continue;
        }
        for(ptr = nodeList; ptr->next !=0; ptr =ptr->next){
            if(ptr->next->data > k->data){
                break;
            }
        }
        if (ptr->next != 0) {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        } else {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return nodeList;
}

void printBuckets(struct Node *list){
    struct Node *cur = list;
    while(cur){
        cout<< setw(3) << cur->data;
        cur = cur->next; 
    }
}

void BucketSort(int arr[]){
    int i, j;
    Node **buckets;
    buckets = (Node **)malloc(sizeof(Node *) *NBUCKET);

    for(i = 0; i < NBUCKET; ++i){
        buckets[i] = NULL;
    }
    for(i =0; i < Max_Data; ++i){
        Node *current;
        int pos = getBucketIndex(arr[i]);
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = arr[i];
        current->next = buckets[pos];
        buckets[pos] = current;        
    }
    for(i = 0; i < NBUCKET; i++){
        cout<<"Bucket["<<i<<"] :";
        printBuckets(buckets[i]);
        cout<<endl;
    }
    for(i = 0; i <NBUCKET; ++i){
        buckets[i] = InsertionSort(buckets[i]);
    }
    cout << "-------------" << endl;
    cout << "Bucktets after sorted" << endl;
    for (i = 0; i < NBUCKET; i++) {
        cout << "Bucket[" << i << "] : ";
        printBuckets(buckets[i]);
        cout << endl;
    }

    // Put sorted elements on arr
    for (j = 0, i = 0; i < NBUCKET; ++i) {
        struct Node *node;
        node = buckets[i];
        while (node) {
        arr[j++] = node->data;
        node = node->next;
        }
    }

    for (i = 0; i < NBUCKET; ++i) {
        struct Node *node;
        node = buckets[i];
        while (node) {
        struct Node *tmp;
        tmp = node;
        node = node->next;
        //free(tmp);
        }
    }
    //free(buckets);
    //return;
}

void print(int arr[]){
    for(int i =0; i < Max_Data; ++i){
        cout<<setw(3) << arr[i];
    }
    cout<<endl;
}

void PrintData(int arr[], int size){   
    for(int i =0; i <  Max_Data; i++){
        cout<<*(arr + i) << " ";
    }
    cout<<endl;
}

int main(){
    int *arrayData = getData(offset, range);

    cout <<"Unsorted Data " <<endl;
    PrintData(arrayData, Max_Data);

    cout <<"Sorted Data using Selection sort method " <<endl;
    clock_t start_sel = (int)clock();
    selectionSort(arrayData, Max_Data);
   // cout<<"Execution Time in second: "<<setw(5) <<setprecision(2) <<(float)(clock() - start_sel / CLOCKS_PER_SEC) <<endl;
    PrintData(arrayData, Max_Data);

    cout <<"Sorted Data using bubble sort method " <<endl;
    clock_t start_bubb = (int)clock();
    bubbleSort(arrayData, Max_Data);
    cout<<"Execution Time in second: " <<(float)(clock() - start_bubb / CLOCKS_PER_SEC) <<endl;
    PrintData(arrayData, Max_Data);

    cout <<"Sorted Data using insertion sort method " <<endl;
    clock_t start_ins = (int)clock();
    insertionSort(arrayData, Max_Data);
    cout<<"Execution Time in second: "<<setw(5) <<setprecision(2) <<(float)(clock() - start_ins / CLOCKS_PER_SEC) <<endl;
    PrintData(arrayData, Max_Data);

    cout <<"Sorted Data using Merge sort method " <<endl;
    clock_t start_meg = (int)clock();
    mergeSort(arrayData, 0, Max_Data - 1);
    cout<<"Execution Time in second: "<<setw(5) <<setprecision(2) <<(float)(clock() - start_meg / CLOCKS_PER_SEC) <<endl;
    PrintData(arrayData, Max_Data);
 
    cout <<"Sorted Data using Quick sort method " <<endl;
    clock_t start_quick = (int)clock();
    quickSort(arrayData, 0, Max_Data - 1);
    cout<<"Execution Time in second: "<<setw(5) <<setprecision(2) <<(float)(clock() - start_quick / CLOCKS_PER_SEC) <<endl;
    PrintData(arrayData, Max_Data);

    cout <<"Sorted Data using Bucket sort method " <<endl;
    clock_t start_bucket = (int)clock();
    BucketSort(arrayData); //, 0, Max_Data - 1);
    cout<<"Execution Time in second: "<<setw(5) <<setprecision(2) <<(float)(clock() - start_bucket / CLOCKS_PER_SEC) <<endl;
    PrintData(arrayData, Max_Data);

  return 0;
  }