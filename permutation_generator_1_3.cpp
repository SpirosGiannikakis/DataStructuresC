#include<iostream>
#include<stdio.h>
using namespace std;

template<class T>
inline void Swap(T& a, T& b){
  //Swap a and b
  T temp = a;
  a = b;
  b = temp;
}

template<class T>
void Perm(T list[], int k, int m){
  //Generate all permutations of list[k:m]

  int i;
  if(k == m){//Output a permutation
    for(i = 0; i <= m; i++){
    cout << list[i] << '\n';
    }
    cout <<'\n';
  }

  else //list[k:m] has more than one permutation
      //Generate these recursively
      for(i = k; i < m; i++){
        Swap(list[k], list[i]);
        Perm(list, k+1, m);
        Swap(list[k], list[i]);
      }
}

int main(){


return 0;
}
