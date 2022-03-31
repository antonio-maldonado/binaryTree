/* Antonio Maldonado Pinzon
	Estructura de datos, Tarea 12
	Programa que elimina un nodo de un arbol */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include "libs/Node.h"
using namespace std;

// define estrutura básica de datos
typedef Node TreeNode;
typedef Node* TreeNodePtr;

typedef struct{
  TreeNodePtr root;
}BinaryTree;

TreeNodePtr deleteNode(TreeNodePtr);
TreeNodePtr buildTree( FILE* );
void visit( TreeNodePtr );
void preOrder( TreeNodePtr );
void inOrder( TreeNodePtr );
void postOrder( TreeNodePtr );
void deleteTree(TreeNodePtr node);

// *************************************************************
//    Funcion principal
// *************************************************************
int main(int argc, char **argv){
  // lee archivo, crea arbol binario, cierra archivo
  FILE * in = fopen("a.in","r");
  BinaryTree bt;
  bt.root = buildTree(in);
  fclose (in);

  // despliega informacion
  cout<<endl<<"The pre-order traversal is  : ";preOrder( bt.root );cout<<endl;
  cout<<endl<<"The in-order traversal is   : ";inOrder( bt.root );cout<<endl;
  cout<<endl<<"The post-order traversal is : ";postOrder( bt.root );cout<<endl;

  //Proceso de eliminacion del nodo L
	TreeNodePtr a=CrearNode(); //Creo un nuevo nodo el cual almacenará el nodo nuevo a poner en el arbol
	a=deleteNode(bt.root->right); //Me retorna el nuevo nodo a sustituir en lugar de L
	cout<<"Nodo a agregar en lugar de L:  ";
	cout<<a->data.word<<endl; //Muestro el nuevo nodo que reemplazara al nodo L
	bt.root->right=a; //Sustituyo en el arbol el nodo L por el nuevo nodo (N)
 	cout<<"\nNodo L eliminado del arbol\nNuevo arbol:";
	//Imprimo el arbol despues de haber eliminado al nodo L	
	cout<<endl<<"The pre-order traversal is  : ";preOrder( bt.root );    cout << endl;
  cout<<endl<<"The in-order traversal is   : ";inOrder( bt.root );    cout << endl;
  cout<<endl<<"The post-order traversal is : ";postOrder( bt.root );    cout << endl;
  //Elimino el arbol
  cout<<endl<<"Eliminando arbol..."<<endl;
	deleteTree(bt.root);
	cout<<"Arbol eliminado"<<endl;
	//termina programa
  return EXIT_SUCCESS;
}  // end main
// *************************************************************
//    Funciones del programa
// *************************************************************
TreeNodePtr buildTree(FILE* in){
  // lee siguiente string
  char str[100];
  fscanf(in,"%s",str);
  if (strcmp(str,"@")==0)    // si es una hoja, regresa NULL
    return NULL;
  // si es nodo interior, sigue la recursion
  TreeNodePtr p=CrearNode();
  strcpy(p->data.word,str);
  p->left=buildTree(in);
  p->right=buildTree(in);
  return p;
}      //end buildTree

void visit(TreeNodePtr node)
{cout<<node->data.word << " ";}

void preOrder(TreeNodePtr node){
  if(node!=NULL){
		visit(node);
    preOrder(node->left);
    preOrder(node->right);
  }
}      //end preOrder

void inOrder(TreeNodePtr node){
  if(node!=NULL){
		inOrder( node->left );
    visit( node );
    inOrder( node->right );
  }
}      //end inOrder

void postOrder(TreeNodePtr node){
	if(node!=NULL){
    postOrder(node->left);
    postOrder(node->right);
   	visit(node);
  }
}      //end postOrder

void deleteTree(TreeNodePtr node){
	if(node!=NULL){
    deleteTree( node->left );
    deleteTree( node->right );
    delete node;
  }
}

TreeNodePtr deleteNode(TreeNodePtr T) {
	TreeNodePtr R=CrearNode();
	TreeNodePtr P=CrearNode();
	if (T==NULL) return NULL;
	if (T->right==NULL) return T->left; //cases 1 and 2b
	R=T->right;

	if(T->left==NULL) return R; //case 2a

	if(R->left==NULL){
		R->left = T->left;
		return R;
	}
	while (R->left != NULL) { //will be executed at least once
		P = R;
		R = R->left;
	}
//R is pointing to the in-order successor of T;
//P is its parent
	R->left= T->left;
	P->left = R->right;
	R->right = T->right;
return R;
} //end deleteNode
