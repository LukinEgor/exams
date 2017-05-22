using System;
using System.Collections.Generic;
using System.Xml.Serialization;
using System.IO;
using System.Linq;

namespace MyList {
  class Program {
     public static void Main(string[] args) {
       var list = new MyList();

       while(true) {
         Console.WriteLine("Input action:\n1 - Add item\n2 - Edit item\n3 - Delete item\n4 - Save\n5 - Load\n6 - Print\n7 - Exit\n");
         string input = Console.ReadLine();
         int number = 0;
         switch(input) {
           case "1":
             Student student = CreateStudent();
             list.Add(student);
             break;
           case "2":
             Console.WriteLine("Enter number student");
             number = Int32.Parse(Console.ReadLine());
             student = list.StudentList.Where(st => st.Number == number).First();
             list.Remove(student);
             Student newStudent = CreateStudent();
             list.Add(newStudent);
             break;
           case "3":
             Console.WriteLine("Enter number student");
             number = Int32.Parse(Console.ReadLine());
             student = list.StudentList.Where(st => st.Number == number).First();
             list.Remove(student);
             break;
           case "4":
             list.Serialize();
             break;
           case "5":
             MyList newList = list.Deserialize();
             list = newList;
             break;
           case "6":
             list.StudentList.ForEach(st => PrintStudent(st));
             break;
           case "7":
             return;
           default:
             break;
         }
       }
     }

     public static void PrintStudent(Student student) {
       Console.WriteLine("Student {0} - {1} {2} {3}, Group - {4}", student.Number, student.FirstName,
           student.SecondName, student.LastName, student.Group);
     }

     public static Student CreateStudent() {
       Student student = new Student();

       Console.WriteLine("Enter first name");
       student.FirstName = Console.ReadLine();

       Console.WriteLine("Enter second name");
       student.SecondName = Console.ReadLine();

       Console.WriteLine("Enter last name");
       student.LastName = Console.ReadLine();

       Console.WriteLine("Enter group name");
       student.Group = Console.ReadLine();

       Console.WriteLine("Enter number name");
       student.Number = Int32.Parse(Console.ReadLine());

       return student;
     }

  }

  public class MyList {
    public List<Student> StudentList { get; set; } = new List<Student>();

    public MyList() {
    }

    public void Add(Student student) {
      this.StudentList.Add(student);
    }

    public void Remove(Student student) {
      this.StudentList.Remove(student);
    }

    public void Serialize() {
      var xml = new XmlSerializer(typeof(MyList));

      using (FileStream fs = new FileStream("test.xml", FileMode.Create))
      {
        xml.Serialize(fs, this);
      }
    }

    public MyList Deserialize() {
      var xml = new XmlSerializer(typeof(MyList));
      MyList list = new MyList();

      using (FileStream fs = new FileStream("test.xml", FileMode.Open))
      {
        list = (MyList)xml.Deserialize(fs);
      }

      return list;
    }
  }

  public class Student {
    public int Number { get; set; }
    public string FirstName { get; set; }
    public string SecondName { get; set; }
    public string LastName { get; set; }
    public string Group { get; set; }
  }
}
