#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

double eval(int *pj);

// Generate random bitstring
int* generateRandomVec()
{
  static int vec[100];

  random_device rd; 
  mt19937 eng(rd());  
  uniform_int_distribution<> distr(0, 1); 
  
  for (int n = 0; n<100; ++n)
    vec[n] = distr(eng); 
  
  return vec;

}


int main()
{

  int *bitstring;
  bitstring = generateRandomVec();
  cout<< "Initial bitstring" <<endl;
  for(int i = 0; i < 100; i++)
      {
        cout<< bitstring[i];
      }
  cout<<endl;    

  double fitness;
  double fitness_next;
  int* new_bitstring = bitstring;

  for(int j=0; j < 100; j++)
  {
  	
  	fitness = eval(bitstring);

    new_bitstring[j] = 1 - bitstring[j]; 
  	fitness_next = eval(new_bitstring);

	  if (fitness_next > fitness)
	  {
		  cout << "fitness = " << fitness_next <<", after flipping bit in position "<<j<<"."<<endl;
		  cout<<"And the bit string is "<<endl;
      for(int i = 0; i < 100; i++)
      {
       cout<<bitstring[i];
      }
      cout<<endl;
      cout<<"--------------------------------------------"<<endl;
   	  bitstring[j] = new_bitstring[j];
    }
    else
    {
      bitstring[j] = 1 - new_bitstring[j];
	  }
    	
  }
  	
}