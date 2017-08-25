/* Nguyen Ton
 * 08/24/2017
 * Merge 2 sorted arrays: put the short array B into long array A
 * - Start to insert/merge from the last element
 */
#include<iostream>
using namespace std;
const int lenA =6;
const int lenB=2;
int main()
{
  int a[lenA]={2,5,11,13};
  int b[lenB]={1,12};

  int indxTot =sizeof(a)/sizeof(int)-1;
  int indxA=3;
  int indxB=sizeof(b)/sizeof(int)-1;

  int length=indxTot+1;
  /* Possible mistakes:
   * - indxB >=0
   * - indxA>=0
   * - Careful with array index: numOfEle-1
   */
  while(indxB>=0)
    {
      if(indxA>=0 && a[indxA]>b[indxB])
	{
	  a[indxTot]=a[indxA];
	  indxA--;
	}
      else
	{
	  a[indxTot]=b[indxB];
	  indxB--;
	}
      indxTot--;
    }
  cout<<"length= "<<length<<endl;
  for(int i=0; i<length;i++)
    {
      cout<<a[i]<<endl;
    }
}
