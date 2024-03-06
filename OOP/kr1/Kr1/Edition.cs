using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kr1
{
	class Edition
	{
		protected string Title { get => _title; set => _title = value ?? throw new ArgumentNullException(nameof(value), "Cannot set to null"); }
		protected string _title;

		protected DateTime ReleaseDate { get => _releaseDate; set => _releaseDate = value; }
		protected DateTime _releaseDate;

		protected int Circulation
		{
			get
			{
				return _circulation;
			}
			set
			{
				ArgumentOutOfRangeException.ThrowIfNegative(value, "Circulation value must positive or zero.");
				_circulation = value;
			}
		}
		protected int _circulation;

		public Edition(string title, DateTime releaseDate, int circulation)
		{
			Title = title;
			ReleaseDate = releaseDate;
			Circulation = circulation;
		}

		public Edition()
		{
			Title = "Untitled edition";
			ReleaseDate = new DateTime();
			Circulation = 0;
		}

		virtual public object DeepCopy() => new Edition { Title = Title, ReleaseDate = ReleaseDate, Circulation = Circulation };

		public override bool Equals(object? obj)
		{
			return obj != null &&
			       obj is Edition other &&
				   other.Title == Title &&
				   other.ReleaseDate == ReleaseDate &&
				   other.Circulation == Circulation;
		}

		public static bool operator ==(Edition left, Edition right)
		{
			return left.Equals(right);
		}

		public static bool operator !=(Edition left, Edition right)
		{
			return !left.Equals(right);
		}

		public override int GetHashCode()
		{
			return HashCode.Combine(Title, ReleaseDate, Circulation);
		}

		public override string ToString()
		{
			return $"Edition: title {Title}, release date {ReleaseDate}, circulation {Circulation}";
		}
	}
}
