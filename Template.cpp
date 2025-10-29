#include <iostream>
using namespace std;
template <class T>
void SelectionSort(T arr[ ], int n) {
    cout << "\nSorting elements of array: " << endl;
    for (int i = 0; i < n - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                std::swap(arr[min_index], arr[i]);
            }
    }
    cout << "Displaying sorted elements: ";
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
};
int main () {
    char yn;
    do{
        cout<<"\n----Menu----\n";
        cout<<"1.Integer array\n";
        cout<<"2.Float array\n";
    int ch;
    cout << "Enter choice: ";
    cin>>ch;
    switch(ch){
    case 1:
    {int n1;
    cout << "Enter size of integer array: ";
    cin >> n1;
    int a[n1];
    cout << "Enter " << n1 << " elements below: "<< endl;
    for (int i=0; i<n1; i++) {
        cin >> a[i];
    }
    SelectionSort(a, n1);
    break;
    }
    case 2:
    {int n2;
    cout << "Enter size of float array: ";
    cin >> n2;
    float b[n2];
    cout << "Enter " << n2<< " elements below: "<< endl;
    for (int i=0; i<n2; i++) {
        cin >> b[i];
    }
    SelectionSort(b, n2);
    break;}
    }
    cout<<"\nDo you want to continue: ";
    cin>>yn;
    }while(yn=='Y'||yn=='y');
    cout<<"Thank You!";
    return 0;
}
