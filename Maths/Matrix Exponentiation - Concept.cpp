// Linear recurrence
// A linear recurrence is a relation like f(n)=f(n-1)+f(n-2)
// non-linear f(n)=f(n-1)*f(n-2)

// solve in log(n) time
//1st step
//f(n) = f(n-1)+f(n-4) it takes O(n) time if we solve using dP and iteration
//f(n) = 1.f(n-1)+0.f(n-2)+0.f(n-3)+1.f(n-4)
//k=4

//2.step find the matrix of size k X 1 and this will be F1 vector
// F1=[1] // for fibonacci t will f(1)=1,f(2)=1 you can take f(0)=0 also
//    [1]

//3. find a transformation matrix
//   [0 1][1]-->[1] <--f2
//   [1 1][1]   [2] <--f3    this sequences goes till the end                              [0 1][1]-->[1] <--f2
                                                                                      //   [1 1][2]   [2] <--f3    this sequences goes till the end
//     T  F1    F2
                                                                                      //     T  F2    F3

// so basically we can write that the Fn=T*Fn-1
//                                    Fn=T^n-1*F1   time complexity tn=O(K^3*log(n))


// make all the right side element to the diagonal 1
//and in last row add Ck, Ck-1.....C1
//so for f(n) = 1.f(n-1)+0.f(n-2)+0.f(n-3)+1.f(n-4)
//T=[0 1 0 0]
//  [0 0 1 0]
//  [0 0 0 1]
//  [1 0 0 1]


// If there is constant in the equation
// means equation of type f(n) = 1.f(n-1)+0.f(n-2)+0.f(n-3)+1.f(n-4)+3
//then add one extra row and column in the T
//T=[0 1 0 0 0]
//  [0 0 1 0 0]
//  [0 0 0 1 0]
//  [1 0 0 1 0]
//  [0 0 0 0 1] make last element 1


// if there is f(i)=f(i-1)+2*i^2+3*i+5
// then try to make T by yourself
// that by multiplying Fi you will get Fi+1
