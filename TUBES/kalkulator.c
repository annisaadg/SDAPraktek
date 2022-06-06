/** Nama File : kalkulator.c
 *  Deskripsi : File Body Kalkulator
 *  Oleh      : -Zacky Faishal Abror
 *				-Annisa Dinda Gantini
 *				-Dhafin Rizqi Fadhilah
 *  Tanggal   : 
 */
#include "kalkulator.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Mengecek apakah stack itu kosong atau tidak 
 * I.S. : Stack kosong belum terdefinisi
 * F.S. : Mengembalikan nilai true ketika stack kosong
 */
boolean IsEmptyStack(stack s){ //
	if(top(s)== NULL){
		return true;
	}else {
		return false;
	}
}

/* Mengecek sebuah data valid atau tidak 
 * I.S. : Data belum terdefinisi falid
 * F.S. : Mengembalikan nilai true ketika data valid
 */
boolean isequal(info token, info operator){ //
	if(strcmp(token,operator) == 0){
		return true;
	}else{
		return false;
	}
}

/* Untuk mengecek apakah inputan berupa operator atau bukan 
 * I.S. : Pengecekan belum dilakukan
 * F.S. : Mengembalikan nilai true ketika terdefinisi operator
 */
boolean isoperator(info element){ //
	if(isequal(element,"+") || 
	isequal(element,"-") || 
	isequal(element,"/") ||
	isequal(element,":") ||
	isequal(element,"*") ||
	isequal(element,"x") ||
	isequal(element,"X") ||
	isequal(element,"(") || 
	isequal(element,")") || isequal(element,"^") || isequal(element,"|")) {
		return true;
	}else{
		return false;
	}
}

/* Membuat sebuath stack kosong
 * I.S. : Stack belum dibuat
 * F.S. : Stack sudah dibuat
 */
void createstack(stack *s){ //
	top(*s) = NULL;
}

/* Membuat sebuath tree kosong
 * I.S. : Tree belum dibuat
 * F.S. : Tree sudah dibuat
 */
void createTree(RootTree *node) { //
	*node = NULL;
}

/* Menyediakan tempat sebuah penyimpanan
 * I.S. : Alokasi telah belum tersedia
 * F.S. : Alokasi sudah tersedia
 */
address alokasi(info x){ //
	tabStack *Stack;
	ElmtNode *tree;
	
	tree = (ElmtNode*)malloc(sizeof(ElmtNode));
	strcpy(tree->MathExpression,x);
	tree->left = NULL;
	tree->right = NULL;
	
	Stack = (tabStack*)malloc(sizeof(tabStack));
	if(Stack != NULL){
		Stack->node = tree;
		Stack->prev = NULL;
		return Stack;
	}else {
		return NULL;
	}
}

/* Memasukan data ke dalam stack
 * I.S. : data belum dimasukan ke dalam stack
 * F.S. : Data sudah dimasukkan ke dalam stack
 */
void push(stack *s,info x){ //
	address p;
	
	p = alokasi(x);
	if (IsEmptyStack(*s)){
		top(*s) = p;
	} else {
		prev(p) = top(*s);
		top(*s) = p;
	}
}

/* Mengeluarkan data dari dalam stack
 * I.S. : data belum dikeluarkan dari dalam stack
 * F.S. : Data sudah dikeluarkan dari dalam stack
 */
void pop(stack *s, address *x){ //
	address pTOP;
	
	pTOP = top(*s);
	*x = pTOP;
	
	if(prev(pTOP) == NULL){
		top(*s) = NULL;
	} else {
		top(*s) = prev(pTOP);
		prev(pTOP) = NULL;
	}
}

/* Mengidentifikasi prioritas dari sebuah operasi
 * I.S. : Operasi belum ada tingkatan prioritas
 * F.S. : Nilai kembalian sesuai dengan definisi
 */
int priority(info opr){
	if( isequal(opr,"+") || isequal(opr,"-")){
		return 1;
	} else if( isequal(opr,"/") || isequal(opr,":") || isequal(opr,"*") ||isequal(opr,"x") ||isequal(opr,"X")){
		return 2;
	} else if( isequal(opr,"^") || isequal(opr,"|")){
		return 3;
	} else{
		return 0;
	}
}

/* Memasukan sebuah data ke dalam tree
 * I.S. : Data belum masuk ke dalam tree
 * F.S. : Data sudah masuk ke dalam tree
 */
