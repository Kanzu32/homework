abstract class Progression {
    protected double first;
    protected double step;

    public Progression (double first, double step) {
        this.first = first;
        this.step = step;
    }

    public virtual double Sum(int n) {return 0f;}
}