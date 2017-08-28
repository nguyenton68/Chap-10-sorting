/* Seach an element in a rotated array
 * - Either left or right side of the midpoint is sorted
 * - Keep divide into 2 halves and search left, right
 *
 * - Problem: I don't understand the issue with a[mid]=a[left]
 */
#include<iostream>
using namespace std;
int searchRotated(int a[], int left, int right, int x)
{
  int mid=(left+right)/2;
  if(a[mid]==x)
    return mid;
  if(right<left)
    return -1;

  if(a[left]<a[mid])// normal sorted on left side
    {
      if(x>=a[left] && x<a[mid])
	return searchRotated(a,left,mid-1,x);//search left
      else
	return searchRotated(a,mid+1,right,x);//search right
    }
  else //normal sorter on right side
    {
      if(x>a[mid] && x<=a[right])
	return searchRotated(a,mid+1, right,x);//search right
      else
	return searchRotated(a,left,mid-1,x);//search left
    }
}
int main()
{
  int arr[12]={15,16,19,20,25,1,3,4,5,7,10,14};
  int result = searchRotated(arr,0,11,5);
  cout<<result<<endl;
}
