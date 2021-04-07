
/*
  CEOI 2006
  Competition Day #2
  Task MEANDIAN
  Sample library for C/C++
*/

/*
  input file format:
  N
  a1 a2 ... aN
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define LOG
#define QUERY_LIMIT 1000


/* internal variables */
static FILE *flog;
static int  N;
static int  *array;
static int  queries;
static int  cant[4];


/* cleanup() - close files, etc. */
static void cleanup()
{
   if ( flog != NULL )
      fclose( flog );
   if ( array != NULL )
      free( array );
}


/* die() - something went wrong, 0 points */
static void die( const char *format, ... )
{
   va_list arg;

#ifdef LOG
   va_start( arg, format );
   vfprintf( flog, format, arg );
   va_end( arg );
   fprintf( flog, "\n" );
#endif

   printf( "Error: " );
   va_start( arg, format );
   vprintf( format, arg );
   va_end( arg );
   printf( "\n" );

   exit(0);
}


/* ok() - full points */
static void ok()
{
#ifdef LOG
   fprintf( flog, "OK! (%d queries)\n", queries );
#endif

   printf( "OK!\n");
   exit(0);
}

/* intcmp() - qsort comparison function */
static int intcmp( const void *a, const void *b )
{
   if ( *(const int *)a < *(const int *)b ) return -1;
   if ( *(const int *)a > *(const int *)b ) return 1;
   return 0;
}


int Init()
{
   static int initialized = 0;

   if ( initialized )
      die( "Init() called more than once!" );

   flog = NULL;
   N = 0;
   array = NULL;
   queries = 0;

#ifdef LOG
   flog = fopen( "meandian.log", "wt" );
   fprintf( flog, "Init() => " );
#endif

   if ( scanf( "%d", &N ) != 1 ) {
      die( "error reading N" );
   }
   if ( N < 4 || N > 100 ) {
      die( "N must be between %d and %d", 4, 100 );
   }

   if ( ( array = (int*)malloc(N*sizeof(int)) ) == NULL ) {
      die( "internal error: malloc failed" );
   }

   {
      int i;
      for ( i=0; i<N; ++i ) {
         if ( scanf( "%d", &array[i] ) != 1 )
            die( "error reading input" );
         if ( array[i] % 2 != 0 )
            die( "number %d (at position %d) should be even", array[i], i+1 );
         if ( array[i] <= 0 || array[i] > 100000 )
            die( "number %d (at position %d) should be a positive integer <= %d", array[i], i+1, 100000 );
      }

      int *tmp;
      if ( ( tmp = (int*)malloc(N*sizeof(int)) ) == NULL ) {
         die( "internal error: malloc failed" );
      }

      memcpy( tmp, array, N*sizeof(int) );
      qsort( tmp, N, sizeof *tmp, intcmp );

      for ( i=1; i<N; ++i )
         if ( tmp[i-1] == tmp[i] )
            die( "duplicates found (number %d)", tmp[i] );

      cant[0] = tmp[0];   cant[1] = tmp[1];
      cant[2] = tmp[N-2]; cant[3] = tmp[N-1];
      free(tmp);
   }

#ifdef LOG
   fprintf( flog, "OK (N=%d)\n", N );
#endif

   atexit(cleanup);

   initialized = 1;

   return N;
}


static void compare_swap_ints(int *a, int *b)
{
   if ( array[*a-1] > array[*b-1] ) {
      int t = *a;
      *a = *b;
      *b = t;
   }
}

int Meandian(int a, int b, int c, int d)
{
#ifdef LOG
   fprintf( flog, "Meandian(%d, %d, %d, %d) => ", a, b, c, d );
#endif

   ++queries;
   if ( queries > QUERY_LIMIT )
      die( "too many queries" );

   if ( a < 1 || a > N || b < 1 || b > N ||
        c < 1 || c > N || d < 1 || d > N )
      die( "arguments must be between 1 and N" );

   compare_swap_ints( &a, &b );
   compare_swap_ints( &a, &c );
   compare_swap_ints( &a, &d );
   compare_swap_ints( &b, &c );
   compare_swap_ints( &b, &d );
   compare_swap_ints( &c, &d );

   if ( a == b || b == c || c == d )
      die( "all 4 arguments must be distinct" );

   int ret = (array[b-1]+array[c-1])/2;

#ifdef LOG
   fprintf( flog, "%d\n", ret );
#endif

   return ret;
}


void Solution(const int *sol)
{
#ifdef LOG
   fprintf( flog, "Solution() => " );
#endif
   {
      int i;
      for ( i=0; i<N; ++i ) {
         int expected =
            array[i] == cant[0] || array[i] == cant[1] ||
            array[i] == cant[2] || array[i] == cant[3] ? -1 : array[i];
         if ( sol[i] != expected )
            die( "number %d is wrong (%d, should be %d)", i+1, sol[i], expected );
      }
   }

   ok();
}
