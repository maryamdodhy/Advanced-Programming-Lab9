#include<stdio.h>
#include<stdlib.h>

typedef (*vtable)(struct Mat *m);

			vtable *tabM;
			vtable *tabV;

			typedef struct Matrix {

				int column;
				int row;
				int *array;

					void (*Matrix)( struct Mat *mat, int col, int row);
					void (*add)( struct Mat *mat, struct Mat *mat1, struct Mat *mat2);
					void (*mult)( struct Mat *mat, struct Mat *mat1, struct Mat *mat2);
					vtable *table_m;

			}Mat;

			
			typedef struct Vector{
			Mat matrix;
			int max;  int min;
			void (*vec)( struct vector *mat, int col, int row);
			vtable *table_v;
			}vector;

					int L1_M(Mat *m1){
						int i=0;
						int sum=0;
						int j=0;
						int final=0;

						for(j=0; j<m1->column; j++){
							for(i=0; i<(m1->row); i++){
							sum=sum+m1->array[j*m1->column +i];
							}
							if(sum>final){
							final=sum;
							}
					}

					return final;

					}

					int L1_V(Mat *m1){
						int i=0;
						int sum=0;
						int j=0;
						int final=0;

							for(i=0; i<(m1->row); i++){
							sum=sum+m1->array[i];

							}

						return sum;

					}

					void Multiply(Mat *m1, Mat *m2, Mat *r){

					int i=0; int j=0; int k=0; int l=0;
					int sum=0;

						int m = 0;

					r->array=(int *)malloc( (m1->row*m2->column)* sizeof(int));
					for ( j = 0; j<(m1->row*m1->column); j = j + m1->column){
							i = j;
							 k = 0;
							for (l = 0; l<(m2->row*m2->column);){
								sum = sum + (m1->array[j] * m2->array[l]);
					 			l = l + m2->column;
								i++;
								if ((i) % m1->column == 0){
									r->array[k] = sum;
									i = j;
									if (l != ((m2->row*m2->column)-1) + m2->column){
									k++;
									l = k;
								}
								m++;
								sum=0;
								}
							}
						
					}
					}

					void Add(Mat *m1, Mat *m2 , Mat *r){
						int *arr;
						  int i,j;

						r->array=(int *)malloc( (m1->row*m1->column)* sizeof(int));

							for(i=0; i<(m1->column*m1->row); i++){
								r->array[i] = m1->array[i]+m2->array[i];
							}

					}


					void Add_Vector(vector *m1, vector *m2 , vector *r)
					{
					int *arr;
					  int i,j;
					r->matrix.array=(int *)malloc( (m1->matrix.row*m1->matrix.column)* sizeof(int));

					for(i=0;i<(m1->matrix.column*m1->matrix.row); i++){
						r->matrix.array[i]=m1->matrix.array[i]+m2->matrix.array[i];


					}
					}
					
					void MatrixInit( Mat *mat, int col, int row){
							int **arr;
							mat->add = Add;
							mat->mult = Multiply;
							mat->column = col;
							mat->row = row;
							mat->array = (int*)malloc( sizeof(int)*(row*col));
							
							int i,j;


								for(i=0;i<(col*row); i++){
								mat->array[i] = i+1;
								}

					}


					void VectorInit( vector *mat, int col, int row){
							int **arr;
							mat->matrix.add = Add_Vector;
							mat->matrix.mult = Multiply;
							mat->matrix.column = col;
							mat->matrix.row = row;
							mat->matrix.array = (int *)malloc(sizeof(int)*(row*col));
							
							int i,j;


								for(i=0;i<(col*row); i++){
								mat->matrix.array[i] = i+1;

								}
					}				
					

			int main(){
			
			int row_m = 2; int col_m = 2;

			int row_v = 2; int col_v = 1;
				
			int input;
				
			Mat m1; Mat m2; Mat r; Mat r1;
			vector v1;vector v2;vector v3;
			int i,j;

			printf("Press 1 for Vector. \n  Press 2 for Matrix. \n");
			scanf("%d", &input);

			if(input==1){

			printf("Enter rows of Vector One:\n");
			scanf("%d", &row_v);

			printf("Enter rows of Vector Two:\n");
			scanf("%d", &col_v);

				tabV=(vtable *)malloc( (10)* sizeof(vtable));
				v2.vec=VectorInit;
				v2.vec(&v2, 1, row_v);
				v1.vec=VectorInit;
				v1.vec(&v1, 1, col_v);

					if(row_v==col_v){
					v1.matrix.add(&v1, &v2, &v3);
					printf("Addition of vector:\n");
						for(i=0; i<v2.matrix.row;i++){

						printf("%d  ", v3.matrix.array[i]);

						printf("\n");
						}
					}
			else
			printf("Addition not possible!\n");

			tabV[0]=L1_V;
			v1.table_v=tabV;
			v2.table_v=tabV;
			printf("%d is L1 norm of Vector One. \n",v1.table_v[0](&v1.matrix));
			printf("%d is L1 norm of Vector Two. \n",v2.table_v[0](&v2.matrix));

			}
			

			if(input == 2){


				printf("Enter rows for Matrix One:\n");
				scanf("%d", &row_m);

				printf("Enter columns for Matrix One:\n");
				scanf("%d", &col_m);

				printf("Enter rows for Second Matrix:\n");
				scanf("%d", &row_v);

				printf("Enter columns for Second Matrix:\n");
				scanf("%d", &col_v);

			m1.Matrix=MatrixInit;
			m1.Matrix(&m1, row_m,col_m);
			m2.Matrix=MatrixInit;
			m2.Matrix(&m2, row_v,col_v);

				if (col_m == col_v && row_m==row_v){

					m2.add(&m1, &m2,&r);
					printf("Addition:\n");
					for(i=0; i<m2.row;i++){
						for (j=0; j<m2.column; j++){
						printf("%d  ", r.array[i*m2.column +j]);
						}
					printf("\n");
					}
				}

				else
				printf("Addition not possible!\n");
			
					if(col_m==row_v){
					m2.mult(&m1,&m2, &r1);


					printf("Multiplication:\n");

						for(i=0; i<row_m;i++){
							for (j=0; j<col_v; j++){
							printf("%d  ", r1.array[i*m2.column +j]);
							}
						printf("\n");
						}
					}

					else
					printf("Multiplication not possible!\n");
					tabM=(vtable *)malloc( (10)* sizeof(vtable));
					tabM[0]=L1_M;
					m1.table_m=tabM;
					m2.table_m=tabM;
					printf("%d is L1 norm of Matrix One. \n", m1.table_m[0](&m1));
					printf("%d is L1 norm of Matrix Two. \n", m2.table_m[0](&m2));

			}


			

}
