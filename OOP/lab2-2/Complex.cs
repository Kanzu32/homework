using System;
using System.Collections.Generic;
using System.Text;

namespace lab22 {
    class Complex {
        private double real;
        private double imaginary;

        public Complex() {
            real = 0;
            imaginary = 0;
        }

        public Complex(double real, double imaginary) {
            this.real = real;
            this.imaginary = imaginary;
        }

        public override string ToString() {
            if (imaginary < 0)
                return $"{real}{imaginary}i";
            return $"{real}+{imaginary}i";
        }

        public static Complex Add(Complex num1, Complex num2) {
            return new Complex(num1.real + num2.real, num1.imaginary + num2.imaginary);
        }

        public static Complex Sub(Complex num1, Complex num2) {
            return new Complex(num1.real - num2.real, num1.imaginary - num2.imaginary);
        }

        public static Complex Mul(Complex num1, Complex num2) {
            return new Complex(num1.real*num2.real - num1.imaginary*num2.imaginary, num1.real*num2.imaginary + num2.real*num1.imaginary);
        }
    }
}