class Person {
    string firstname;
    string lastname;
    string middlename;

    public Person(string lastname, string firstname, string middlename) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.middlename = middlename;
    }

    public Person() {
        this.firstname = "firstname";
        this.lastname = "lastname";
        this.middlename = "middlename";
    }

    public override string ToString() {
        return $"{lastname} {firstname} {middlename}";
    }
}

class Article {
    Person author;
    string title;
    double rating;
    public Article(Person author, string title, double rating) {
        this.author = author;
        this.title = title;
        this.rating = rating;
    }

    public Article() {
        this.author = new Person();
        this.title = "Unnamed book";
        this.rating = 0;
    }

    public override string ToString() {
        return $"{title}, {author} RAITING: {rating:f2}";
    }

    public Person Author {
        get {return author;}
    }
}

class Magazine {

}