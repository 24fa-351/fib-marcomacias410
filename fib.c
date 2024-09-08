#include <stdio.h>
#include <stdlib.h>

int fib_iterative(int nth_term)
{

   int first_num = 0;
   int second_num = 1;
   int sum_of_num = 0;

   // starting counter at 2 because we know the first 2 terms of the sequence
   for (int ix = 2; ix < nth_term; ++ix)
   {
      sum_of_num = first_num + second_num;
      first_num = second_num;
      second_num = sum_of_num;
   }

   return sum_of_num;
}

int fib_recursive(int nth_term)
{

   if (nth_term <= 1)
      return nth_term;
   return fib_recursive(nth_term - 1) + fib_recursive(nth_term - 2);
}

int main(int argc, char *argv[]) 
{

   int fibo_sum;
   int txt_file_num;
   int given_num = atoi(argv[1]);
   char letter = argv[2][0];

   if (argc != 4) {
      printf("File: %s <int> <r|i> <filename>\n", argv[0]);
      return 1;
   }


   if (letter != 'r' && letter != 'i') {
      printf("Error. Please enter the letter r (recursive) or i (iterative)");
      return 1;
   }

   FILE * f = fopen(argv[3], "r");

   fscanf(f, "%d", &txt_file_num);

   txt_file_num += given_num;

   if (letter == 'r') {

      fibo_sum = fib_recursive(txt_file_num - 1);
   }
   else if (letter == 'i') {

      fibo_sum = fib_iterative(txt_file_num);
   }

   printf("%d", fibo_sum);

   return 0;
}
