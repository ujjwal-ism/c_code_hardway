#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
		
using namespace std;
		
// Storing dimensions of Box.
struct 	Box{
	int height;
	int width;
	int depth;
};	

bool box_comparator(Box a,Box b){
	int A1 = a.width*a.depth;
	int A2 = b.width*b.depth;
	return A1>A2; 
}	
		
// Solving Box stacking problem i.e maximum length of stack of boxes.
int max_stack_len(Box box[],int n){
	Box boxes[3*n];
	for(int i=0;i<n;i++){
		int k = 3*i;
		boxes[k].height = box[i].height;
		boxes[k].width = box[i].width;
		boxes[k].depth = box[i].depth;
		
		boxes[k+1].height = box[i].width;
		boxes[k+1].width = box[i].height;
		boxes[k+1].depth = box[i].depth;

		boxes[k+2].height = box[i].depth;
		boxes[k+2].width = box[i].height;
		boxes[k+2].depth = box[i].width;
	}
	
	sort(boxes,boxes+3*n,box_comparator);  // Sorting in decending order.
	/*for(Box b:boxes){
		cout<<b.width<<" "<<b.depth<<" "<<b.height<<endl;
	}*/

	int MSH[3*n+1];
	MSH[0]=0;
	for(int i=1;i<=3*n;i++){
		int q=0;
		for(int j=0;j<i;j++){
			if(boxes[j].width>boxes[i-1].width && boxes[j].depth>boxes[i-1].depth)// Checking it fits or not
				q = max(q,MSH[j+1]);																																																																																																																														
		}
		MSH[i]=q+boxes[i-1].height;
	}                              
	int max=-1;
	for(int i=0;i<=3*n;i++){
		cout<<MSH[i]<<endl;
		if(max<MSH[i])
			max = MSH[i];
	}                    
	return max;                                                                                                                                                                                                                                                                                                                                                                     	
}	
	
int main(int argc, char const *argv[])
{	
	Box box[4];
	box[0].height=4;
	box[0].width=7;
	box[0].depth=9;

	box[1].height=5;
	box[1].width=8;
	box[1].depth=9;

	box[2].height=11;
	box[2].width=20;
	box[2].depth=40;

	box[3].height=1;
	box[3].width=2;
	box[3].depth=3;

	cout<<max_stack_len(box,4)<<endl;
	return 0;
}