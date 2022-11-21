/* Joshua Thompson
*  11/20/2022
*  Bankers Algorithm Implementation
*  Professor
*/

/* This file contains all necessary components for a bankers algorithm
implementation example. */

#include <iostream>
#include <string.h>
#include <vector>

// Global constant variables

#define p 5 // Amount of processes

#define r 3 // Types of resources available

int total = 0;

// Function headers

bool is_available(int,int[][r],int[][r],int[][r],int[]);

void safe_sequence(bool[],int[][r],int[][r],int[][r],int[],std::vector<int>);

// Main body

int main(){

  int allocated[p][r] = { { 0,1,1 },  // Amount of resources allocated to
                          { 2,0,0 },  // each process
                          { 3,0,2 },
                          { 2,1,1 },
                          { 0,0,2 } };

  int max[p][r] = { { 7,6,3 },  // Maximum amount of resources that can be
                    { 3,2,2 },  // allocated towards each process
                    { 9,0,2 },
                    { 2,2,2 },
                    { 4,3,3 } };

  int resources[r] = { 3,3,2 }; // Initial available resources

  int available[r]; // Available resources during program

  for(int i = 0; i < r; i++){

    int sum = 0;
    for(int j = 0; j < p; j++) sum += allocated[j][i];

    available[i] = resources[i] - sum;

  }

  std::vector<int> safe; // Used for displaying safe sequences

  bool marked[p];
  memset(marked, false, sizeof(marked));

  int need[p][r];  // Resources needed matrix
  for(int i = 0; i < p; i++){

    for(int j = 0; j < r; j++){

      need[i][j] = max [i][j] - allocated[i][j];

    }

  }

  std::cout << "Safe sequences are:" << std::endl;

  safe_sequence(marked, allocated, max, need, available, safe);

  std::cout << "\nThere are total " << total << " safe-sequences" << std::endl;

  return 0;

}


// Checks to see if resources for a given process is available
// Returns true if there is, otherwise returns false
bool is_available(int process, int allocated[][r], int max[][r],
                  int need[][r], int available[]){

  bool flag = true;

  for(int i = 0; i < r; i++){

    if(need[process][i] > available[i]) flag = false; // Checks if more
                                                      // resources are
  }                                                   // necessary

  return flag;

}

// Main component: Checks to see which sequences are safe from
// deadlock.  It will output any possible paths.
void safe_sequence(bool marked[], int allocated[][r], int max[][r],
                   int need[][r], int available[], std::vector<int> safe) {

  for(int i=0;i<p;i++){

    if(!marked[i] && is_available(i,allocated,max,need,available)){

      marked[i] = true; // Marks the process for no overlaps

      // Deallocates resources from process i
      for(int j = 0; j < r; j++) available[j] += allocated[i][j];

      safe.push_back(i);
      // Loops through all process to find a safe sequence
      safe_sequence(marked, allocated, max, need, available, safe);
      safe.pop_back();

      marked[i] = false; // Unmarks the process

      for(int j = 0; j < r; j++) available[j] -= allocated[i][j];

  }

  // When / if a safe sequence has been found, proceed to print it
  if(safe.size() == p){

    total++;
    for(int i = 0; i < p; i++){

      std::cout << "P" << safe[i]+1;
      if(i != (p - 1)) std::cout << "--> "; // Example: P1--> P2--> P3--> etc

    }

    std::cout << std::endl; // Move to the next sequence

  }


}
}
