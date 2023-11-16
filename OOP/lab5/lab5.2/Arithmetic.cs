class Arithmetic : Progression {
    public Arithmetic(double first, double step) : base(first, step) {}
    override public double Sum(int n) {
        return (2*first + step*(n-1))*n/2;
    }
}