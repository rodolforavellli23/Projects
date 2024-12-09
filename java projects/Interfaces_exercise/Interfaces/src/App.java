
public class App implements InterfaceTest {

    public class Rabbit implements Prey {

        @Override
        public void flee() {
            System.out.println("*The rabbit is running away*");
        }
    }

    public class Hawk implements Predator {

        @Override
        public void hunt() {
            System.out.println("*The hawk is hunting*");
        }
    }

    public class Fish implements Prey, Predator {

        @Override
        public void flee() {
            System.out.println("*The fish is swimming away*");
        }

        @Override
        public void hunt() {
            System.out.println("*The fish is hunting*");
        }
    }

    public static void main(String[] args) throws Exception {
        App appInstance = new App();
        Rabbit rabbit = appInstance.new Rabbit();
        Hawk hawk = appInstance.new Hawk();
        Fish fish = appInstance.new Fish();

        rabbit.flee();
        hawk.hunt();
        fish.flee();
        fish.hunt();
    }
}
