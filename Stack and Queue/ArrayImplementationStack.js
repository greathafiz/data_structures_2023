// const MAX = 1

// class Stack {
//     constructor() {
//       this.items = [];
//     }
  
//     push(element) {
//       this.items.push(element);
//     }
  
//     pop() {
//       if (this.items.length === 0) {
//         return "Underflow";
//       }
//       return this.items.pop();
//     }
  
//     peek() {
//       return this.items[this.items.length - 1];
//     }
  
//     isEmpty() {
//       return this.items.length === 0;
//     }
//   }
  
//   const stack1 = new Stack

//   stack1.push('X')
//   stack1.push('Y')
//   stack1.push('Z')

  // const poppedItem = stack1.pop()

  // console.log(`${poppedItem} was popped from stack`)

  // const currItems = stack1.peek()

  // console.log(stack1.isEmpty())

  // console.log(`Elements present in stack: ${currItems}`)

  // while (!stack1.isEmpty()) {
    
  // }




  // class Stack2 {
  //   constructor(MAX) {
  //     this.items = []
  //     this.MAX = MAX 
  //   }

  //   peek() {
  //     return this.items.length - 1
  //   }

  //   isEmpty() {
  //     let top = this.items.length - 1
  //     return top === -1
  //   }

  //   pop() {
  //     let top = this.items.length - 1
  //     if (top < 0) {
  //       return "Underflow. Stack is empty"
  //     } 
  //       return this.items.pop()
  //   }

  //   push(item) {
  //     // let top = this.items.length - 1
  //     if (this.items.length === MAX) {
  //       const error = console.log("Overflow. Stack is full")
  //       return error
  //     } else {
  //       this.items.push(item)
  //       return `${item} pushed successfully`
  //     }
  //   }
  // }

  // const stack2 = new Stack(MAX)

  // stack2.push('X')
  // stack2.push('Y')
  // stack2.push('Z')

  // console.log(stack2)
  // // console.log(`${stack2.pop()} was popped from the stack`)
  // // console.log(stack2)
  // stack2.peek()
  // console.log(stack2.isEmpty())
  
  



  class Stack {
    constructor(maxSize) {
      this.items = [];
      this.maxSize = maxSize;
    }
  
    push(element) {
      if (this.items.length === this.maxSize) {
        const errorInfo = console.log('Overflow')
        return errorInfo;
      } else {
        this.items.push(element);
        return "Element pushed successfully";
      }
    }
  
    pop() {
      if (this.items.length === 0)
      {
        const info = console.log("Underflow")
        return info

      } else {
        return this.items.pop()
      }
    }
  
    peek() {
      return this.items[this.items.length - 1];
    }
  
    isEmpty() {
      return this.items.length === 0;
    }
  }

  const stack = new Stack(1)

  stack.push('X')
  stack.pop()
  stack.pop()

  console.log(stack)