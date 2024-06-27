#include <iostream>

void merge( int  * arr,  int * left_array, int left_size,  int * right_array, int right_size )
{
    int i = 0;

    int j = 0;

    int u =0;

     while(j < left_size && u < right_size)
     {
         if (left_array[j] <= right_array[u])
         {
         arr[i++] = left_array[j++];
         }
         else
         {
             arr[i++] = right_array[u++];
         }
     }


    while (j < left_size)
    {
        arr[i++] = left_array[j++];
    }


    while (u < right_size)
    {
        arr[i++] = right_array[u++];
    }

}

void merge_sort(int * arr, int size)
{
   if (size == 1)
   {
       return;
   }

    int middle = size/2;

    int * left_array = new int[middle];

    int * right_array = new int[size - middle];

    for ( int i = 0; i < middle; i++)
    {
        left_array[i] = arr[i];
    }

    for ( int i = middle; i < size; i++)
    {
        right_array[i-middle] = arr[i];
    }

    merge_sort(left_array, middle);
    merge_sort(right_array,size - middle);

    merge(arr, left_array, middle, right_array, size - middle);

    delete [] left_array;
    delete [] right_array;

}

void print_array( int * arr, int size)
{
    for ( int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

int main() {

    int array_1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};

    int sizeof_array_1 = sizeof(array_1)/ sizeof(array_1[0]);

    print_array(array_1,sizeof_array_1);

    merge_sort(array_1,sizeof_array_1);

    print_array(array_1,sizeof_array_1);

    std::cout << std::endl << std::endl;




    int array_2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4 ,27, 28, 89, 2, 25, 74};

    int sizeof_array_2 = sizeof(array_2)/ sizeof(array_2[0]);

    print_array(array_2,sizeof_array_2);

    merge_sort(array_2,sizeof_array_2);

    print_array(array_2,sizeof_array_2);

    std::cout << std::endl << std::endl;


    int array_3[] = {24, 66, 20, 79, 30, -6, 19, 62, 94, 59, 0 ,7, 59, 546, 84, 60, 95, 62};

    int sizeof_array_3 = sizeof(array_3)/ sizeof(array_3[0]);

    print_array(array_3,sizeof_array_3);

    merge_sort(array_3,sizeof_array_3);

    print_array(array_3,sizeof_array_3);


    return 0;
}
