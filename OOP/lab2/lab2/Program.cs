using System;
using System.Collections.Generic;
using System.Text;

namespace lab2 {
    internal class Program {
        private static void Main(string[] args) {
            Product[] productArray = new Product[3];
            productArray[0] = new Product();
            Console.WriteLine(Product.GetText());
            productArray[1] = new Product("Стол", "ст1", 10);
            Console.WriteLine(Product.GetText());
            productArray[2] = new Product(new Product("Ноутбук", "нб12", 3));
            Console.WriteLine(Product.GetText());
            Console.ReadLine();
        }
    }
}
