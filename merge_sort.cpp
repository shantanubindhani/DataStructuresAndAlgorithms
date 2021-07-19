// This is a Merge Sort demonstration

#include <iostream>

using namespace std;

int arr[] = { 3, 1, 0, 5, 2, 6, 4}; // you can modify array for testing and evalutation
int size = sizeof(arr)/sizeof(int); // gets the size of the above array //

void printArray()
{
    int i;
    cout << "[ ";
    for(i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]";
}


void mergeSubArrays(int l, int r) // l : left index AND r : right index 
{
    int m = (l + r)/2;   // mid point
    int i = l, j = m+1;  // i AND J ARE THE ITARATOR FOR THE 1ST AND 2ND HALVES OF THE ARRAY
    int k = 0;           // k is the Iterator for temporary array 
    int temp[((r-l)+1)]; // temp array to temporarily store the sorted portion of the main array

    // checks for the availability of elements 
    // on both the halves of array simultaneously
    while( (i <= m) && (j <= r))
    {
        if(arr[i] <= arr[j])  // if current element of ( 1st half <= 2nd half )
        {                     //
            temp[k] = arr[i]; //temp[current_Index] <-- current element of 1st half
            i++;
            k++; // increments value of respective indexs by 1
        }
        else
        {
            temp[k] = arr[j]; // same logic and working as previous block
            j++;              // only difference is, all this happens with 2nd half
            k++;              // not 1st half;
        }
    }
    // the loops below are used to ensure that 
    // none of the elements in any half is left unchecked!.
    while( i <= m ) // executes if 1st half still has elements unchecked
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while( j <= r ) // executes if 2nd half still has elements unchecked
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // this piece of code is used to replace the unsorted portion
    // with its sorted version.
    k = 0;
    for( i = l; i <= r; i++)
    {
        arr[i] = temp[k];
        k++;
    }
    // end of function
}

void mergeSort(int l, int r) // l : left index AND r : right index
{
    if( l < r )
    {
        int m = (l+r)/2; // calculating the midpoint of array
        mergeSort(l, m); // recursively calling mergeSort for the 1st half 
        mergeSort(m+1, r); // recursively calling mergeSort for the 2nd half
        mergeSubArrays(l, r); // merging back the two divided arrays in sorted order.
    }
}
// Driver code
int main()
{
    cout << "\n Before sorting : ";
    printArray();
    cout << "\n==============================================";
    
    mergeSort(0, size-1); // sorting takes place
    
    cout << "\n==============================================";
    cout << "\n After sorting : ";
    printArray();

    cout << "\n\n";
    return 0;
}