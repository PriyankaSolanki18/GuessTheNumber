#include<iostream>
using namespace std;
//menu
void menu(){
     cout<<"------------------MENU------------------"<<endl;
     cout<<"Press 1 to sort array in ascending order"<<endl;
     cout<<"Press 2 to sort array in descending order"<<endl;
     cout<<"Press 3 to apply binary search"<<endl;
     cout<<"Press 4 to exit"<<endl;
}

//sorting in ascending order
void sortArrayAsc(int arr[], int len)
{
    int i, j, temp;
    for(i=0; i<(len-1); i++)
    {
        for(j=0; j<(len-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<endl;
    cout<<"Ascending sorted array is : ";
    for(int k=0;k<len;k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}

//Sorting in descending order
void sortArrayDesc(int arr[], int len){
    int i, j, temp;
    for(i=0;i<len;i++)
	{		
		for(j=i+1;j<len;j++)
		{
			if(arr[i]<arr[j])
			{
				temp  =arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
    cout<<endl;
    cout<<"Descending sorted array is : ";
    for(int k=0;k<len;k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
} 

//Binary Search
int binarySearch(int arr[], int len, int num)
{
    sortArrayAsc(arr,len);
    sortArrayDesc(arr,len);
    cout<<"Enter element to be searched : ";
    cin>>num;
    int s, e, mid;
    s = arr[0];
    e = arr[len-1];
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]==num){
            // return mid;
            cout<<"Element "<<arr[mid]<<" found at position "<<mid<<endl;
        }else if(arr[mid]>num){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}

//main function
int main()
{
    int len, i, arr[100], num, pos, choice;
    cout<<"Enter the Size of array : ";
    cin>>len;
    cout<<"Enter "<<len<<" Elements : ";
    for(i=0; i<len; i++)
        cin>>arr[i];
        
        do{
            cout<<"\n";
            menu();
            cout<<endl;
            cout<<"Enter your choice : ";
            cin>>choice;
            switch(choice){
            case 1:
            sortArrayAsc(arr, len);
            break;
            case 2:
            sortArrayDesc(arr, len);
            break;
            case 3:
            binarySearch(arr,len,num);
            break;
            case 4:
            exit(0);
            break;
            default:
            cout<<"Invalid choice Try Again"<<endl;
            }
        }while(choice!=3);
   
   
    // if(pos==0)
    //     cout<<endl<<num<<" isn't available in the list";
    // else
    //     cout<<endl<<num<<" is available at Position "<<pos;
    // cout<<endl;
    return 0;
}