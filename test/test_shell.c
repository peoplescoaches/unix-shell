#include "../test-framework/unity.h"
#include <stdbool.h>
#include <unistd.h>
#include "../src/shell.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_initial_shell_prompt(void)
{
   // redirect stdin and stdout streams to corresponding text files
   freopen("build/test_input.txt", "w+", stdin);
   fprintf(stdin, "test\nexit\n");
   // rewind to beginning of input file
   rewind(stdin); 
   freopen("build/test_output.txt", "w+", stdout);

   // call execute_shell function
   execute_shell();

   // flush stdout to make sure all output is written to file
   fflush(stdout);

   char output[50][20];
   // set stream to read from file
   FILE *file = fopen("build/test_output.txt", "r");
   if(file == NULL){
        printf("File not found!");
   } else {
      // get string from the stream to get its contents
      int row = 0;
      while(fgets(output[row], sizeof(output[0]), file) != NULL) {
         ++row;
      }
   }
   // close the files
   fclose(stdin);
   fclose(stdout);

   // set stdout back to the terminal
   stdout = fdopen(dup(fileno(stderr)), "w");

   // verify text in shell command line
   TEST_ASSERT_EQUAL_STRING("hello test\n", output[1]);

   // print output to console for debugging
   fprintf(stderr, "Test output:\n%s\n", output[1]);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_initial_shell_prompt);

   return UNITY_END();
}
