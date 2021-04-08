#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>

#include <errno.h>
#include <pthread.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;


int main(int argc, char** argv) {
    int module = -1;
    int pnum = -1;
    int number = -1;

    {
        while (true) {
            static struct option options[] = {
                {"k", required_argument, 0, 0},
                {"pnum", required_argument, 0, 0},
                {"mod", required_argument, 0, 0},
                {0, 0, 0, 0}
            };
            int option_index = 0;
            int c = getopt_long(argc, argv, "?", options, &option_index);
            if (c==-1) break;

            switch (c)
            {
                case 0:
                    switch (option_index)
                    {
                        case 0:
                            number = atoi(optarg);
                            if (number < 0) {
                                printf("k must be positiv number: %d\n", number);
                                return 1;
                            } break;
                        
                        case 1:
                            pnum = atoi(optarg);
                            if (pnum < 0 || pnum > number) {
                                printf("pnum must be positiv number: %d\n", pnum);
                                return 1;
                            } break;

                        case 2:
                            module = atoi(optarg);
                            if (module <= 1) {
                                printf("mod must be positiv number: %d\n", module);
                                return 1;
                            } break;
                        
                        default:
                            printf("Index %d is out of options\n", option_index);
                    } break;
                

                case '?':
                    break;
            
                default:
                    printf("getopt returned character code 0%o?\n", c);
            }
        }

        if (optind < argc) {
            printf("Has at least one no option argument\n");
            return 1;
        }

        if (number == -1 || pnum == -1 || module == -1) {
            printf("Usage: %s --k \"num\" --pnum \"num\" --mod \"num\"\n", argv[0]);
            return 1;
        }   

    }
    
    pthread_t threads[pnum];
    
}
