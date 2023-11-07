enum DiskType {CD, DVD};

class Disk : Publication {
    protected DiskType diskType;
    public Disk(string name, double price, DiskType diskType) : base(name, price) {
        this.diskType = diskType;
    }

    public DiskType DiskType {
        get {
            return this.diskType;
        }
    }

    public override string ToString() {
        return $"{name}, {diskType}, {price}";
    }
}