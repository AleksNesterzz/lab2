#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>



using namespace std;

int matrix_counter (int** k,int cols, int rows){
    
	int sum=0;
    
	int* arr = (int*) k;
    
	for (int i=0; i<min(cols,rows);++i)
        
		for (int j=i+1; j<cols;++j){
			sum+=arr[i*cols+j];
        
		}
    
	return sum;
};


int main() {
 
	int cols,rows, diag;
 
	fstream file;
 
	file.open("/uploads/test1.txt", ios::in);
 
	if (!file){
    
		cout<<"File not found"<<endl;
    
		file.close();
    
		return 0;
    
		}
 
	file>>cols;
 
	file>>rows;
 
	int a[rows][cols];
 
	cout<<"Number of columns="<<cols<<" ";
 
	cout<<"Number of rows="<<rows<<endl;
 
	for (int i=0; i<rows;++i)
    
		for (int j=0; j<cols; ++j){
        
			file>>a[i][j];
    }
 
	for (int i=0; i<rows;i++){
    
		for (int j=0; j<cols; j++)
        
			cout<<a[i][j]<<" ";
    
			cout<<endl;
    
	}
    
	cout<<endl;
 
	diag = matrix_counter((int**)a,cols,rows);
 
	cout<<"Sum of numbers upper main diagonale="<<diag<<endl;
 
}
