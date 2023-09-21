using System;
using System.Collections.Generic;
using System.Text;

namespace lab2 {
    class Product {
        private string name = "";
        private string code = "";
        private int count;
        private static string text = "";

        public Product() {
            text = "Конструктор без параметров вызван для объекта <" + this.ToString() + ">\n";
        }

        public Product(string name, string code, int count) {
            this.name = name;
            this.code = code;
            this.count = count;
            text = "Конструктор с параметрами вызван для объекта <" + this.ToString() + ">\n";
        }

        public Product(Product product) {
            this.name = product.name;
            this.code = product.code;
            this.count = product.count;
            text = "Конструктор копироваия вызван для объекта <" + this.ToString() + ">\n";
        }

        public static string GetText() {
            string res = text;
            text = "";
            return res;
        }

        public int Count {
            get { return count; }
            set { count = value; }
        }

        public string Name {
            get { return name; }
        }

        public string Code {
            get { return code; }
        }

        public override string ToString()
        {
            string st = "name\"" + this.name + "\"   code=\"" + this.code + "\"   count=" + count.ToString();
            return st;
        }
    }
}