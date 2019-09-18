#include <iostream>
#include <random>
#include <algorithm>
#include <stdlib.h>     /* rand */
#include <bits/stdc++.h>

using namespace std;

double eval(int *pj);
void modify(int *bitstring, int begin_randomIndex, int end_randomIndex);

// Generate random bitstring
int* generateRandomVec()
{
  static int vec[150];

  random_device rd; 
  mt19937 eng(rd());  
  uniform_int_distribution<> distr(0, 1); 
  
  for (int n = 0; n<150; ++n)
    vec[n] = distr(eng); 
  
  return vec;

}


int main()
{

  int *bitstring;
  bitstring = generateRandomVec();
  cout<< "Initial bitstring" <<endl;
  for(int i = 0; i < 150; i++)
      {
        cout<< bitstring[i];
      }
  cout<<endl;    

  double fitness;
  double fitness_next;

  fitness = eval(bitstring);
  cout<<"Initial fitness = "<< fitness<<endl;

  int begin_randomIndex;
  int end_randomIndex;

  for(int k=0; k<60000; k++){
    begin_randomIndex = rand() % 150;
    end_randomIndex = begin_randomIndex + (rand() % (150-begin_randomIndex));
  
  	modify(bitstring, begin_randomIndex, end_randomIndex);
    fitness_next = eval(bitstring);

	  if (fitness_next > fitness)
	  {
		  cout << "fitness = " << fitness_next <<endl;
		  cout<<"And the bit string is "<<endl;
      for(int i = 0; i < 150; i++)
      {
       cout<<bitstring[i];
      }
      cout<<endl;
      cout<<"--------------------------------------------"<<endl;
   	  fitness = fitness_next;
    }
    else
    {
      modify(bitstring, begin_randomIndex, end_randomIndex);  
	  }
  }  	
  
}

void modify(int *bitstring, int begin_randomIndex, int end_randomIndex)
{
  for(int i = begin_randomIndex; i < end_randomIndex; i++)
  {
    bitstring[i] = 1 - bitstring[i];
  }
}
