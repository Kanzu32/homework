using System.ComponentModel;

internal class Program {
    private static void Main(string[] args) {
        Console.WriteLine("Enter mode.\nCF - Celsius to Fahrenheit\nFC - Fahrenheit to Celsius.");
        var ans = Console.ReadLine();
        Console.WriteLine("Enter temperature: ");
        double input = Convert.ToDouble(Console.ReadLine());
        if (ans == "CF" || ans == "cf") {
            Console.WriteLine(TemperatureConverter.ToFahrenheit(input));
        } else if (ans == "FC" || ans == "fc") {
            Console.WriteLine(TemperatureConverter.ToCelsius(input));
        } else {
            Console.WriteLine("Wrong input.");
        }
    }
}

public class TemperatureConverter {
    public static double ToFahrenheit(double C) {
        return Math.Round(C * (9 / 5f) + 32, 2);
    }
    public static double ToCelsius(double F) {
        return Math.Round((F - 32) / (9/5f), 2);
    }
}