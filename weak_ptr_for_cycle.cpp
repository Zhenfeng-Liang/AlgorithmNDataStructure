/*
Let me repeat your question: "My question, how cyclic data structures makes reference count above zero, kindly request to show with example in C++ program. How the problem is solved by weak_ptrs again with example please."

The problem occurs with C++ code like this (conceptually):
*/

class A { shared_ptr<B> b; ... };
class B { shared_ptr<A> a; ... };
shared_ptr<A> x(new A);  // +1
x->b = new B;            // +1
x->b->a = x;             // +1
// Ref count of 'x' is 2.
// Ref count of 'x->b' is 1.
// When 'x' leaves the scope, there will be a memory leak:
// 2 is decremented to 1, and so both ref counts will be 1.
// (Memory is deallocated only when ref count drops to 0)

/*
To answer the second part of your question: It is mathematically impossible for reference counting to deal with cycles. Therefore, a weak_ptr (which is basically just a stripped down version of shared_ptr) cannot be used to solve the cycle problem - the programmer is solving the cycle problem.

To solve it, the programmer needs to be aware of the ownership relationship among the objects, or needs to invent an ownership relationship if no such ownership exists naturally.
*/


// The above C++ code can be changed so that A owns B:

class A { shared_ptr<B> b; ... };
class B { weak_ptr<A>   a; ... };
shared_ptr<A> x(new A); // +1
x->b = new B;           // +1
x->b->a = x;            // No +1 here
// Ref count of 'x' is 1.
// Ref count of 'x->b' is 1.
// When 'x' leaves the scope, its ref count will drop to 0.
// While destroying it, ref count of 'x->b' will drop to 0.
// So both A and B will be deallocated.

/*
A crucial question is: Can weak_ptr be used in case the programmer cannot tell the ownership relationship and cannot establish any static ownership because of lack of privilege or lack of information?

The answer is: If ownership among objects is unclear, weak_ptr cannot help. If there is a cycle, the programmer has to find it and break it. An alternative remedy is to use a programming language with full garbage collection (such as: Java, C#, Go, Haskell), or to use a conservative (=imperfect) garbage collector which works with C/C++ (such as: Boehm GC).
*/
