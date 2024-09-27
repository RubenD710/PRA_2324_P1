#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {
	
	    private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2;
		void resize(int new_size){
		   T* arr1= new T[new_size];
		   for (int i=0;i<n;i++){
		      arr1[i]=arr[i];
		   }
		   delete[] arr;
		   arr=arr1;
		   max=new_size;
		}

	     public:
                ListArray(){
		   arr= new T[MINSIZE];
		   max=MINSIZE;
		   n=0;
		}
  		
		
		~ListArray(){
		   delete[] arr;
		}

		T operator[](int pos){
		   if (pos >= 0 && pos < n){
		       return arr[pos];
		   }
		   throw std::out_of_range("posicion fuera del rango");
		}

		friend std::ostream&operator<<(std::ostream &out, const ListArray<T> &list){
		   out << "[";
        	   for (int i = 0; i < list.n; ++i) {
            	      out << list.arr[i] << "";
            	   }
        	   out << "]";
                   return out;
		}

		void insert(int pos, T e) override
		{
		   if (pos >= 0 && pos <= n) {
                      if (n == max) {
                         resize(max * 2);
                      }
                   for (int i = n; i > pos; --i) {
                      arr[i] = arr[i - 1];  // Mover elementos a la derecha
                   }
                   arr[pos] = e;
                   n++;
                   } else {
                      throw std::out_of_range("Posición fuera del rango");
                   }
		}

		void append(T e) override
		{
		   if (n==max){
		       resize(max*2);
		   }
		   insert(n,e);
		   n++;
		}

		void prepend(T e) override
		{
		   if(n==max){
		      resize(max*2);
		   }
		   for (int i=n;i>=0;i--){
                      arr[i+1]=arr[i];
                   }
		   insert(0,e);
		   n++;
		}

		T remove(int pos) override
		{
		   if (pos >= 0 && pos < n){
                       T aux=arr[pos];
		       // el numero eliminado echarlo al final de la array para hacer una nueva sin ese numero
		       for (int i = pos; i < n - 1; ++i) {
                    	   arr[i] = arr[i + 1];  // Mover elementos a la izquierda
                	}
		       n--;
		       return aux;
                   }
                   throw std::out_of_range("posicion fuera del rango");
		}

		T get(int pos) override
		{
		   if (pos >= 0 && pos < n){
                       return arr[pos];
                   }
                   throw std::out_of_range("posicion fuera del rango");

		}

		int search(T e) override
		{
		   for (int i=0;i<n;i++){
		       if(e==arr[i]){
		 	 return i;
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
