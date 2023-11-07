internal class Program
{
    private static void Main(string[] args)
    {
        	
        List<Publication> publications = new List<Publication>();
        while (true) {
            Console.WriteLine("p - publication, d - disk: ");
            var publicationType = Console.ReadLine();
            if (publicationType == "p" || publicationType == "P") {
                Console.WriteLine("Publication name: ");
                var name = Console.ReadLine();
                Console.WriteLine("Publication price: ");
                double price = Convert.ToDouble(Console.ReadLine());
                if (name != null) {
                    publications.Add(new Publication(name, price));
                } else {
                    Console.WriteLine("Wrong input, try again.");
                    continue;
                }


            } else if (publicationType == "d" || publicationType == "D") {
                Console.WriteLine("Disk name: ");
                var name = Console.ReadLine();
                Console.WriteLine("Disk type: ");
                var diskTypeString = Console.ReadLine();
                DiskType diskType;
                if (diskTypeString == "CD") {
                    diskType = DiskType.CD;
                } else if (diskTypeString == "DVD") {
                    diskType = DiskType.DVD;
                } else {
                    Console.WriteLine("Wrong input, try again.");
                    continue;
                }
                Console.WriteLine("Disk price: ");
                double price = Convert.ToDouble(Console.ReadLine());
                if (name != null) {
                    publications.Add(new Disk(name, price, diskType));
                } else {
                    Console.WriteLine("Wrong input, try again.");
                    continue;
                }
            } else {
                Console.WriteLine("Wrong input, try again.");
            }

            foreach (Publication publ in publications) {
                Console.WriteLine(publ);
            }
        }
    }
}