#include <iostream>
using namespace std;
class Selection_Sort{
    private:
    int * arr;
    int n;
    public:
    Selection_Sort(int n1){
        n=n1;
       arr=new int[n];
    }
    ~Selection_Sort() {
        delete[] arr;
    }
    void enterArray(){
         for( int i=0; i<n; i++){
        cout << "Enter the element " << i+1 << " in an array: ";
        cin >> arr[i];
        if(arr[i] < 0){
            cout << "Enter the positive number " << endl;
        }
    }
    }
    void initialArray(){
        cout << "Initial array: " << endl;
    for( int i=0; i<n; i++){
       cout << arr[i] << " ";
    }
     cout << endl;
    }
    void sortArray(){
        int min;
    for(int i=0; i<n-1; i++){
      min=i;
      for(int j=i+1; j<n; j++){
      if(arr[j] < arr[min]){
        min=j;
      }
      }
      if(min !=i){
        int temp;
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
      }
    }
    }
    void displaySortedArray(){
        cout << "Sorted Array: " << endl;
         for(int k=0; k<n; k++){
        cout << arr[k] << " ";
    }
    }
};
int main(){
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
     if (n <= 0) {
        cout << "Invalid input. Number of elements must be positive." << endl;
        return 1;
    }
    Selection_Sort s1(n);
    s1.enterArray();
    s1.initialArray();
    s1.sortArray();
    s1.displaySortedArray();
    return 0;
}
