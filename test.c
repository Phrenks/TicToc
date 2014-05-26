#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "TicToc.h"

int main(){
  // Declare timers
  tictoc_add_timer(test);
  tictoc_add_timer(internal_test);
  tictoc_add_timer(internal_test_2);
  
  // Start general timer
  tictoc_start(test);

  int i=0;
  for(i=0; i<10000; ++i){
    // Start first internal timer
    tictoc_start(internal_test);
    printf("%d\r", i);
    // Stop first internal timer
    tictoc_stop(internal_test);

    // Start first internal timer
    tictoc_start(internal_test_2);
    printf("%d\r", i+1000);
    // Stop first internal timer
    tictoc_stop(internal_test_2);    
  }

  // Stop general timer
  tictoc_stop(test);

  // Show timer
  tictoc_print(test);
  tictoc_print_accum(internal_test);
  tictoc_print_accum(internal_test_2);
  
  return 0;
}
