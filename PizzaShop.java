class Pizza{
   protected String desc = "";
   public Pizza(){
      this.desc = "";
   }
   protected String getDescription(){
      return "Pizza"+desc;
   }
   protected int getCost(){
      return 9;
   }
}

class addSausage extends Pizza{
   Pizza pizza;
   addSausage(Pizza pizza){
      this.pizza = pizza;
      this.pizza.desc = " with";
   }
   protected String getDescription(){
      return this.pizza.getDescription() + " sausage";
   }
   protected int getCost(){
      return this.pizza.getCost() + 1;
   }
}

class addSauce extends Pizza{
   Pizza pizza;
   addSauce(Pizza pizza){
      this.pizza = pizza;
      this.pizza.desc = " with";
   }
   protected String getDescription(){
      return this.pizza.getDescription()+" sauce";
   }
   protected int getCost(){
      return this.pizza.getCost() + 3;
   }
}

class addCheese extends Pizza{
   Pizza pizza;
   addCheese(Pizza pizza){
      this.pizza = pizza;
      this.pizza.desc = " with";
   }
   protected String getDescription(){
      return this.pizza.getDescription()+" cheese";
   }
   protected int getCost(){
      return this.pizza.getCost() + 1;
   }
}


class PizzaShop{
    public static void main(String args[]){
       Pizza myPizza = new Pizza();
       System.out.println(myPizza.getDescription());
       System.out.println(myPizza.getCost());
       for(int i = 0; i < 4; i++){
          myPizza = new addSausage(myPizza);
          System.out.println(myPizza.getDescription());
          System.out.println(myPizza.getCost());
          myPizza = new addSauce(myPizza);
          System.out.println(myPizza.getDescription());
          System.out.println(myPizza.getCost());
          myPizza = new addCheese(myPizza);
          System.out.println(myPizza.getDescription());
          System.out.println(myPizza.getCost());
       }
   }
}
