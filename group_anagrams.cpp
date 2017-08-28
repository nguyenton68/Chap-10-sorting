/* Nguyen Ton
 * 08/27/2017
 * Group anagrams: print all anagrams next to each other
 * - Put all string into a vector
 * - Use another vector( dup), this vector besides string, it also contain index of each string
 * - Then sort each string inside dup, so the index for each string changes as well
 * - Print original vector with index from dup

 * - For example: v={cat, dog, tac, god}; index ={0,1,2,3};
 * After sort dup ={act(0) , act(2), dgo(1), dgo(3)};
 * Print v[dup[index]]
 */
#include<string>
#include<iostream>
#include<vector>
#include<algorithm> //for sorting
using namespace std;

bool comp(pair<int, string> a, pair<int,string> b)
{
  return a.second<b.second;
}
void printAnagram(vector<string> &v)
{
  vector<pair<int, string> > dup;
  for(int i=0; i<v.size(); i++)
    {
      string s = v[i];
      sort(s.begin(), s.end());
      dup.push_back(make_pair<int, string> (i, s));
    }
  sort(dup.begin(), dup.end(), comp);//sort using a user defined function
  for(int i=0; i<v.size(); i++)
    {
      cout<<v[dup[i].first]<<"\t";
    }
  cout<<endl;
}

int main()
{
  vector<string> V;
  V.push_back("cat");
  V.push_back("god");
  V.push_back("tac");
  V.push_back("dog");

  printAnagram(V);
}
