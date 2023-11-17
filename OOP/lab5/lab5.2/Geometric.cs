class Geometric : Progression {
    public Geometric(double first, double step) : base(first, step) {}
    override public double Sum(int n) {
        return (first * (1-Math.Pow(step, n)))/(1-step);
    }
}