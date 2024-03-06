using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kr1
{
	class Person
	{
		public string Firstname { get; set; }
		public string Lastname { get; set; }
		public string Middlename { get; set; }

		public Person(string lastname, string firstname, string middlename)
		{
			Firstname = firstname;
			Lastname = lastname;
			Middlename = middlename;
		}

		public Person()
		{
			Firstname = "-";
			Lastname = "Unknown person";
			Middlename = "-";
		}

		public override string ToString()
		{
			return $"{Lastname} {Firstname} {Middlename}";
		}
	}
}
