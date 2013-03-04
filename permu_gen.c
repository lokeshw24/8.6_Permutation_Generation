/*HOW TO RUN :
 * 	$cc <program_name>
 * 	$./a.out
 *
 * WHAT PROG DOES :
 * 	>Prints all the permutation of 'n' values, taken 'r' at a time.
 *
 * LOGIC :
 * 	>First generate a unique combination and every time an unique combination
 * 	is generated, find its all permutation.
 *
 * NOTES :
 * 	>Didn't do error checking on the values of 'n' & 'r', assuming user enters them appropriately.
 *
 */


#include<stdio.h>
#include<stdlib.h>

int n, r;
int *arr;

/**************************************************************/
void rotate_right( int current_arr_pos ){
	int i=arr[current_arr_pos] ;
	int temp=arr[r-1];
	int *t=arr+r-1;

	for( ; (*t)!=i ;  ){
		*t=*(t-1);
		--t;
	}

	*t=temp;

}

/**************************************************************/
void print_array( int *arr ){
	int i;
	printf("[ " );
	for( i=0 ; i<r ; i++ ){
		printf("%d " , arr[i] );

	}
	printf("]\n" );

}

/**************************************************************/
void permu_gen( int current_arr_pos ){

	if( current_arr_pos == (r-1) )
		print_array( arr );
	else{
		int i;
		for( i=0 ; i<(r-current_arr_pos) ; i++ ){
			permu_gen( current_arr_pos + 1 );
			rotate_right( current_arr_pos );
		}

	}

}

/**************************************************************/
void  combination_gen( int current_arr_pos ){
	if( current_arr_pos > (r-1) ) return ;

	if( current_arr_pos == (r-1 ) ){
		/*this is last position in array, so print till 'n' */
		int i;
		for( i=arr[current_arr_pos] ; i<=n ; i++ ){
			permu_gen(0);
			/*for every unique combination that has been generated,
			 * find its permutation.
			 */

			arr[current_arr_pos]++;
			printf("\n");
		}
		printf("**\n");

	}
	else{
		while( arr[current_arr_pos] <= ( n-r+current_arr_pos+1 ) ){
			arr[current_arr_pos+1]=arr[current_arr_pos]+1;
			combination_gen( current_arr_pos+1);
			arr[current_arr_pos]++;
		}
	}

}

/**************************************************************/
int main(){
	n=5;
	r=3;

	arr=(int *)malloc(r*sizeof(int) );
	arr[0]=1;

	combination_gen(0);

	return 0;

}

