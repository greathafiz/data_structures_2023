// Function to initialize a singly linked list node
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

const initializeList = () => {
  let head = null;
  let tail = null;

  return { head, tail };
};

// let linkedList = initializeList();
// console.log(linkedList);

// Function to insert a node
// at the end of a singly linked list

const insertNode = (head, tail, data) => {
  let newComponent = new Node(data);

  if (!head) {
    head = newComponent;
    tail = newComponent;
  } else {
    tail.next = newComponent;
    tail = newComponent;
  }

  return { head, tail };
};


//Inserting nodes:

let list = initializeList();
list = insertNode(list.head, list.tail, 5);
console.log(list);
