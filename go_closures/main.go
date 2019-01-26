package main

import ("fmt")

func main() {
   closures()
   defers()
   return
}

func defers() (a int) {
   fmt.Println("####################[BEGIN]defer test####################")
   defer fmt.Println("####################[END]defer test##################")

   defer func () { fmt.Println("curry the action to delay evaluation", a) }()
   defer fmt.Println("arguments are evaluated at defer invocation", a)

   a = 100
   {
      //a := 30 // variable shadowing is cool
      defer func () {
         a *= 3
      }()
      defer func () {
         a += 3
      }()
      // defers are placed in a stack and executed as they are popped off of the stack
   }
   return
}

func funcShadow() int {
   funcShadow := func (i int) int {
      return i

   }
   return funcShadow(100)
}

func closures() {
   fmt.Println("####################[BEGIN]closure test####################")
   defer fmt.Println("####################[END]closure test##################")

   ch := make(chan int)
   num := 100

   for i := 0; i < num; i++ {
      go func (/*_*/i int) {  // not actually an emoticon, just 
                              // commented out a way to shadow a copied variable
         ch<-i
      }(i)
   }
   for i := 0; i < num; i++ {
      a := <-ch
      fmt.Println(a)
   }
}
