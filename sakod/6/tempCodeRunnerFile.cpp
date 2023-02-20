template <typename Type>
// class HeaderList {
// public:
//     HeaderNode<Type>* header;
    

//     HeaderList() {
//         header = new HeaderNode();
//     };

//     void push(Type data) {
//         Node<Type>* node = new Node<Type>(data);
//         if (count == 0) {
//             top = node;
//             count = 1;
//         } else {
//             node->next = top;
//             top = node;
//             count++;
//         }
        
//     }

//     Type pop() {
//         if (count == 0) {
//             throw std::length_error("Stack is empty!!!");
//         }
//         Node<Type>* node = top;
//         Type data = node->data;
//         top = top->next;
//         delete node;
//         count--;
//         return data;
        
//     }

//     void print() {
//         Node<Type>* node = top;
//         while (node->next != nullptr) {
//             cout << node->data << " ";
//             node = node->next;
//         }
//         cout << node->data << "\n";
//     }
// };