using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kr1
{
	class Person
	{
		string firstname;
		string lastname;
		string middlename;

		public Person(string lastname, string firstname, string middlename)
		{
			this.firstname = firstname;
			this.lastname = lastname;
			this.middlename = middlename;
		}

		public Person()
		{
			this.firstname = "-";
			this.lastname = "Unknown person";
			this.middlename = "-";
		}

		public override string ToString()
		{
			return $"{lastname} {firstname} {middlename}";
		}
	}
}
