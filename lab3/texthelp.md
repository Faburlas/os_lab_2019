1)Компилируем первый через 
$ gcc sequential_min_max.c find_min_max.h find_min_max.c utils.h utils.c  -o ex1
2)
$ gcc parallel_min_max.c find_min_max.c find_min_max.h utils.h utils.c -o ex2
./ex2 --seed 10 --array_size 10 --pnum 2
3)
$ gcc parallel_min_max.c find_min_max.c find_min_max.h utils.h utils.c -o ex3
./ex3 --seed 10 --array_size 10 --pnum 2
