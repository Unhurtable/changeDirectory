/*
 * Name:
 *    changeDir - A simple program for changing the current working directory
 *
 * Syntax:
 *  changeDir [argv]
 *
 * Description:
 *    changeDir is a simple program that changes the current working directory of the thread that calls it
 *    without changing any environment variables.
 *
 * Options:
 *    None
 *
 * Examples:
 *  changeDir Documents
 *  changeDir ..
 *  changeDir .
 *
 *SEE ALSO:
 *  Function calls: chdir(1) 
 *   
 *
 *NOTES:
 *  Compile with gcc changeDir.c -o changeDir provided gcc exists on
 *  your system. 
 *
 *	This version is suited for KTH's shell.it.kth.se servers. 
 *
 *AUTHOR:
 *  Anton Täcklind (antontac@kth.se)
 */

#include <stdlib.h>
#include <unistd.h>

/*
 * changeDirectory
 *
 * changeDirectory simply attempts to call the chdir function (provided by unistd.h).
 * If this call fails, an error is printed and the program exits.
 * If this call succeeds, nothing extra is done.
 * Parameters:
 *    char *argv - A pointer to a char array indicating which directory the user wishes to jump to.
 * Returns:
 *    void
 */
void changeDirectory(char *argv){
  if(chdir(argv) == -1){
    perror("Error : Couldn't change directory");
    exit(1);
  }
}

int main(int args, char *argv[]){
  /*
   * Runs changeDirectory if there is an argument, otherwise it does nothing
   */
  if(args > 0){
    changeDirectory(argv[0]);
  }
  return 0;
}