void pushTree(stack *s, info x,Tnode left, Tnode right){ //
    address p;
    
    p = alokasi(x);
    p->node->left = right;
    p->node->right = left;
    
    if (IsEmptyStack(*s)) { 
        top(*s) = p;
    } else { 
        prev(p) = top(*s);
        top(*s) = p;
    }
}

/* Mengubah nilai infix menjadi postfix
 * I.S. : Data masih berupa infix
 * F.S. : Data sudah berbentuk postfix
 */
void toPostfix (info text, stack s, info *hasil){
	info temphasil;
	strcpy(temphasil," ");
	int i;
	int j = 0;
	address k;
	info tmpText;
	boolean Digit;
	
	while(text[j] != '\0'){
		Digit=false;
		tmpText[0] = text[j];
		if(text[j-1] == '(' && text[j] == '-'){
			tmpText[1] = text[j-1];
			j++;
		}
		j++;
		
		if(isdigit(text[j])){
			Digit = true;
		}
			if(isoperator(tmpText)){
				if(IsEmptyStack(s) || isequal(tmpText,"(")){
					push(&s,tmpText);
				} else if(isequal(tmpText,")")){
					while(!isequal(s.top->node->MathExpression,"(")){
						pop(&s,&k);
						strcat(temphasil,k->node->MathExpression);
						if(!Digit){
							strcat(temphasil," ");
						}
						
					}
					
					pop(&s,&k);
				}else if((priority(s.top->node->MathExpression) < priority(tmpText))){
					push(&s,tmpText);
				}else if((priority(s.top->node->MathExpression) >= priority(tmpText	))){
					while(s.top != NULL){
						pop(&s,&k);
						strcat(temphasil,k->node->MathExpression);
						strcat(temphasil," ");
						
					}
					push(&s,tmpText);
				}
			}else{
				strcat(temphasil,tmpText);
				if(!Digit){
					strcat(temphasil," ");
				}
			}
			
			tmpText[0] = '\0';
			tmpText[1] = '\0';
		}
		while(s.top	!= NULL){
			pop(&s,&k);
			strcat(temphasil,k->node->MathExpression);
			strcat(temphasil," ");
		}
		strcpy((*hasil),temphasil);
	}

/* Memmbuat sebuah tree untuk melakukan operasi
 * I.S. : Tree operasi belum terdefinisi
 * F.S. : Tree operasi sudah terdefinisi
 */
void buildTree ( stack s, Tnode *node, info text){
	int batastext =strlen(text);
	int i;
	int j = 0;
	Tnode temp;
	address tempT;
	info tmpText;
	boolean Digit;
	int k;
	struct Token Tokenizazer[100];
	
	strcat(text," ");
	char* token =strtok(text," ");
	
	while (token != NULL){
		strcpy(Tokenizazer[j].token,token);
		j++;
		token=strtok(NULL," ");
	}
	for (i=0;i<j;i++){
		strcpy(tmpText,Tokenizazer[i].token);
		if (isoperator(tmpText)){
			ElmtNode *tree;
			tree = (ElmtNode*)malloc(sizeof(ElmtNode));
			//tree ->MathExpression = text[i
			
			pop(&s,&tempT);
			tree->left = tempT->node;
			pop(&s,&tempT);
			tree->right = tempT->node;
			
			pushTree(&s,tmpText,tree->left,tree->right);
		}else{
			push(&s,tmpText);	
		}
		tmpText[0]='\0';
	}
	
	pop(&s,&tempT);
	(*node)= tempT -> node;
}

/* Menghitung hasil dari bentuk tree
 * I.S. : Operasi Matematika belum terhitung
 * F.S. : mengembalikan hasil dari operasi matematika
 */
int calculate(Tnode root){
	if(isequal(root->MathExpression,"+")){
		return calculate(root->left)+calculate(root->right);
	}if(isequal(root->MathExpression,"-")){
		return calculate(root->left)-calculate(root->right);
	}if(isequal(root->MathExpression,"*")|| isequal(root -> MathExpression, "X") || isequal(root -> MathExpression, "x")){
		return calculate(root->left)*calculate(root->right);
	}if(isequal(root->MathExpression,"/")){
		return calculate(root->left)/calculate(root->right);
	}else{
		int val;
		info str;
		strcpy(str,root->MathExpression);
		
		val =atoi(str);
		return val;
	}
}
