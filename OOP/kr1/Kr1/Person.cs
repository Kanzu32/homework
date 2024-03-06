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

		public Person(string lastname, string firstname)
		{
			Firstname = firstname;
			Lastname = lastname;
		}

		public Person()
		{
			Firstname = "-";
			Lastname = "Unknown person";
		}

		public override string ToString()
		{
			return $"{Lastname} {Firstname}";
		}
	}
}
