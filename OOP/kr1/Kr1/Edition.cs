using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kr1
{
	class Edition
	{
		private string name;
		private DateTime releaseDate;
		private int circulation;

		public Edition(string name, DateTime releaseDate, int circulation)
		{
			this.name = name;
			this.releaseDate = releaseDate;
			this.circulation = circulation;
		}

		public Edition()
		{
			this.name = "Unnamed edition";
			this.releaseDate = new DateTime();
			this.circulation = 0;
		}

		virtual public object DeepCopy()
		{
			// Копия !!!
			return this;
		}

		protected string Name { get => name; set => name = value; }
		protected DateTime ReleaseDate { get => releaseDate; set => releaseDate = value; }
		protected int Circulation { get => circulation;
			set
			{
				ArgumentOutOfRangeException.ThrowIfNegative(value, "Circulation value must be non-negative.");
				this.circulation = value;
			}
		}

		public override bool Equals(object? obj)
		{
			// проверка по значениям, ==, != !!!
			return base.Equals(obj);
		}

		public override int GetHashCode()
		{
			// !!!
			return base.GetHashCode();
		}

		public override string ToString()
		{	
			// все поля класса !!!
			return base.ToString();
		}
	}
}
