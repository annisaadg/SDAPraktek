#include "Queue.h"
#include <stdio.h>

void ShowMenu();
int main(){
	Queue Q;
	int X;
	address P;
	int choose;
	
 	CreateQueue(&Q);
 	
 	ShowMenu();
 	
 	do{
 		printf("\nEnter your preference:\n\xaf\xaf ");
 		scanf("%d",&choose);
 		if(choose==1){
 			printf("\nValue: ");
 			scanf("%d",&X);
 			AddQue(&Q,X);
 			printf("Element has been added.");
 			printf("\n\n");
 			ShowMenu();
		 }
		if(choose==2){
			if(IsQueueEmpty(Q)){
				printf("\nDelete failed! Queue is empty.");
			}else{
				DelQue(&Q,&X);
				printf("One element has been deleted.");
			}
			printf("\n\n");
 			ShowMenu();
	 	}
		 if(choose==3){
 			printf("\nValue: ");
 			scanf("%d",&X);
 			if(CariElemenQueue(Q,X)==true){
 				printf("Element exists");
			 }else{
			 	printf("Element doesn't exists");
			 }
 			printf("\n\n");
 			ShowMenu();
		 }
		 if(choose==4){
		 	printf("\n");
 			CetakQueue(Q);
 			printf("\n");
 			ShowMenu();
		 }
	 }while(choose<5);
 	
}

void ShowMenu(){ 
	printf("===== DYNAMIC QUEUE ALLOCATION =====");
	printf("\n1. Add Element to Queue");
	printf("\n2. Delete One Element of Queue");
	printf("\n3. Search Element");
	printf("\n4. Print Queue");
	printf("\n5. Quit");
}
