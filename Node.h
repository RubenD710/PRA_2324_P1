#include <ostream>

template <typename T>
class Node{
   public:
   T data;
   Node<T>* next;
   Node(T data, Node<T>* next=nullptr){
      this->data=data;
      this->next=next;
   }
   friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
      out << "[";
      Node<T> aux=node;
      while(node.next!=nullptr) {
      out << aux.data << "";
      aux=aux.next;
      }
      out << "]";
      return out;
   }

};
