
namespace v4 {
    public class MyInt {
        private long data;
        public MyInt() {
            data = 0;
        }
        public MyInt(int d) {
            data = d;
        }

        public MyInt(long d) {
            if (d > Int32.MaxValue || d < Int32.MinValue) {
                throw new OverflowException($"Value {d} overflows Int32");
            }
            data = d;
        }

        public override string ToString() {
            return data.ToString();
        }

        public static MyInt operator + (MyInt a, MyInt b) {
            long res = a.data + b.data;
            if (res > Int32.MaxValue || res < Int32.MinValue) {
                throw new OverflowException($"Overflow in operation {a.data} + {b.data}");
            }
            return new MyInt(res);
        }

        public static MyInt operator - (MyInt a, MyInt b) {
            long res = a.data - b.data;
            if (res > Int32.MaxValue || res < Int32.MinValue) {
                throw new OverflowException($"Overflow in operation {a.data} - {b.data}");
            }
            return new MyInt(res);
        }

        public static MyInt operator * (MyInt a, MyInt b) {
            long res = a.data * b.data;
            if (res > Int32.MaxValue || res < Int32.MinValue) {
                throw new OverflowException($"Overflow in operation {a.data} * {b.data}");
            }
            return new MyInt(res);
        }

        public static MyInt operator / (MyInt a, MyInt b) {
            long res = a.data / b.data;
            if (res > Int32.MaxValue || res < Int32.MinValue) {
                throw new OverflowException($"Overflow in operation {a.data} / {b.data}");
            }
            return new MyInt(res);
        }
    }
}
