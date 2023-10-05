
namespace v4 {
    class Program {
        public static MyInt? a;
        public static MyInt? b;
        static void Main(string[] args) {
            while (true) {

                Console.Write("Enter operation (+, -, *, /, exit): ");
                string? operation = Console.ReadLine();

                if (operation == "exit")
                    break;

                Console.Write("Enter A number: ");
                string? aStr = Console.ReadLine();
                Console.Write("Enter B number: ");
                string? bStr = Console.ReadLine();
            
                a = new MyInt(long.Parse(aStr ?? "0"));
                b = new MyInt(long.Parse(bStr ?? "0"));
                
                switch (operation) {
                    case "+":
                        Console.WriteLine(a + b);
                        break;
                    case "-":
                        Console.WriteLine(a - b);
                        break;
                    case "*":
                        Console.WriteLine(a * b);
                        break;
                    case "/":
                        Console.WriteLine(a / b);
                        break;
                    default:
                        Console.WriteLine("Wrong input.");
                        break;

                }
            }
        }
    }
}
