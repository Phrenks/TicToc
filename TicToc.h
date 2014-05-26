#include <stdio.h>
#include <time.h>
#include <stdint.h>

// Add a new timer
#define tictoc_add_timer(tname) struct timespec tictoc_start_##tname##_t;  struct timespec tictoc_end_##tname##_t; uint64_t tictoc_elapsed_##tname##_t=0; uint64_t tictoc_elapsed_accum_##tname##_t=0;

// Start a timer
#define tictoc_start(tname) do {clock_gettime(CLOCK_MONOTONIC, &tictoc_start_##tname##_t); } while(0);

// Stop a timer
#define tictoc_stop(tname) do { clock_gettime(CLOCK_MONOTONIC, &tictoc_end_##tname##_t); tictoc_elapsed_##tname##_t = ((tictoc_end_##tname##_t.tv_nsec + (tictoc_end_##tname##_t.tv_sec*1000000000)) - (tictoc_start_##tname##_t.tv_nsec + (tictoc_start_##tname##_t.tv_sec*1000000000))); tictoc_elapsed_accum_##tname##_t += tictoc_elapsed_##tname##_t;} while (0)

// Return the result after a "stop"
#define tictoc_result(tname) (tictoc_elapsed_##tname##_t); 

// Return the accum after a "stop"
#define tictoc_result_accum(tname) (tictoc_elapsed_##tname##_t); 

// Print the timer
#define tictoc_print(tname) do { printf(#tname": %lu\n", tictoc_elapsed_##tname##_t); } while (0)

// Print the accum
#define tictoc_print_accum(tname) do { printf("Accum "#tname": %lu\n", tictoc_elapsed_accum_##tname##_t); } while (0)
