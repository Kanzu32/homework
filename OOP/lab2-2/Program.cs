namespace lab22 {
    internal class Program {
        private static void Main(string[] args) {
            while (true) {

                Console.WriteLine("Enter operation symbol +, -, * or exit:");
                var operation = Console.ReadLine();
                if (operation == "exit")
                    break;
                Console.WriteLine("Enter first number\nreal part:");
                double r1 = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("imaginary part:");
                double i1 = Convert.ToDouble(Console.ReadLine());
                Complex c1 = new Complex(r1, i1);

                Console.WriteLine("\nEnter second number\nreal part:");
                double r2 = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("imaginary part:");
                double i2 = Convert.ToDouble(Console.ReadLine());
                Complex c2 = new Complex(r2, i2);

                switch (operation) {
                    case "+":
                        Console.WriteLine(Complex.Add(c1, c2));
                        break;
                    case "-":
                        Console.WriteLine(Complex.Sub(c1, c2));
                        break;
                    case "*":
                        Console.WriteLine(Complex.Mul(c1, c2));
                        break;
                    default:
                        Console.WriteLine("Wrong input.");
                        break;
                }
            }
        }
    }
}