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
   fprintf(stdin, "test\n");
   // rewind to beginning of input file
   rewind(stdin); 
   freopen("build/test_output.txt", "w+", stdout);

   // call execute_shell function
   execute_shell();

   // flush stdout to make sure all output is written to file
   fflush(stdout);

   // set stream to read from file
   FILE *file = fopen("build/test_output.txt", "r");
   
   // get string from the stream to get its contents
   char output[50];
   fgets(output, sizeof(output), file);
   
   // close the files
   fclose(stdin);
   fclose(stdout);

   // set stdout back to the terminal
   stdout = fdopen(dup(fileno(stderr)), "w");

   // verify text in shell command line
   TEST_ASSERT_EQUAL_STRING("pcshell> test\n", output);

   // print output to console for debugging
   fprintf(stderr, "Test output:\n%s\n", output);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_initial_shell_prompt);

   return UNITY_END();
}
