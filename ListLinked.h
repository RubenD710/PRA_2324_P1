#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T>{
    
    private:
       Node<T>* first;
       int n;
    public:
       ListLinked(){
          first=nullptr;
          n=0;
       }

       ~ListLinked(){
          while (first != nullptr) {
      	      Node<T>* aux = first->next;
      	      delete first;
              first = aux;
  	  }
       }

       T operator[](int pos){
	  if (pos >= 0 && pos < n){
      	     Node<T>* aux = first;
             for(int i = 0; i < pos; i++){
                aux = aux->next;
             }
             return aux->data;
          }
          throw std::out_of_range("posicion fuera del rango");
       }


       friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
          out << "[";
    	  Node<T>* aux = list.first;
    	  while (aux != nullptr) {  // Cambiado para incluir el último nodo
             out << aux->data<< " ";
             aux = aux->next;
             }
    	     out << "]";
    	     return out;
	}
       
       void insert(int pos, T e) override
       {
       	  if (pos >= 0 && pos <= n) {
       	     if(pos!=0){
       	     	Node<T>* aux=first;
       	     	for(int i=0;i<pos-1;i++){
                   aux=aux->next; 
             	}
             	aux->next= new Node<T>(e,aux->next);
             }else{
                 first= new Node<T>(e,first);
             }
             n++;
          } else {
             throw std::out_of_range("Posición fuera del rango");
          }
	}

	void append(T e) override
	{
	   insert(n,e);
	}

	void prepend(T e) override
	{
	   insert(0,e);
	}

	T remove(int pos) override
	{
	   if (pos >= 0 && pos <n) {
	     Node<T>* aux=first;
	     T retorno;
       	     if(pos!=0){
                for(int i=0;i<pos-1;i++){
                   aux=aux->next; 
                }
                Node<T>* eliminar=aux->next;
                retorno=eliminar->data;
                aux->next=eliminar->next;
                delete eliminar;
             
           }else{
                 first=aux->next;
                 retorno=aux->data;
                 delete aux;
           }
             n--;
             return retorno;
          }else {
             throw std::out_of_range("Posición fuera del rango");
          }
	}

	T get(int pos) override
	{
	   if (pos >= 0 && pos < n){
              Node<T>* aux=first;
       	      for(int i=0;i<n;i++){
                	if(i==pos){
                   	   return aux->data;
                	}else{
                    	   aux=aux->next; 
                 	}  
             }
           }
             throw std::out_of_range("posicion fuera del rango");

	}

	int search(T e) override
	{
           Node<T>* aux=first;
       	   for(int i=0;i<n;i++){
              if(aux->data==e){
                 return i;
              }else{
                 aux=aux->next; 
              }  
           }
           return -1;
        }

	bool empty() override
	{
	   return n==0;
	}

	int size() override
	{
	   return n;
	}
};

