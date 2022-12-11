#include <iostream>
using namespace std;

void my_swap(int arr[], int index1, int indexM){
    int mid = arr[index1];
    arr[index1] = arr[indexM];
    arr[indexM] = mid;
}
/*  phân tích max(0, a[i] - a[i-1]), ta thấy để giá trị cách nhiệt lớn nhất
 thì giá trị lớn nhất xếp cuối và giá trị bé nhất xếp đầu  */
int main(int argc, char **argv){
    int N;
    cout<<"Nhap so luong so can nhap N = ";
    cin>>N;cout<<endl;
    int *dayso = new int[N], min, max, indexMax, indexMin;
    cout<<"Nhap day so: "<<endl;
    for(int i =0;i<N;i++){
        cin>>dayso[i];
        if(i==0){
            min = dayso[i];
            indexMin = i;
            max = dayso[i];
            indexMax = i;
        }
        else{
            if (dayso[i]>max){
                max = dayso[i];
                indexMax = i;
            }
            if(dayso[i]<min){
                min = dayso[i];
                indexMin = i;
            }
        }
    }
    cout<<"So max = "<<max<<" voi chi so: "<<indexMax<<endl;
    my_swap(dayso,N-1,indexMax);
    cout<<"So min = "<<min<<" voi chi so: "<<indexMin<<endl;
    my_swap(dayso,0,indexMin);
    cout<<"Day so sau sap xep: "<<endl;
    for(int i=0;i<N;i++){
        cout<<" "<<dayso[i];
    }
    cout<<endl;
    delete[] dayso;
    return 0;
}